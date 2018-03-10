#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void handler1(int s)
{
	int i = 0;
	for (; i < 5; i++) {
		fprintf(stdout, "%d", i);
		fflush(NULL);
		sleep(1);
	}
}

int main(void)
{
	signal(SIGINT, handler1);

	while (1) {
		write(1, "*", 1);	
		sleep(1);	
	}	

	exit(0);
}

