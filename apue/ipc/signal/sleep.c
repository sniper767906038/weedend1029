#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	//if error

	if (pid == 0) {
		sleep(5);
		sleep(3);
		sleep(1);
		kill(getppid(), SIGKILL);	
		exit(0);
	}
	
	while (1) {
		write(1, "*", 1);	
		sleep(1);	
	}


	return 0;
}

