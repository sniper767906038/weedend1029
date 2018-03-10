#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 猜想
	while (1) {
		printf("[dengchao@localhost...]$");
		//ls -l
		fork();	
		//给子进程收尸
	}
*/

int main(void)
{
	pid_t pid;

	printf("[%s] is running\n", __FUNCTION__);
	//创建子进程
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
	}

	printf("good bye\n");


	exit(EXIT_SUCCESS);
}

