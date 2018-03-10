
/*
 模拟shell的工作模式
	./a.out
	[guolin@uplooking]$ ls -l

 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	pid_t pid;

	while (1) {
		printf("[uplooking] $ ");
		getline(&lineptr, &n, stdin);	
		if (!strcmp(lineptr, "exit\n"))
			break;
		pid = fork();
		if (pid < 0) {
			perror("fork()");
			exit(1);
		}
		if (pid == 0) {
			execl("/bin/sh", "sh", "-c", lineptr, NULL);
			perror("execl()");
			exit(1);
		}	
		wait(NULL);
	}		

	exit(0);
}

