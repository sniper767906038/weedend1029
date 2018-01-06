#include <stdlib.h>
#include <string.h>

#include "list.h"

listhead_t *listhead_init(int size)
{
	listhead_t *h = NULL;

	h = malloc(sizeof(listhead_t));
	if (NULL == h)
		return NULL;
	h->head.data = NULL;	
	h->head.next = &h->head;
	h->size = size;

	return h;
}

int list_insert(listhead_t *h, const void *data, enum insert_en way)
{
	struct node_st *new = NULL;
	struct node_st *cur = NULL;

	//为新节点开辟存储空间
	new = calloc(1, sizeof(*new));
	if (NULL == new)
		return -1;
	//为新结点数据开辟存储空间
	new->data = malloc(h->size);
	if (NULL == new->data) {
		free(new);
		return -1;
	}
	memcpy(new->data, data, h->size);

	if (way == INSERT_FRONT) {
		new->next = h->head.next;	
		h->head.next = new;
	} else if (way == INSERT_TAIL) {
		for (cur = h->head.next; cur->next != &h->head; cur = cur->next)
			;
		//cur存储的就是最后一个结点的地址
		new->next = cur->next;	
		cur->next = new;
	} else {
		free(new->data);
		free(new);
		return -1;
	}

	return 0;
}

void list_traval(const listhead_t *h, void (*pri)(const void *))
{
	struct node_st *cur = NULL;	

	for (cur = h->head.next; cur != &h->head; cur = cur->next) {
		pri(cur->data);	
	}
}

void list_destroy(listhead_t *h)
{
	struct node_st *cur, *n;	

	for (cur = h->head.next, n = cur->next; cur != &h->head; cur = n, n = n->next) {
		free(cur->data);	
		free(cur);
	}

	free(h);
}

/*
 返回要找的结点的前一个结点的地址
 */
static struct node_st *findprevnode(const listhead_t *h, const void *key, cmp_t cmp) 
{
	struct node_st *prev, *cur;	

	prev = (void *)&h->head;
	cur = prev->next;

	while (cur != &h->head) {
		if (!cmp(cur->data, key)) {
			return prev;	
		}
		prev = cur;
		cur = cur->next;
	}

	return NULL;
}

int list_delete(listhead_t *h, const void *key, cmp_t cmp)
{
	struct node_st *prev = NULL, *del = NULL;

	prev = findprevnode(h, key, cmp);
	if (prev == NULL)
		return -1;
	del = prev->next;
	prev->next = del->next;
	del->next = NULL;

	free(del->data);
	free(del);

	return 0;
}


int list_update(listhead_t *h, const void *key, cmp_t cmp, const void *replacedata)
{
	struct node_st *prev = NULL, *cur = NULL;

	prev = findprevnode(h, key, cmp);
	if (prev == NULL)
		return -1;
	
	cur = prev->next;
	memcpy(cur->data, replacedata, h->size);

	return 0;
}


void *list_search(const listhead_t *h, const void *key, cmp_t cmp)
{
	struct node_st *prev = NULL, *cur = NULL;

	prev = findprevnode(h, key, cmp);
	if (prev == NULL)
		return NULL;
	
	cur = prev->next;
	
	return cur->data;
}

