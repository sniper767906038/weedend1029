#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void handler(int s)
{
	write(1, "!", 1);
}

int main(void)
{
	int i, j;
	sigset_t set, oldset;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGQUIT);

	signal(SIGINT, handler);
	signal(SIGQUIT, handler);


	for (j = 0; j < 10; j++) {
		//阻塞2 ＆ 3信号
		sigprocmask(SIG_BLOCK, &set, &oldset);
		for (i = 0; i < 10; i++) {
			write(1, "*", 1);
			sleep(1);
		}
		printf("\n");
		sigprocmask(SIG_SETMASK, &oldset, NULL);
	}


	exit(0);
}

