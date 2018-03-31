#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#include "tbf.h"

//令牌桶数据类型
typedef struct {
	int token;
	int cps;
	int burst;
	pthread_mutex_t mut;
	pthread_cond_t cond;
}tbf_t;

static tbf_t *jobs[MAXTBF] = {};
static pthread_mutex_t jobmut = PTHREAD_MUTEX_INITIALIZER;//保证多线程同时操作jobs数组是互斥的
static pthread_t tid;
static pthread_once_t once = PTHREAD_ONCE_INIT; 
//保证制定的函数只能调用一次

static void *thr_job(void *s)
{
	while (1) {
		pthread_mutex_lock(&jobmut);
		for (int i = 0 ; i < MAXTBF; i++) {
			if (jobs[i] != NULL) {
				pthread_mutex_lock(&jobs[i]->mut);
				jobs[i]->token += jobs[i]->cps;
				if (jobs[i]->token > jobs[i]->burst) {
					jobs[i]->token = jobs[i]->burst;
				}
				pthread_cond_broadcast(&jobs[i]->cond);
				pthread_mutex_unlock(&jobs[i]->mut);
			}
		}
		pthread_mutex_unlock(&jobmut);
		sleep(1);
	}
}

static void module_load()
{
	int err;
	//管理所有令牌桶的线程　并发
	err = pthread_create(&tid, NULL, thr_job, NULL);	
	//if error;
	
}


static int getpos(void) 
{
	for (int i = 0; i < MAXTBF; i++)
		if (jobs[i] == NULL)
			return i;
	return -1;
}

int tbf_init(int cps, int burst)
{
	tbf_t *me = NULL;	
	int pos;

	pthread_once(&once, module_load);

	me = malloc(sizeof(tbf_t));
	if (NULL == me) {
		return -1;
	}
	memset(me, '\0', sizeof(tbf_t));

	me->cps = cps;
	me->burst = burst;
	pthread_mutex_init(&me->mut, NULL);
	pthread_cond_init(&me->cond, NULL);

	pthread_mutex_lock(&jobmut);
	pos = getpos();
	if (pos < 0) {
		//令牌桶个数已达上限
		pthread_mutex_unlock(&jobmut);
		free(me);
		return -1;
	}
	jobs[pos] = me;
	pthread_mutex_unlock(&jobmut);

	return pos;
}

int tbf_fetch(int tf, int n)
{
	int ret;

	if (tf < 0 || tf >= MAXTBF || n <= 0)
		return -1;
	pthread_mutex_lock(&jobs[tf]->mut);
	while (jobs[tf]->token == 0) {
		pthread_cond_wait(&jobs[tf]->cond, &jobs[tf]->mut);
	}
	if (jobs[tf]->token > n) {
		ret = n;	
		jobs[tf]->token -= n;
	} else {
		ret = jobs[tf]->token;
		jobs[tf]->token = 0;
	}
	pthread_mutex_unlock(&jobs[tf]->mut);

	return ret;
}

int tbf_return(int tf, int n)
{
	if (tf < 0 || tf >= MAXTBF || n <= 0)
		return -1;
	pthread_mutex_lock(&jobs[tf]->mut);
	jobs[tf]->token += n;
	if (jobs[tf]->token > jobs[tf]->burst)
		jobs[tf]->token = jobs[tf]->burst;
	pthread_cond_broadcast(&jobs[tf]->cond);
	pthread_mutex_unlock(&jobs[tf]->mut);

	return 0;
}

void tbf_destroy(int tf)
{
	pthread_mutex_lock(&jobmut);
	free(jobs[tf]);
	jobs[tf] = NULL;
	pthread_mutex_unlock(&jobmut);
}


