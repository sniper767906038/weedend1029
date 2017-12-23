#include <stdio.h>

int main(void)
{
	char str[] = "hello world";//12
	char *p = "hello world";//指针变量p存储的是字符串常量"hello world"的首地址

	str[0] = 'w';
	//p[0] = 'w';

	printf("%s\n", str);
	printf("%s\n", p);


	return 0;
}

