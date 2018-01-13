#ifndef __LSTACK_H
#define __LSTACK_H

#include <list.h>

typedef struct list_head lstack_t; 

#define STACK_HEAD_INIT(name) LIST_HEAD(name)

int lstack_push(lstack_t *s, const void *data, int size);

int lstack_isempty(lstack_t *s);

int lstack_pop(lstack_t *s, void *data, int size);

void lstack_destroy(lstack_t *s);

#endif

