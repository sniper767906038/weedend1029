#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	int pfd[2];
	char buf[100] = {};
	pid_t pid;

	if (pipe(pfd) < 0) {
		perror("pipe()");
		exit(1);
	}

	pid = fork();
	if (pid < 0) {
		perror("fork()");
		close(pfd[0]);
		close(pfd[1]);
		exit(1);
	}

	if (pid == 0) {
		//关闭写端	
		close(pfd[1]);
		read(pfd[0], buf, 100);
		puts(buf);
		close(pfd[0]);	
		exit(0);
	}

	close(pfd[0]);
	write(pfd[1], "你好世界!!", strlen("你好世界!!")); //write
	close(pfd[1]);
	wait(NULL);

	exit(0);
}

