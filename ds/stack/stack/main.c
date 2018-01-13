#include <stdio.h>

#include <stack.h>

int main(void)
{
	int num[] = {1,2,3,4,5,6,7,8,9};
	int popnum;
	stack_t *s;
	
	s = stack_init(sizeof(int), 5);

	for (int i = 0; i < sizeof(num) / sizeof(*num); i++) {
		if (isfull(s)) {
			printf("栈已满\n");
			break;
		}
		push(s, num + i); 
	}

	while (!isempty(s)) {
		pop(s, &popnum);
		printf("%d pop\n", popnum);
	}

	destroy(s);

	return 0;
}

