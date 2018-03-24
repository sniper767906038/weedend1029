#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void handler(int s)
{	
	int i = 0;
		
	while (i < 5) {
		fprintf(stdout, "  %d]%d  ", i, s);	
		fflush(NULL);
		sleep(1);
		i++;
	}
}

int main(void)
{
//	signal(SIGINT, handler);		
//	signal(SIGQUIT, handler);		
	struct sigaction act;

	act.sa_flags = 0;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	sigaction(SIGINT, &act, NULL);

	act.sa_flags = 0;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGINT);
	sigaction(SIGQUIT, &act, NULL);

	while (1) {
		write(1, "*", 1);
		sleep(1);
	}

	exit(0);
}

