#include <stdlib.h>
#include <string.h>

#include <dlist.h>

dlisthead_t *dlisthead_init(int size)
{
	dlisthead_t *me = NULL;

	me = malloc(sizeof(*me));
	if (NULL == me)
		return NULL;
	memset(me, '\0', sizeof(*me));

	me->head.prev = &me->head;
	me->head.next = &me->head;
	me->size = size;

	return me;
}

/*
 将一个新的结点插入到两个结点之间
 将new指向的结点插到p 和 n之间
 */
static void __listadd(struct node_st *new, struct node_st *p, struct node_st *n)
{
	new->prev = p;
	new->next = n;
	p->next = new;
	n->prev = new;
}

int dlist_add(dlisthead_t *l, const void *data, insert_t way)
{
	struct node_st *new;

	//为新结点开辟存储空间
	new = malloc(sizeof(*new)+l->size);
	if (NULL == new)
		return -1;
	memset(new, '\0', sizeof(*new)+l->size);
	memcpy(new->data, data, l->size);

	//插入链表
	if (way == INSERT_FRONT) {
		__listadd(new, &l->head, l->head.next);
	} else if (way == INSERT_TAIL) {
		__listadd(new, l->head.prev, &l->head);	
	} else {
		free(new->data);
		free(new);
		return -1;
	}

	return 0;
}

/*
 删除某一个指定的结点
 */
static void __listdelete(struct node_st *del) 
{
	del->prev->next = del->next;	
	del->next->prev = del->prev;
	del->prev = del->next = NULL;

}

/*
 找到指定结点
 */
static struct node_st *__find(const dlisthead_t *l, const void *key, cmp_t cmp) 
{
	struct node_st *cur = NULL;

	for (cur = l->head.next; cur != &l->head; cur = cur->next) {
		if (!cmp(cur->data, key))	
			return cur;
	}

	return NULL;
}

int dlist_delete(dlisthead_t *l, const void *key, cmp_t cmp)
{
	//找到要删除的结点	
	struct node_st *f = __find(l, key, cmp);
	if (f == NULL)
		return -1;
	__listdelete(f);
	free(f);

	return 0;
}

void *dlist_search(const dlisthead_t *l, const void *key, cmp_t cmp)
{
	struct node_st *f = __find(l, key, cmp);
	if (f == NULL)
		return NULL;
	
	return f->data;
}

/*
 将制定的结点从链表中摘除(删除的同时获取其数据)
 */
int dlist_fetch(dlisthead_t *l, const void *key, cmp_t cmp, void *data)
{
	void *p = dlist_search(l, key, cmp);
	if (p == NULL)
		return -1;
	memcpy(data, p, l->size);

	dlist_delete(l, key, cmp);

	return 0;
}

void dlist_traval(const dlisthead_t *l, pri_t pri)
{
	struct node_st *cur;

	for (cur = l->head.next; cur != &l->head; cur = cur->next) {
		pri(cur->data);	
	}
}

void dlist_destroy(dlisthead_t *l)
{
	struct node_st *cur;

	if (l->head.next == &l->head && l->head.prev == &l->head) {
		free(l);
		return;
	}

	cur = (l->head.next)->next;

	while (cur != &l->head) {
		free(cur->prev);
		cur = cur->next;
	}
	free(cur->prev);

	free(l);
}


int dlist_isempty(const dlisthead_t *l)
{
	return l->head.next == &l->head && l->head.prev == &l->head;
}

