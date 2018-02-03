#include <stdio.h>
#include <unistd.h>

int main(void)
{

	printf("g");//stdio
	write(1, "b", 1);//sysio

	printf("i");
	write(1, "o", 1);

	printf("r");
	write(1, "y", 1);

	printf("l");
	write(1, "s", 1);

	fflush(NULL);//刷新所有打开的输出流
	//printf("\n");

	while (1);

	return 0;
}

