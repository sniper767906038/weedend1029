#include <stdio.h>
#include <string.h>

#define NAMESIZE 32

struct student_st {
	int id;
	float c_score;
	char name[NAMESIZE];
};

int main(void)
{
	//struct student_st结构体类型
	struct student_st stu;
	//初始化
	struct student_st stu1 = {2, 100, "yangming"};
	struct student_st *p;

	p = &stu;

	//赋值
	stu.id = 1;
	stu.c_score = 90.23;
	strcpy(stu.name, "guolin");

	printf("%d %.2f %s\n", stu.id, stu.c_score, stu.name);
	printf("%d %.2f %s\n", stu1.id, stu1.c_score, stu1.name);
	printf("%d %.2f %s\n", p->id, p->c_score, p->name);

	return 0;
}

