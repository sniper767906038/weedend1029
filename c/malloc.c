#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITSIZE	32
#define INCREACE	5

/*
	定义一个函数,从标准输入得到一行字符串,将字符串返回 
	//要求字符串的长度，不超过32个字节
 */

int *getarray(int n);
//char *getstring(void);
int getstring(char **);
int readString(char **str);
int main(void)
{
	int *p = NULL;
	char *str = NULL;
#if 0
	p = getarray(10);

	for (int i = 0; i < 10; i++) {
		//p[i] = i+1;	
		printf("%d ", p[i]);
	}	
	printf("\n");

	free(p);	
	p = NULL;//防止重复释放
	free(p);

	//str = getstring();
	getstring(&str);
	printf("%s\n", str);

	free(str);
	str = NULL;
	free(str);//no operation is performed
#endif

	if (readString(&str) == 0) {
		puts(str);
		free(str);
	}

	return 0;
}

int *getarray(int n)
{
	//int arr[n];no
	//static int arr[n];yes
	int *arr = NULL;//NULL--->(void *)0

#if 0
	arr = malloc(n*sizeof(int));	
	if (NULL == arr) {
		printf("malloc() failed\n");
		return NULL;
	}

	//初始化地址空间
	memset(arr, '\0', n*sizeof(int));
#endif
	arr = calloc(n, sizeof(int));
	if (NULL == arr) {
		printf("calloc() failed\n");
		return NULL;
	}

	return arr;
}

//char *getstring(void)
int getstring(char **p)//p二级指针，存储一级指针变量的地址
{
	int i;
	*p = calloc(32, sizeof(char));
	if (NULL == *p) {
		printf("calloc() failed\n");
		return -1;
	}
	
	for (i = 0; i < 32; i++) {
		scanf("%c", *p+i);//&(*p)[i]
		if ((*p)[i] == '\n') {
			(*p)[i] = '\0';	
			break;
		}
	}

	if (i == 32) {
		(*p)[i-1] = 0;	
	}

	return 0;
}

/*
	定义一个函数
   	功能：读入终端输入的一行字符串	
 */

int readString(char **str)
{
	char ch;
	int i;
	int len;

	*str = malloc(INITSIZE);	
	if (NULL == *str) {
		printf("[%d]malloc failed\n", __LINE__);
		return -1;		
	}
	len = INITSIZE;

	i = 0;
	while (1) {
		ch = getchar();	
		if (ch == '\n') {
			(*str)[i] = '\0';
			break;
		}
		(*str)[i] = ch;
		i++;
		if (i >= len) {
			len += INCREACE;
			*str = realloc(*str, len);		
			if (NULL == *str) {
				printf("[%d]remalloc failed\n", __LINE__);
				return -1;
			}
		}
	}

	//开辟的存储空间的大于字符串占用的
	if (len > i+1) {
		*str = realloc(*str, i+1);	
		if (NULL == *str) {
			printf("[%d]remalloc failed\n", __LINE__);
			return -1;
		}
	}
	
	return 0;
}



