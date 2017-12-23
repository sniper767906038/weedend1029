/*
二维数组 
	表达形式 
 */
#include <stdio.h>

int main(void)
{
	int arr[16] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0};
	/*arr2是一个由4个一维数组组成的二维数组
	  arr2数组的成员是一个一维数组
	 */
	int arr2[4][4] = {
		{0,0,0,0},
		{0,1,0,0},
		{0,1,0,0},
		{0,1,1,0}
	};

	printf("arr2:%p\n", arr2);
	printf("arr2+1:%p\n", arr2+1);

	printf("%d\n", arr2[0][5]);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", arr2[i][j]);	
		}
		printf("\n");
	}

	for (int i = 0; i < 16; i++)
		printf("%d ", arr2[0][i]);
	printf("\n");


	return 0;
}

