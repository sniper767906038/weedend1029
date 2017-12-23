#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void test(int s)
{
	printf("this is a test s:%d\n", s);
}

void hand(int unused)
{
	printf("这次清楚了吗?\n");
}

int main(void)
{
#if 0
	void (*p)(int);//函数指针(参数类型，返回值类型)

	p = test;

	p(2);
	test(1);
	
	printf("%p\n", test);
#endif
	//signal(2/*Ctrl c*/, test);
	signal(2/*Ctrl c*/, hand);
	/*
	   signal(int signum, void (*handler)(int));
		handler(signum);	 
	 */

	while (1) {
		printf("hello\n");	
		sleep(1);	
	}

	return 0;
}

