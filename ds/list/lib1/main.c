#include <stdio.h>
#include <string.h>

#include "list.h"

#define NAMESIZE	32

struct stu_st {
	int id;
	char name[NAMESIZE];
};

static void fun_print(const void *data);
static int id_cmp(const void *data, const void *key);
static int name_cmp(const void *data, const void *key);
int main(void)
{
	listhead_t *list = NULL;
	struct stu_st stu;
	int id[] = {3,2,1,6,7,9,8};
	char *name[] = {"yangming", "lilei", "wangxinmin", "zhaodong", "chushuangwei",\
	"dengchao", "guolin"};
	int delid;
	char *delname;

	list = listhead_init(sizeof(struct stu_st));
	//if error

	for (int i = 0; i < sizeof(id) / sizeof(*id); i++) {
		stu.id = id[i];	
		strcpy(stu.name, name[i]);
		list_insert(list, &stu, INSERT_TAIL);
	}
	
	list_traval(list, fun_print);

	delid = 1;
	delname = "yangming";

	printf("***********delete id = 1*************\n");
	list_delete(list, &delid, id_cmp);
	list_traval(list, fun_print);
	printf("***********delete name yangming*********\n");
	list_delete(list, delname, name_cmp);
	list_traval(list, fun_print);
	
	printf("************update******************\n");
	stu.id = 100;
	strcpy(stu.name, "uplooking");
	delid = 7;
	list_update(list, &delid, id_cmp, &stu);
	list_traval(list, fun_print);

	list_destroy(list);

	return 0;
}

static void fun_print(const void *data)
{
	const struct stu_st *d = data;

	printf("%d %s\n", d->id, d->name);
}

static int id_cmp(const void *data, const void *key)
{
	const struct stu_st *d = data;
	const int *k = key;

	return d->id - *k;
}

static int name_cmp(const void *data, const void *key)
{
	const struct stu_st *d = data;
	const char *k = key;

	return strcmp(d->name, k);
}






