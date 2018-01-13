#include <stdio.h>

#include <lstack.h>

int main(void)
{
	int num[] = {1,2,3,4,5,6,7,8,9};
	int popnum;
	
	STACK_HEAD_INIT(s);

	for (int i = 0; i < sizeof(num) / sizeof(*num); i++) {
		lstack_push(&s, num + i, sizeof(int));	
	}

	while (!lstack_isempty(&s)) {
		lstack_pop(&s, &popnum, sizeof(int));
		printf("%d pop\n", popnum);
	}

	lstack_destroy(&s);

	return 0;
}

