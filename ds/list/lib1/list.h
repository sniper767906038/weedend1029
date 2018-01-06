#ifndef __LIST_H
#define __LIST_H

//单循环链表

//枚举插入方式类型
enum insert_en{
	INSERT_FRONT=1,
	INSERT_TAIL
};

/*
 抽象数据类型
 */
struct node_st {
	void *data;//数据域的地址
	struct node_st *next;//下一个结点的地址
};

typedef struct {
	struct node_st head;
	int size;//存储链表中数据字节个数
}listhead_t;

//定义比较函数指针类型 0相等
typedef int (*cmp_t)(const void *data, const void *key);

/*
 定义接口函数
 */
/*
 初始化头结点
size:存储数据字节个数
return value:
	头结点的地址
 */
listhead_t *listhead_init(int size);

/*
 insert
h:头结点的地址(找到单链表，并获取数据字节个数)
data:待插入元素的数据首地址
way:插入方式
 */
int list_insert(listhead_t *h, const void *data, enum insert_en way);

/*
 delete
h:头结点地址
key:删除关键字地址
cmp:存储比较函数的地址
	对于链表中存储的每一个结点, 我们能够得到的只是它的数据的首地址
	所以如果与关键字比较，需要使用者提供比较函数
 */
int list_delete(listhead_t *h, const void *key, cmp_t cmp);

/*
 update
h:头结点地址
key:删除关键字地址
cmp:存储比较函数的地址
replacedata:到更改的数据地址
 */
int list_update(listhead_t *h, const void *key, cmp_t cmp, const void *replacedata);

/*
	search 
h:头结点地址
key:关键字地址 
cmp:比较函数
return value:
	找到的数据域地址
	如果没有找到 返回NULL
 */
void *list_search(const listhead_t *h, const void *key, cmp_t cmp);

/*
 traval
h:头结点地址
pri:打印函数的地址
	对于链表只能获取到数据域地址，并不知道是什么类型
	使用者已知所存储的数据类型,可提供打印函数
 */
void list_traval(const listhead_t *h, void (*pri)(const void *));

void list_destroy(listhead_t *h);


#endif

