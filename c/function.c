#if 0
	函数
		定义
			函数名
				标识符,见名思意
			形参列表
				存储已知值,回填结果值	
			返回值类型
				得到的结果值	
		声明
			调用之前，要对调用的函数声明
			函数名
			参数类型
			返回值类型
		调用
			函数名(实参);
#endif
#include <stdio.h>

//函数的声明
int isprimer(int n);
int main(void)
{
	int number;

	scanf("%d", &number);

	//调用	
	if (isprimer(number)) {
		printf("%d is a primer\n", number);
	} else {
		printf("%d is not a primer\n", number);
	}

	return 0;
}

/*
   函数的定义
 	function:
		实现判断给定整型数值是否为质数
	return value:
		0	no
		1	yes
 */
int isprimer(int n)
{
	int flag = 1;

	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0) {
			flag = 0;
			break;
		}
	}

	return flag;
}

