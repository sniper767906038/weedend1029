#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}

	if (pid == 0) {
		//child
	/*
		printf("[child]pid:%d, pgid:%d\n", getpid(), getpgrp());
		exit(0);
	*/
		setpgid(getpid(), getpid());
		execl("./group_1", "./group_1", NULL);
		perror("execl()");
		exit(1);
	}

	printf("[parent]pid:%d, pgid:%d sid:%d\n", getpid(), getpgrp(), getsid(0));
	wait(NULL);

	exit(0);
}


