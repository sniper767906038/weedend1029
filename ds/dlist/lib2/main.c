#include <stdio.h>
#include <string.h>

#include <dlist.h>

typedef struct {
	int age;
	char name[32];
}person_t;

static void traval(const void *data);
static int name_cmp(const void *data, const void *key);
int main(void)
{
	dlisthead_t *head;		
	person_t ps;
	int ages[] = {24,26,23,25,30,29};
	char *names[] = {"xiaobai", "zhangsan", "lisi", "wangwu", "zhaoliu", "uplooking"};
	char *nm = "wangwuwu";

	head = dlisthead_init(sizeof(person_t));

	for (int i = 0; i < sizeof(ages) / sizeof(*ages); i++) {
		ps.age = ages[i];	
		strcpy(ps.name, names[i]);
		//dlist_add(head, &ps, INSERT_FRONT);
		dlist_add(head, &ps, INSERT_TAIL);
	}	

	dlist_traval(head, traval);

	printf("***********删除*************\n");
	if (dlist_delete(head, nm, name_cmp) < 0) {
		printf("没有要删除的元素\n");
	} else {
		printf("删除成功\n");
		dlist_traval(head, traval);
	}


	dlist_destroy(head);

	return 0;
}

static void traval(const void *data)
{
	const person_t *d = data;

	printf("%d %s\n", d->age, d->name);
}

static int name_cmp(const void *data, const void *key)
{
	const person_t *d = data;
	const char *k = key;

	return strcmp(d->name, k);
}

