#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static jmp_buf env;

/*
 求得两个整型数的商
 */
int div2num(int m, int n)
{
	if (n == 0)	
		//重新输入ｎ的值，并调用此函数 ---->跨函数 goto不能跨函数
		longjmp(env, 2);
	else
		return m / n;
}

int main(void)
{
	int n1, n2;
	int res;
	int ret;

	ret = setjmp(env);
	if (ret == 0) {
		printf("请输入两个整型数\n");
	} else {
		//longjmp()--->error
		printf("ret : %d\n", ret);
		printf("请重新输入\n");
	}
	scanf("%d%d", &n1, &n2);

	res = div2num(n1, n2);

	printf("res:%d\n", res);

	exit(0);
}
