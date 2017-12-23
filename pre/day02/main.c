#include <stdio.h>

/*
	1.读入一个整型数(scanf("%d", &n)),求得其前ｎ项和
	2.读入一个整型数,判断其是否为回文整型 
	12321    111
 */

int main(void)
{
	int num, save;
	int sum = 0;

	/*
	for (int i = 0; i < 10; i ++) {
		printf("* ");		
	}
	printf("\n");
	*/
	printf("请输入一个整型数: ");
	scanf("%d", &num);

#if 0
	//遍历1到num之间的所有的数值，将其累加到sum
	for (int i = 1; i <= num; i++) {
		sum = sum + i;	
		//sum += i;
	}
	printf("%d的前n项和为%d\n", num, sum);
#endif
	save = num;
	//num == 123
	for (; num > 0; num = num / 10) {
		sum = sum*10 + num % 10;	
	}	
	if (sum == save)
		printf("%d 是一个回文整型\n", save);

	return 0;
}

