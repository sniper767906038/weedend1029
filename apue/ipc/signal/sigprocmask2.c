#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void handler(int s)
{	
	int i = 0;
	sigset_t set, old;

	sigemptyset(&set);
	sigaddset(&set, 5-s);
		
	sigprocmask(SIG_BLOCK, &set, &old);
	while (i < 5) {
		fprintf(stdout, "[%d] %d", i, s);	
		fflush(NULL);
		sleep(1);
		i++;
	}
	sigprocmask(SIG_SETMASK, &old, NULL);
}

int main(void)
{
	signal(SIGINT, handler);		
	signal(SIGQUIT, handler);		

	while (1) {
		write(1, "*", 1);
		sleep(1);
	}

	exit(0);
}

