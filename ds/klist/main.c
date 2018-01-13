#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#define NAMESIZE 32

struct stu_st {
	int id;
	char name[NAMESIZE];
	struct list_head node;
};

int main(void)
{
	int id[] = {1,2,3,4,5,6};
	char *name[] = {"aa", "bb", "cc", "dd", "ee", "ff"};
	struct stu_st *s = NULL;
	struct list_head *pos = NULL;
		
	//初始化头结点
	LIST_HEAD(head);	
	
	for (int i = 0; i < sizeof(id) / sizeof(*id); i++) {
		s = calloc(1, sizeof(struct stu_st));	
		//if error
		s->id = id[i];
		strcpy(s->name, name[i]);
		list_add_tail(&s->node, &head);
	}

	list_for_each(pos, &head) {
		s = list_entry(pos, struct stu_st, node);
		//printf("%d %s\n", s->id, s->name);
		if (s->id == 5) {
			list_del(&s->node);
			free(s);
			break;
		}
	}

	list_for_each(pos, &head) {
		s = list_entry(pos, struct stu_st, node);
		printf("%d %s\n", s->id, s->name);
	}

	return 0;
}

