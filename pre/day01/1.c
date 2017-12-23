#include <stdio.h>

int main(void)
{
	//char short int long (long long)
	//1     2     4   8
	//变量的定义
	int num;

	printf("hello world\n");//调用 --->声明

	scanf("%d", &num);
	if (num % 2 == 0) {
		printf("%d是一个偶数\n", num);	
	} else {
		printf("%d是一个基数\n", num);
	}


	return 0;
}

