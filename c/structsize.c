#include <stdio.h>

#pragma pack(1)

struct test {
	char a; 
	char d;	
	long b;
//	int c;
}__attribute__((packed));/*结构体单字节对齐*/

typedef struct test2 {
	char a;
	int b;
}t2;

int main(void)
{
	struct test t;
	printf("%p, %p, %p\n", &t.a, &t.b, &t.d/*, &t.c*/);	

	printf("%ld\n", sizeof(struct test));
	printf("%ld\n", sizeof(struct test2));

	return 0;
}

