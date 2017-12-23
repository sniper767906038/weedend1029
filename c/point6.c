#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*cmp_t)(const void *data1, const void *data2);

void sort_arr(void *arr, int nmemb, int size, cmp_t cmp);

static int int_cmp(const void *data1, const void *data2)
{
	int *d1 = (int *)data1;
	int *d2 = (int *)data2;

	return *d2-*d1;
}

static int str_cmp(const void *data1, const void *data2)
{
	char **d1 = (char **)data1;
	char **d2 = (char **)data2;

	//return strcmp(*d1, *d2);
	return strcmp(*d2, *d1);
}

int main(int argc, char **argv)
{
	int arr[] = {3,2,1,6,7,9,8,4,7};

	sort_arr(arr, sizeof(arr) / sizeof(*arr), sizeof(int), int_cmp);

	for (int i = 0; i <  sizeof(arr) / sizeof(*arr); i++)
		printf("%d ", arr[i]);
	printf("\n");

	//将命令行参数组成的数组argv　排序
	sort_arr(argv, argc, sizeof(char *), str_cmp);
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);	
	}

	return 0;
}


//定义一个函数：给任意数组排序
//选择排序
void sort_arr(void *arr, int nmemb, int size, cmp_t cmp)
{	
	int ind;

	char *p = calloc(1, size);
	if (NULL == p)
		return;

	for (int i = 0; i < nmemb - 1; i++) {
		memcpy(p, (char *)arr + i*size, size);
		ind = i;
		for (int j = i+1; j < nmemb; j++) {
			if (cmp(p, (char *)arr+j*size) > 0) {
				memcpy(p, (char *)arr+j*size, size);		
				ind = j;
			}
		}
		if (i != ind) {
			memcpy((char *)arr+ind*size, (char *)arr+i*size, size);
			memcpy((char *)arr+i*size, p, size);	
		}
	}	

	free(p);
}


