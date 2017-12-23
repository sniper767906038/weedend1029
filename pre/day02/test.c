/*
 定义一下几个函数
 	1.比较两个整型数的大小
	2.求得给定整型数的阶乘
	3.求得斐波那契数列的第ｎ项 
		1 1 2 3 5 8
 */
#include <stdio.h>

int febnaci(int n);
int int_cmp(int num1, int num2);
long factor(int num);
int main(void)
{
	int n1, n2;
	int ret;

	printf("输入两个整型数: ");
	scanf("%d%d", &n1, &n2);

	if ((ret = int_cmp(n1, n2)) > 0) {
		printf("%d大于%d\n", n1, n2);
	} else if (ret < 0) {
		printf("%d小于%d\n", n1, n2);
	} else 
		printf("%d是等于%d\n", n1, n2);

	printf("输入待求得的整型数: ");
	scanf("%d", &n1);
	printf("%d的阶乘%ld\n", n1, factor(n1));

	for (int i = 1; i <= 20; i++) {
		printf("斐波那契数列的第%d项是%d\n", i, febnaci(i));
	}

	return 0;
}

/*
return:
	0  equal
	-1 less than
	1  more than
 */
int int_cmp(int num1, int num2)
{
	if (num1 > num2)
		return 1;
	else if (num1 < num2)
		return -1;
	else
		return 0;
}

long factor(int num)
{
	int res = 1;

	for (int i = 2; i <= num; i++) {
		res = res * i;	
	}

	return res;
}

int febnaci(int n)
{
	int pre1, pre2;
	int res;

	if (n == 1 || n == 2)
		return 1;
	pre1 = pre2 = 1;
	for (int i = 3; i <= n; i++) {
		res = pre1 + pre2;	
		pre2 = pre1;	
		pre1 = res;
	}
	
	return res;	
}

