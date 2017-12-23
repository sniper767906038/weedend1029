#include <stdio.h>

int main(void)
{
	int arr[] = {2,3,4};
	int (*p)[3] = NULL;//数组指针
	int arr2[3][2] = {};
	//arr2--->&arr2[0]
	//arr2 + 1--->&arr2[1]
	//arr2--->int (*)[2]
	int (*q)[2] = arr2;

	p = &arr;

	printf("%p\n", arr);//int *--->sizeof(int)
	printf("%p\n", arr+1);

	printf("%p\n", &arr);//int (*)[3]--->sizeof(int)*3
	printf("%p\n", &arr+1);


	return 0;
}

