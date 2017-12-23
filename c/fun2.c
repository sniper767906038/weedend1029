/*
定义一个函数,求得斐波那契数列的第n项 
前两项为1 从第三项开始，每一项是前两项的和
1 1 2 3 5 8 13 21......
 */
#include <stdio.h>

int febnaci_n(int n);
int febnaci_nr(int n);
int sumn(int n);
int main(void)
{
	int ret;

	for (int i = 1; i <= 20; i++) {
		//ret = febnaci_n(i);
		ret = febnaci_nr(i);
		printf("%d ", ret);	
	}
	printf("\n");

	scanf("%d", &ret);
	printf("%d\n", sumn(ret));

	return 0;
}

/*
	n:第n项
    return value:第n项的值	
 */
int febnaci_n(int n)
{
	int b1, b2;
	int res;

	if (n <= 0)
		return -1;
	if (n == 1 || n == 2)	
		return 1;
	b1 = b2 = 1;
	for (int i = 3; i <= n; i++) {
		res = b1 + b2;			
		b2 = b1;
		b1 = res;
	}

	return res;
}

/*
 递归函数
 	1.找到递归终止条件
	2.递归点
 
 */
int febnaci_nr(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return febnaci_nr(n-1) + febnaci_nr(n-2);
}

/*
 	求一个整型数值的前ｎ项和
 */

int sumn(int n)
{
	if (n == 1)	
		return 1;
	return n + sumn(n-1);
}


