#include <stdio.h>

int main(void)
{
	volatile int num = 10;

	printf("hello everyone! %d %d %d\n", num, num--, ++num);
	// c = ++num, b = num --, a = num;

	return 0;
}

