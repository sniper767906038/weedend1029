#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int mydaemon(void)
{
	pid_t pid;
	int fd;

	pid = fork();
	if (pid < 0) {
		syslog(LOG_ALERT, "fork():%s", strerror(errno));
		exit(1);
	}
	if (pid > 0) {
		//parent
		_exit(0);
	}

	//child--->setid()
	if (setsid() < 0) {
		//perror("setsid()");
		syslog(LOG_ALERT, "setsid():%s", strerror(errno));
		return -1;
	}
	//success PID == PGID == PSID no tty

	//redirect 0, 1, 2 
	fd = open("/dev/null", O_WRONLY);		
	if (fd < 0) {
		syslog(LOG_ERR, "setsid():%s", strerror(errno));
		return -1;
	}
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	if (fd > 2)
		close(fd);

	//change directory
	chdir("/");

	//
	umask(0);

	return 0;
}

int main(void)
{
	int i;	
	FILE *fp;

	/*
	 	LOG_PID:日志消息包含pid
		LOG_PERROR:向stderr输出
	 */
	openlog(NULL, LOG_PID | LOG_PERROR, LOG_DAEMON);

#if 0
	//become daemon
	if (mydaemon() < 0) {
		fprintf(stderr, "mydaemon failed");
		exit(1);
	}
#endif
#if 1
	if (daemon(0, 1) < 0) {
		//perror("daemon()");
		syslog(LOG_ERR, "daemon():%s", strerror(errno));
		exit(1);
	}
#endif
	
	//fp = fopen("/srv/ftp/download/weekend1029/apue/process/test", "w");
	fp = fopen("./test", "w");
	if (NULL == fp) {
		//perror("fopen()");
		syslog(LOG_ERR, "fopen():%s", strerror(errno));
		exit(1);
	}

	i = 0;
	while (1) {
		fprintf(fp, "%d", i);		
		fflush(NULL);
		sleep(1);
		i ++;
	}

	closelog();

	exit(0);
}

