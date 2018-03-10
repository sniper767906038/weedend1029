#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//./a.out ls -l
int main(int argc, char *argv[])
{
	pid_t pid;
	char *args[] = {"cp", "/etc/passwd", ".", NULL};

	printf("i am the calling process\n");

	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}
	if (pid == 0) {
		//child--->"ls -l"
		printf("pid:%d\n", getpid());
		//ls进程替换子进程
		//execl("/bin/ls", "ls", "-l", "-i", NULL);
		//execlp("ls", "ls", "-l", "-i", NULL);//可执行文件在默认路径
		//execv("/bin/cp", argv+1);
		//execvp("ls", argv+1);

		/****************/
		execl("/bin/sh", "sh", "-c", argv[1], NULL);

		perror("execl()");
		exit(1);
	}		

	wait(NULL);
	printf("child back home\n");

	exit(0);
}

