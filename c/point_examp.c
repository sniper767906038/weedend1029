#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//形参改变实参
void swap2num(int *num1, int *num2);
//函数返回值的回填
int arrmax_min(int *p/*int p[]*/, int nmemb, int *max, int *min);
int main(void)
{
	int n1 = 100;
	int n2 = 200;
	int arr[20] = {};
	int max, min;

	swap2num(&n1, &n2);//函数的传参是值传递的过程 
	//num1 = n1, num2 = n2
	printf("n1:%d, n2:%d\n", n1, n2);

	//随机产生
	srand(getpid());
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");	

	arrmax_min(arr, 20, &max, &min);

	printf("max:%d, min:%d\n", max, min);

	return 0;
}

void swap2num(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

int arrmax_min(int *p/*int p[]*/, int nmemb, int *max, int *min)
{
	*max = *min = p[0];

	for (int i = 1; i < nmemb; i++) {
		if (p[i] > *max)	
			*max = p[i];
		if (p[i] < *min)
			*min = p[i];
	}
}







