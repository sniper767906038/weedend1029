#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define START 100
#define END	  300
#define THRNR 4

//静态线程池
static int job = 0; //job == 0任务未分配　　job == -1所有任务已分配完成,
//job > 0任务待计算   解决多线程对此任务的竞争，使用互斥量
/*
 互斥量使用按照以下步骤:
 	初始化 pthread_mutex_init()    --->互斥量-->unlock
	加锁/抢锁 pthread_mutex_lock()                 locked
	解锁   pthread_mutex_unlock()               unlocked
	销毁   pthread_mutex_destroy()              
 */
static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

static int is_primer(int n)
{
	for (int i = 2; i <= n / 2+1; i++) {
		if (n % i == 0)	
			return 0;
	}
	return 1;
}

static void *thr_job(void *s)
{
	int myjob;

	while (1) {
		//抢锁-->成功--->拿到job值 job = 0 解锁 计算	
		//----->失败--->阻塞
		pthread_mutex_lock(&mut);	
		while (job == 0) {
			pthread_mutex_unlock(&mut);
			sched_yield();//出让调度器(调度队尾排队)
			pthread_mutex_lock(&mut);	
		}
		if (job == -1) {
			pthread_mutex_unlock(&mut);
			break;
		}

		myjob = job;	
		job = 0;
		pthread_mutex_unlock(&mut);
		
		if (is_primer(myjob)) {
			printf("%d是一个质数\n", myjob);
		}
	}

	pthread_exit((void *)0);
}

int main(void)
{
	pthread_t tids[THRNR] = {};
	int err;

	for (int i = 0; i < THRNR; i++) {
		err = pthread_create(tids+i, NULL, thr_job, NULL);	
		if (err) {
			fprintf(stderr, "pthread_create():%s\n", strerror(err));
			exit(1);
		}
	}	

	//为任务线程分配任务
	for (int j = START; j <= END; j++) {
		pthread_mutex_lock(&mut);
		while (job > 0) {
			//有未完成的任务
			pthread_mutex_unlock(&mut);
			sched_yield();
			pthread_mutex_lock(&mut);
		}
		job = j;
		pthread_mutex_unlock(&mut);
	}

	//所有任务发放完成
	pthread_mutex_lock(&mut);	
	while (job != 0) {
		pthread_mutex_unlock(&mut);
		sched_yield();
		pthread_mutex_lock(&mut);
	}
	job = -1;
	pthread_mutex_unlock(&mut);

	for (int i = 0; i < THRNR; i++) {
		pthread_join(tids[i], NULL);
	}

	pthread_mutex_destroy(&mut);

	exit(0);
}






