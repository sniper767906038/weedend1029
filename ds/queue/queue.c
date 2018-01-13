#include <stdlib.h>
#include <string.h>

#include "queue.h"

queue_t *queue_init(int size, int maxnmemb)
{
	queue_t *me = NULL;

	me = malloc(sizeof(*me));
	if (NULL == me)
		return NULL;
	memset(me, '\0', sizeof(*me));
	me->start = calloc(maxnmemb, size);
	if (NULL == me->start) {
		free(me);
		return NULL;
	}
	me->front = me->tail = 0;
	me->size = size;
	me->maxnmemb = maxnmemb;

	return me;
}

int queue_isempty(const queue_t *q)
{
	return q->front == q->tail;
}

int queue_isfull(const queue_t *q)
{
	return (q->tail + 1) % q->maxnmemb == q->front;
}

int enq(queue_t *q, const void *data)
{
	if (queue_isfull(q))
		return -1;
	//队尾	
	memcpy((char *)q->start + q->tail * q->size, data, q->size);
	q->tail = (q->tail + 1) % q->maxnmemb;

	return 0;
}

int deq(queue_t *q, void *data)
{
	if (queue_isempty(q))
		return -1;

	memcpy(data, (char *)q->start + q->front * q->size, q->size);
	q->front = (q->front+1) % q->maxnmemb;

	return 0;
}

void queue_destroy(queue_t *q)
{
	free(q->start);	
	free(q);
}

