#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM 20

int main(void)
{
	int arr[NUM] = {};

	//随机数的产生
	srand(getpid());

	//赋值
	for (int i = 0; i < NUM; i++) {
		arr[i] = rand() % 100;	
	}

	//遍历
	for (int i = 0; i < NUM; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");

	return 0;
}

