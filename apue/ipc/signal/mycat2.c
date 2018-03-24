#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>

#define BUFSIZE 10

// 谁申请谁释放，谁打开谁关闭

static volatile int flag = 0; //没有权限　　

//令牌桶的三要素:令牌，速率，　上限
struct token_st {
	int token;		
	int cps;
	int burst;
};

struct token_st mytoken = {0, 10, 100};

static void alrm_handler(int s)
{
	alarm(1);
	mytoken.token += mytoken.cps;
	if (mytoken.token >= mytoken.burst)
		mytoken.token = mytoken.burst;
}

int main(int argc, char **argv)
{
	int fd;
	char buf[BUFSIZE] = {};
	int cnt, pos, already_w;

	if (argc < 2)
		return 1;
	
	signal(SIGALRM, alrm_handler);
	//产生SIGALRM
	alarm(1);

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

	/*
	 令牌桶模型
	 */
	while (1) {
		while (mytoken.token <= 0) {
			pause();//通知
		}
		mytoken.token -= mytoken.cps;

		while (1) {
			cnt = read(fd, buf, mytoken.cps);	
			if (cnt == 0)
				goto END;
			if (cnt < 0) {
				//排除假错	
				if (errno == EINTR)
					continue;
				else {
					perror("read()");
					goto ERROR1;
				}
			}
			break;
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
END:
	close(fd);

	return 0;
ERROR1:
	close(fd);
	exit(1);
}

