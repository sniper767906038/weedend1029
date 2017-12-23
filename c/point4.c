#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ls -l
//char *arr[3] = {"ls", '-l', NULL};

/*
	./a.out 1234 
	"1234"---->1234
	./a.out -1234
	"-1234"---->-1234

	实现四则运算
		./a.out 1 + 2
			1+2=?
		./a.out 100 x 20
 */

//指针数组
int myatoi(const char *p);
int caculate2num(int a, int b, const char *op);
int main(int argc, char *argv[]/*char **argv*/)
{
	//char *--->&--->char **	

#if 0
	for (int i = 0; /*i < argc*/ argv[i]; i++) {
		printf("%s\n", argv[i]);	
	}
#endif
#if 0
	if (argc < 2)
		return 1;
	printf("%d\n", myatoi(argv[1]));
#endif
	if (argc < 4)
		return 1;	
	printf("%s %s %s = %d\n", argv[1], argv[2], argv[3], \
			caculate2num(atoi(argv[1]), atoi(argv[3]), argv[2]));

	return 0;
}

int myatoi(const char *p)
{
	int res = 0;		
	int flag = 1;
	
	if (*p == '-') {
		flag = -1;	
		p++;
	}
		
	while (*p) {
		res = res * 10 + (*p - '0');
		p++;
	}

	return res * flag;
}

int caculate2num(int a, int b, const char *op)
{
	if (!strcmp(op, "+")) {
		return a + b;	
	}
	
	if (!strcmp(op, "-")) {
		return a - b;	
	}

	if (!strcmp(op, "x")) {
		return a * b;	
	}

	if (!strcmp(op, "/")) {
		return a / b;	
	}
}






