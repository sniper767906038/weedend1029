#ifndef __QUEUE_H
#define __QUEUE_H

typedef struct {
	void *start;
	int front;
	int tail;
	int size;
	int maxnmemb;
}queue_t;

queue_t *queue_init(int size, int maxnmemb);

int queue_isempty(const queue_t *q);	

int queue_isfull(const queue_t *q);

int enq(queue_t *q, const void *data);

int deq(queue_t *q, void *data);

void queue_destroy(queue_t *q);

#endif

