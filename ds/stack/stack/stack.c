#include <stdlib.h>
#include <string.h>
#include <stack.h>

stack_t *stack_init(int size, int maxnmemb)
{
	stack_t *s = NULL;

	s = malloc(sizeof(*s));
	if (NULL == s)
		return NULL;
	memset(s, '\0', sizeof(*s));
	s->bottom = calloc(maxnmemb, size);
	if (NULL == s->bottom) {
		free(s);
		return NULL;
	}
	s->top = 0;
	s->size = size;
	s->maxnmemb = maxnmemb;

	return s;
}

int isempty(stack_t *s)
{
	return s->top == 0;
}

int isfull(stack_t *s)
{
	return s->top == s->maxnmemb;
}

int push(stack_t *s, const void *data)
{
	if (isfull(s))
		return -1;
	memcpy((char *)s->bottom + s->top*s->size, data, s->size);
	s->top ++;

	return 0;
}

int pop(stack_t *s, void *data)
{
	if (isempty(s))
		return -1;
	s->top --;
	memcpy(data, (char *)s->bottom + s->top*s->size, s->size);
	memset((char *)s->bottom+s->top*s->size, '\0', s->size);

	return 0;
}

void destroy(stack_t *s)
{
	free(s->bottom);
	free(s);
}

