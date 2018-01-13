#ifndef __DLIST_H
#define __DLIST_H

typedef enum {
	INSERT_FRONT,
	INSERT_TAIL
}insert_t;


//双向环链
struct node_st {
	void *data;
	struct node_st *prev;
	struct node_st *next;
};

typedef struct {
	struct node_st head;
	int size;
}dlisthead_t;

typedef int (*cmp_t)(const void *data, const void *key);
typedef void (*pri_t)(const void *data);

dlisthead_t *dlisthead_init(int size);

int dlist_add(dlisthead_t *l, const void *data, insert_t way);

int dlist_delete(dlisthead_t *l, const void *key, cmp_t cmp);

void *dlist_search(const dlisthead_t *l, const void *key, cmp_t cmp);

int dlist_isempty(const dlisthead_t *l);

/*
 将制定的结点从链表中摘除(删除的同时获取其数据)
 */
int dlist_fetch(dlisthead_t *l, const void *key, cmp_t cmp, void *data);

void dlist_traval(const dlisthead_t *l, pri_t pri);

void dlist_destroy(dlisthead_t *l);

#endif

