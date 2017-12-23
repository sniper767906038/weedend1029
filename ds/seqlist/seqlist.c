#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

seqlist_t *seqlist_init(int size)
{
	seqlist_t *list;

	list = malloc(sizeof(*list));
	if (NULL == list) {
		return NULL;	
	}
	list->p = calloc(INITNMEMB, size);
	if (NULL == list->p) {
		free(list);
		return NULL;
	}
	list->size = size;
	list->nmemb = 0;
	list->maxnmemb = INITNMEMB;

	return list;
}

int seqlist_insert(seqlist_t *q, const void *data)
{
	if (q->nmemb >= q->maxnmemb) {
		q->p = realloc(q->p, (q->maxnmemb+INCRECE) * q->size);	
		if (NULL == q->p) {
			return -1;
		}
		q->maxnmemb += INCRECE;
	}

	//确保新插入的成员有空间存放
	memcpy((char *)(q->p)+q->size*q->nmemb, data, q->size);		
	q->nmemb ++;

	return 0;
}

/*
	返回要找的元素的地址
 */
void *seqlist_search(const seqlist_t *q, const void *key, int (*cmp)(const void *data, const void *key))
{
	for (int i = 0; i < q->nmemb; i++) {
		if (cmp((char *)(q->p)+i*q->size, key) == 0)
			return (char *)(q->p)+i*q->size;
	}

	return NULL;	
}

int seqlist_delete(seqlist_t *q, const void *key, int (*cmp)(const void *data, const void *key))
{
	char *end = NULL;//存储数组的最后一个成员的下一个地址
	char *tmp = NULL;//要删除的时候，待覆盖的首地址
	void *find = NULL;
	//找到
	find = seqlist_search(q, key, cmp);
	if (find == NULL)
		return -1;
			
	//将地址为find的元素删除
	end = (char *)(q->p) + q->nmemb * q->size;
	tmp = (char *)find + q->size;
	memcpy(find, tmp, end-tmp);
	q->nmemb --;

	q->p = realloc(q->p, q->nmemb * q->size);
	//if error

	return 0;
}

void seqlist_traval(const seqlist_t *q, void (*pri)(const void *data))
{
	for (int i = 0; i < q->nmemb; i++) {
		pri((char *)(q->p)+i*q->size);	
	}	
}

void seqlist_destroy(seqlist_t *q)
{
	free(q->p);
	free(q);
}

