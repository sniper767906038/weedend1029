
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

/*
	多线程并发筛质数:100~300 
 
 */

static int is_primer(int n)
{
	for (int i = 2; i <= n / 2+1; i++) {
		if (n % i == 0)	
			return 0;
	}
	return 1;
}

static void *thr_job(void *n)
{
	sleep(1);
	//n是存储任务变量的地址	
	int m = (int)n;
	
	if (is_primer(m))
		printf("%d是一个质数\n", m);

	pthread_exit((void *)0);
}

int main(void)
{
	pthread_t tids[201] = {};
	int err;

	for (int i = 100; i <= 300; i++) {
		err = pthread_create(tids+i-100, NULL, thr_job, (void *)i);
		if (err) {
			fprintf(stderr, "pthread_create():%s\n", strerror(err));
			exit(1);
		}
	}

	for (int i = 0; i < 201; i++) {
		pthread_join(tids[i], NULL);	
	}

	exit(0);
}


