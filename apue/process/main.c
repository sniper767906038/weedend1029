#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void atexit_1(void)
{
	printf("%s was called\n", __FUNCTION__);
}

void atexit_2(void)
{
	printf("%s was called\n", __FUNCTION__);
}

void atexit_3(void)
{
	printf("%s was called\n", __FUNCTION__);
}

void getarg(char **argv)
{
	int i = 0;

	while (argv[i] != NULL) {
		printf("%s ", argv[i++]);	
	}

	//return ;
	//exit(0);
	_exit(0); //_Exit(0)

}

int main(int argc, char **argv)
{
	//注册终止处理程序
	atexit(atexit_1);
	atexit(atexit_2);
	atexit(atexit_3);

	getarg(argv);

	printf("getarg....back...\n");

	//return 0;
	exit(EXIT_SUCCESS);//exit(0)
}

