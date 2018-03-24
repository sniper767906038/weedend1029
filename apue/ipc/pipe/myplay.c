#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

//argv[1] --->music
//argv[2] ---->播放器
int main(int argc, char **argv)
{
	int fd;
	int pfd[2] = {};
	pid_t pid;
	char buf[1024] = {};
	int cnt;

	if (argc < 3)
		exit(1);
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("open()");	
		exit(1);
	}

	//建管道
	if (pipe(pfd) < 0) {
		perror("pipe()");	
		exit(1);
	}

	//建进程
	pid = fork();
	if (pid < 0) {
		perror("fork()");
		goto FORK_ERROR;
	}

	if (pid == 0) {
		//运行播放器
		close(pfd[1]);
		dup2(pfd[0], 0);
		execl("/bin/sh", "sh", "-c", argv[2], NULL);
		perror("execl()");	
		exit(1);
	}

	close(pfd[0]);
	//parent---->open()---->read()--->write_ pipe
	while (1) {
		cnt = read(fd, buf, 1024);
		if (0 == cnt) 
			break;
		if (cnt < 0) {
			if (errno == EINTR)
				continue;
			perror("read()");
			goto READ_ERROR;
		}
		write(pfd[1], buf, cnt);	
		//sleep(1);
	}		

	close(pfd[1]);
	close(fd);

	exit(0);
FORK_ERROR:
	close(pfd[0]);
	close(pfd[1]);
	exit(1);
READ_ERROR:
	close(pfd[1]);
	close(fd);
	exit(1);
}


