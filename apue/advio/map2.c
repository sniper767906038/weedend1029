#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFSIZE 1024

int main(void)
{
	pid_t pid;
	char *p = NULL;

	//父子进程共享内存
	p = mmap(NULL, BUFSIZE, PROT_READ | PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, \
			-1, 0);
	
	pid = fork();
	if (pid < 0) {
		perror("fork()");
		goto ERROR1;
	}
	if (pid == 0) {
		//child
		memcpy(p, "hello world", 11);
		exit(1);
	}
	wait(NULL);
	puts(p);
	munmap(p, BUFSIZE);

	exit(0);
ERROR1:
	munmap(p, BUFSIZE);
	exit(1);
}

