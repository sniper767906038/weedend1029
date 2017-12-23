#include <stdio.h>

/*
行数从终端读入
*
* *
* * *
* * * *

输出的*的个数和行数 从终端读入
* * * *
  * * * *
    * * * *
      * * * *

 
 */

int main(void)
{
	int n;

#if 0
	for (int j = 0; j < 10; j++) { 
		for (int i = 0; i < 10; i++) {
			printf("* ");	
		}
		printf("\n");
	}
#endif

	printf("输入你想输入的行数: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("* ");	
		}
		printf("\n");	
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < i; j ++ ){
			printf("  ");	
		}	
		for (int k = 0; k < n; k++) {
			printf("* ");	
		}	
		printf("\n");
	}
	

	return 0;
}

