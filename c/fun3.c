#include <stdio.h>

void test(int a, int b, int c);
int main(void)
{
	volatile int num = 1;
	//volatile修饰变量，防止编译优化

	//函数的传参是值传递的过程，并顺序是从右向左
	//c = --num;  b = num++; a = num;
	test(num, num++, --num);

	return 0;
}

void test(int a, int b, int c)
{
	printf("a:%d, b:%d, c:%d\n", a, b, c);
}

