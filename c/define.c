#include <stdio.h>

#define NUM 10

//带参数的宏，宏参数要加括号
#define SQUARE(x)	(x)*(x)

#define SWAP(x, y) \
		do {\
			typeof(x) tmp;\
			tmp = (x);\
			(x) = (y);\
			(y) = tmp;\
		}while(0)
//typeof(x) 获得x的类型

int main(void)
{
	int sum = 0;	
	int num1 = 10, num2 = 100;

	for (int i = 1; i < NUM; i++) {
		sum += i;	
	}
	printf("%d\n", sum);

	sum = 5;		

	printf("%d\n", SQUARE(sum+1));

	SWAP(num1, num2);
	printf("num1:%d, num2:%d\n", num1, num2);

	printf("%d %s\n", __LINE__, __FUNCTION__);

	return 0;
}

