/*
指针：
	变量:存储地址的变量
	定义:
		类型取决与存储的地址类型	
	字节个数
		64os
		8byte
	步长:
		取决与地址类型
		char *p; p+1--->1byte
		int *p; p+1--->4byte
 */

#include <stdio.h>

int main(void)
{
	int val = 10;
	int num = 100;
	char ch;

	int *p = &val;//int *类型 p变量名

	printf("sizeof(int *):%ld\n", sizeof(int *));
	printf("*p:%d\n", *p);

	p = &num;
	printf("*p:%d\n", *p);

	ch = 'a';
	char *q = &ch;
	printf("sizeof(q):%ld\n", sizeof(q));
	printf("q:%p, q+1:%p\n", q, q+1);


	return 0;
}




