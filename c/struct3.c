#include <stdio.h>

struct test_st {
	int id;
	char name[32];
	struct test_st *t;
};

int main(void)
{
	struct test_st test1, test2 = {1, "wangxinmin", NULL};

	test1.t = &test2;

	printf("%d %s\n", (test1.t)->id, (test1.t)->name);

	return 0;
}

