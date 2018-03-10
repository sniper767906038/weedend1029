#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	printf("hello\n");
	printf("pid:%d, ppid:%d\n", getpid(), getppid());

	/*
	while (1)
		;
	*/

	exit(0);
}

