#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);

static void sighandler1(int s)
{
	write(1, "!", 1);
}	

int main(void)
{
	sighandler_t back;	
	int i;

	//为信号注册行为
	back = signal(SIGINT, SIG_IGN);
	if (back == SIG_ERR) {
		perror("signal()");
		exit(1);
	}
	
	i = 0;
	while (1) {
		write(1, "*", 1);	
		sleep(1);	
		if (i == 5) {
			signal(SIGINT, sighandler1);
		}
		else if (i == 120) {
			signal(SIGINT, SIG_DFL);
		}
		i++;
	}

	exit(0);
}

