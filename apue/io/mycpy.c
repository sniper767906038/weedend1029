#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
	int rfd, wfd;
	char buf[32] = {};
	int cnt;

	if (argc < 3)
		return 1;

	/*
	 	errno
	 */

	rfd = open(argv[1], O_RDONLY);
	//if error
	if (rfd < 0) {
		//perror("open()");//open(): error message
		fprintf(stderr, "******open():%s******\n", strerror(errno));
		return 1;	
	}

	wfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (wfd < 0) {
		//perror("open()");
		fprintf(stderr, "open():%s\n", strerror(errno));
		goto ERROR1;
	}

	//read--->rfd,  write--->wfd
	while (1) {
		cnt = read(rfd, buf, 32);		
		if (cnt == 0)
			break;
		else if (cnt < 0) {
			//error
			perror("read()");
			goto ERROR2;
		} else {
			write(wfd, buf, cnt);	
		}
	}

	close(rfd);
	close(wfd);

	return 0;
ERROR2:
	close(wfd);
ERROR1:
	close(rfd);
	return 1;
}

