#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
	子进程打印"hello"
   	等待父进程打印完"world"	
	子进程在继续打印输出"good afternoon"

	尽量大范围使用信号，如果需要则一定单向发送
 
 */

static void handler(int s)
{

}

int main(void)
{
	pid_t pid;

	signal(SIGINT, handler);

	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}

	if (pid == 0) {
		printf("hello\n");
		kill(getppid(), SIGINT);
		printf("good afternoon\n");
		exit(0);
	}
	
	pause();
	printf("world\n");
	wait(NULL);

	exit(0);
}

