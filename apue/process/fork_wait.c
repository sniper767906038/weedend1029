#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

static int glob = 10;

int main(void)
{
	pid_t pid;
	int status;
	int var = 100;

	printf("[%d][%s] is running", getpid(), __FUNCTION__);
	//创建子进程
	//在创建新的进程之前如果有标准ｉｏ操作，要刷新缓存区
	fflush(NULL);
	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(EXIT_FAILURE);
	}
	//成功了---->两个进程了
	if (pid > 0) {
		//parent
		printf("parent pid:%d, ppid:%d\n", getpid(), getppid());
	} 

	else if (pid == 0) {
		//子进程
//		sleep(1);
		printf("child pid:%d, ppid:%d\n", getpid(), getppid());
		glob = 20;
		var = 200;
		printf("[%d]glob:%d, var:%d\n", getpid(), glob, var);
		exit(0);
	}

	printf("the child [%d] was terminated\n", wait(&status));

	printf("the exit status %d\n", WEXITSTATUS(status));

	printf("[%d]glob:%d, var:%d\n", getpid(), glob, var);

	printf("good bye\n");


	exit(EXIT_SUCCESS);
}

