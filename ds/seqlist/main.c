#include <stdio.h>
#include "seqlist.h"

struct stu_st {
	int id;
	float score;
};

static void pri_stu(const void *data)
{
	const struct stu_st *d = data;

	printf("%d %f\n", d->id, d->score);
}

static int id_cmp(const void *data, const void *key)
{
	const struct stu_st *d = data;
	const int *k = key;

	return d->id - *k; 
}

int main(void)
{
	seqlist_t *list;	
	struct stu_st stu;
	int delid;

	list = seqlist_init(sizeof(struct stu_st));	
	if (list == NULL) {
		printf("seqlist_init() failed\n");
		return 1;
	}

	stu.id = 1;
	stu.score = 100;
	seqlist_insert(list, &stu);

	stu.id = 2;
	stu.score = 98.12;	
	seqlist_insert(list, &stu);

	seqlist_traval(list, pri_stu);

	printf("after delete\n");
	//删除
	delid = 1;
	seqlist_delete(list, &delid, id_cmp);
	seqlist_traval(list, pri_stu);

	seqlist_destroy(list);

	return 0;
}

