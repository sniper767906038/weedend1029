#include <stdio.h>
/*
 数组:
 	相同类型元素的集合
	存储在同一数组的多个元素地址是连续的
	
	定义:
		type name[element];
 */

int main(void)
{
	//定义
	int arr[5];	
	//arr数组的首地址 int *
	int num = 100;
	//数组的初始化
	int arr2[3] = {1, 2, 3};
	int arr3[] = {1, 2, 3};
	
#if 0
	//int类型的变量的地址类型是int *
	//int *　+1 --->sizeof(int)
	printf("num:%d\n", num);
	printf("num + 1:%d\n", num + 1);
	printf("&num:%p\n", &num);
	printf("&num + 1:%p\n", &num + 1);
#endif
	//成员赋值
	*arr = 100;

	//数组的遍历
	for (int i = 0; i < 5; i++) {
		//printf("%d\n", *(arr+i));	
		printf("%d\n", /*arr[i]*/i[arr]);
	}


	return 0;
}

