/*
	1.随机产生一个由20个整型数组成的数组 
	求得数组中的最大最小值
	将数组从小到大排序 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM 20

int main(void)
{
	int arr[NUM] = {};
	int max, min;

	srand(getpid());

	//赋值
	for (int i = 0; i < NUM; i++) {
		arr[i] = rand() % 100;	
		printf("%d ", arr[i]);
	}
	printf("\n");

	//求得最大最小值
	max = min = arr[0];
	for (int i = 1; i < NUM; i++) {
		max = max < arr[i] ? arr[i] : max;	
		min = min > arr[i] ? arr[i] : min;
	}
	printf("max:%d, min:%d\n", max, min);

	//冒泡排序
	for (int i = 0; i < NUM-1; i++) {
		for (int j = 0; j < NUM-1-i; j++) {
			if (arr[j] > arr[j+1]) {
				arr[j] = arr[j] ^ arr[j+1];	
				arr[j+1] = arr[j] ^ arr[j+1];	
				arr[j] = arr[j] ^ arr[j+1];	
			}
		}	
	}

	//遍历
	for (int i = 0; i < NUM; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");

	return 0;
}


