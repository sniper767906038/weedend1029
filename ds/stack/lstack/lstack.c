#include <stdlib.h>
#include <string.h>
#include "lstack.h"

struct node_st {
	lstack_t node;
	char data[0];
};

int lstack_push(lstack_t *s, const void *data, int size)
{
	struct node_st *new;	

	new = malloc(sizeof(*new) + size);
	if (NULL == new)
		return -1;
	memcpy(new->data, data, size);

	list_add(&new->node, s);

	return 0;
}

int lstack_isempty(lstack_t *s)
{
	return list_empty_careful(s);
}

int lstack_pop(lstack_t *s, void *data, int size)
{
	struct list_head *pos;
	struct node_st *cur;

	list_for_each(pos, s) {
		cur = list_entry(pos, struct node_st, node); 	
		memcpy(data, cur->data, size);
		list_del(pos);
		break;	
	}

	return 0;
}

void lstack_destroy(lstack_t *s)
{
	struct list_head *pos;
	struct node_st *cur;

	if (lstack_isempty(s))
		return;

	list_for_eachnext(pos, s) {
		//前一个结点的首地址
		cur = list_entry(pos->prev, struct node_st, node); 	
		free(cur);
	}
	//最后一个
	cur = list_entry(pos->prev, struct node_st, node); 	
	free(cur);
}

