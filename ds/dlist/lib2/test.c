#include <stdio.h>
#include <stdlib.h>

struct stu_st {
	int id;
	char name[32];
	char data[0];//char data[1]
};

int main(void)
{
	struct stu_st *p;

	printf("%ld\n", sizeof(struct stu_st));

	p = malloc(sizeof(*p) + 100);
	printf("%p %p\n", p, p->data);

	return 0;
}

