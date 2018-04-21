#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define  FILE1 "/dev/tty10"
#define  FILE2 "/dev/tty11"

#define	 BUFSIZE	1024	

enum {
	STATE_R,
	STATE_W,
	STATE_E,
	STATE_T
};

//　抽象两个状态机 tty12--->r_FILE1 w_FILE2   tty21--->r_FILE2 w_FILE1
struct fsm_st {
	int rfd, wfd;
	char buf[BUFSIZE];
	int rcnt;
	int state;
	char errmsg[BUFSIZE];
	int pos; //存储写入的自己个数
};

//状态机推动
static void drive_fsm(struct fsm_st *fsm)
{
	int wcnt;

	switch (fsm->state) {
		case STATE_R:
			fsm->rcnt = read(fsm->rfd, fsm->buf, BUFSIZE);	
			if (fsm->rcnt < 0) {
				//是否假错
				if (errno != EAGAIN) {
					fsm->state = STATE_E;	
					snprintf(fsm->errmsg, BUFSIZE, "read():%s", strerror(errno));
				}
			} else if (fsm->rcnt == 0) {
				fsm->state = STATE_T;
			} else {
				//读到数据
				fsm->state = STATE_W;
				fsm->pos = 0;
			}

			break;
		case STATE_W:
			wcnt = write(fsm->wfd, fsm->buf + fsm->pos, fsm->rcnt);
			if (wcnt < 0) {
				if (errno != EAGAIN) {
					fsm->state = STATE_E;
					snprintf(fsm->errmsg, BUFSIZE, "write():%s", strerror(errno));
				}
			} else {
				fsm->pos += wcnt;	
				if (wcnt < fsm->rcnt) {
					//写的不完整
					fsm->rcnt -= wcnt;
				} else {
					fsm->state = STATE_R;
				}
			}

			break;
		case STATE_E:
			fprintf(stderr, "%s\n", fsm->errmsg);
			fsm->state = STATE_T;
			break;
		case STATE_T:
			break;
	}	

}

//　构建状态机
static void create_fsm(int fd1, int fd2)
{
	struct fsm_st fd12, fd21;
	int fd_save1, fd_save2;	

	//确保fd1 和　fd2是非阻塞
	fd_save1 = fcntl(fd1, F_GETFL);
	fcntl(fd1, F_SETFL, fd_save1 | O_NONBLOCK);
	fd_save2 = fcntl(fd2, F_GETFL);
	fcntl(fd2, F_SETFL, fd_save2 | O_NONBLOCK);

	fd12.rfd = fd1;
	fd12.wfd = fd2;
	fd12.state = STATE_R;

	fd21.rfd = fd2;
	fd21.wfd = fd1;
	fd21.state = STATE_R;
	
	while (fd12.state != STATE_T && fd21.state != STATE_T) {
		drive_fsm(&fd12);			
		drive_fsm(&fd21);			
	}
	fcntl(fd1, F_SETFL, fd_save1);
	fcntl(fd2, F_SETFL, fd_save2);
}


int main(void)
{
	int fd1, fd2;	

	fd1 = open(FILE1, O_RDWR);
	//if error

	fd2 = open(FILE2, O_RDWR | O_NONBLOCK);

	write(fd1, "[i am tty10]", strlen("[i am tty10]"));
	write(fd2, "[i am tty11]", strlen("[i am tty11]"));

	create_fsm(fd1, fd2);

	exit(0);
}



