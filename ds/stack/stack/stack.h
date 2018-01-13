#ifndef __STACK_H
#define __STACK_H

typedef struct {
	void *bottom;
	int top;//入栈元素的下标
	int size;
	int maxnmemb;//栈容量
}stack_t;

stack_t *stack_init(int size, int maxnmemb);

int isempty(stack_t *s);

int isfull(stack_t *s);

int push(stack_t *s, const void *data);

int pop(stack_t *s, void *data);

void destroy(stack_t *s);

#endif

