#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

static void *thr_fun(void *p)
{
	printf("the new thread is running\n");
	
//	sleep(10);

	//return (void *)0;
	pthread_exit((void *)0);
}


int main(void)
{
	pthread_t tid;
	int err;
	int *retval = NULL;

	printf("main will create a new thread\n");
	err = pthread_create(&tid, NULL, thr_fun, NULL);
	if (err) {
		//失败
		fprintf(stderr, "pthread_create():%s\n", strerror(err));
		exit(1);
	}
	//将新线程join回 pthread_join(tid, NULL)不关系线程终止状态
	pthread_join(tid, (void **)&retval);
	printf("the new thread terminaled with %d\n", (int)retval);

	printf("main finished\n");

	//sleep(10);

	exit(0);
}


