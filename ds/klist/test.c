#include <stdio.h>

struct list_head {
	struct list_head *prev;
	struct list_head *next;
};

struct data_st {
	int id;
	char name[32];	
	int score;
	struct list_head node;
	float height;
};

int main(void)
{
	printf("%ld\n", (int)(&((struct data_st *)0)->node));

	return 0;
}
