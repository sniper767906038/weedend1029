#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/time.h>

#include "tbf.h"

#define BUFSIZE 10
#define CPS		10
#define BURST	100

int main(int argc, char **argv)
{
	int fd;
	char buf[BUFSIZE] = {};
	int cnt, pos, already_w;
	int tf;
	int n;

	if (argc < 2)
		return 1;
	
	//初始化
	tf = tbf_init(CPS, BURST);
	//if error

	while (1) {
		fd = open(argv[1], O_RDONLY | O_CREAT, 0666);
		if (fd < 0) {
			//排除假错情况
			if (errno == EINTR)
				continue;
			else {
				perror("open()");
				exit(1);
			}
		}
		break;
	}

	while (1) {
		//要权限
		n = tbf_fetch(tf, CPS);
		cnt = read(fd, buf, n);	
		if (cnt == 0)
			break;
		if (cnt < 0) {
			//排除假错	
			if (errno == EINTR)
				continue;
			else {
				perror("read()");
				goto ERROR1;
			}
		}
		if (n > cnt) {
			//有未消耗的token
			tbf_return(tf, n-cnt);
		}


		//一定将代写入的cnt字节，全部写入
		pos = 0;
		while (1) {
			already_w = write(1, buf+pos, cnt);	
			if (already_w < 0) {
				if (errno == EINTR)
					continue;
				else {
					perror("write()");
					goto ERROR1;
				}
			}
			if (already_w < cnt) {
				cnt -= already_w;
				pos += already_w;
			} else {
				break;
			}
		}
	}

	tbf_destroy(tf);
	close(fd);

	return 0;
ERROR1:
	close(fd);
	exit(1);
}

