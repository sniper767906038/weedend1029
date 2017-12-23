#include <stdio.h>

/*
 	for (exp1; exp2; exp3) {
		statement1;	
		statement2;	
	}

	while (exp2) {
		statement1;	
		statement2;	
		...
	}

	死循环
	for (; 1;) 
		;
	while (1) {
		;	
	}

冗错
	do {
	
	} while();
 
	goto--->无条件跳转

	continue
	break
 
	1.输入一个整型数,得到其倒叙数
		1234   4321
	2.输入两个整型数(num1, num2)
	输出两个数中较小到较大之间的所有的数


 */

int main(void)
{
	int num, num2;	
	int i, j;

	do {
		printf("input two numbers please\n");
		scanf("%d %d", &num, &num2);
	} while (num < 0 || num2 < 0);

	if (num < num2) {
		num = num ^ num2;
		num2 = num ^ num2;
		num = num ^ num2;	
	}

	//取出所有带计算的数值
	for (j = num2; j <= num; j ++) {
		if (j == 2)
			printf("%d 是一个质数\n", j);
		//去除偶数
		if (j % 2 == 0)
			continue;//结束本次循环 继续下一次循环

		//是否为质数
		for (i = 2; i < j; i++) {
			if (!(j % i))	
				break;//结束循环
			if (i == 50) 
				goto END;//只能在函数内跳转
		}

		if (i == j) {
			printf("%d 是一个质数\n", j);	
		}
	}
END:
	printf("this is a test\n");

#if 0
	i = 2;
	while (i < num) {
		if (num % i == 0)	
			break;
		i++;
	}
#endif		

#if 0
	int number;
	int res;

	printf("input a number:");
	scanf("%d", &number);

	res = 0;	
	
	while (number > 0) {
		res = res * 10 + number % 10;
		number /= 10;
	}

	printf("倒叙数:%d\n", res);
#endif

#if 0
	int n1, n2;	
	int max, min;
	
	scanf("%d %d", &n1, &n2);

	max = n1 > n2 ? n1 : n2;
	min = n1 < n2 ? n1 : n2;

	for (int i = min+1; i < max; i++) {
		printf("%d ", i);	
	}
	printf("\n");
#endif

	return 0;
}

