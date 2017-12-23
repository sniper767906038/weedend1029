#include <stdio.h>

enum {INSERT = 10 , DELETE, UPDATE = 20, SEARCH};
enum db{LEFT, RIGHT, UP, DOWN};

int main(void)
{
	enum db t;

	printf("%d %d %d %d\n", INSERT, DELETE, UPDATE, SEARCH);

	printf("sizeof(t):%ld\n", sizeof(t));

	return 0;
}

