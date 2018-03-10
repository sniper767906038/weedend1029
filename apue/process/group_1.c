#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("pid:%d, pgid:%d, sid:%d\n", getpid(), getpgid(0), getsid(0));

	sleep(120);

	exit(0);
}

