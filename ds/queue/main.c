#include <stdio.h>

#include "queue.h"

//./a.out "hello"
int main(int argc, char **argv)
{
	queue_t *que;
	char ch;

	if (argc < 2)
		return 1;

	que = queue_init(sizeof(char), 10);

	for (int i = 0; argv[1][i] != '\0'; i++) {
		if (!queue_isfull(que)) 
			enq(que, argv[1]+i);	
		else {
			printf("队列已满，出队一个元素\n");
			deq(que, &ch);
			printf("%c deq...\n", ch);
			--i;
		}
	}

	while (!queue_isempty(que)) {
		deq(que, &ch);
		printf("%c deq...\n", ch);
	}

	queue_destroy(que);


	return 0;
}

