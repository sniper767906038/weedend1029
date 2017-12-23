#ifndef __SEQLITE_H
#define __SEQLITE_H
//条件编译的作用：防止头文件重复包含

#define INITNMEMB	10
#define INCRECE		5

//类型的定义
typedef struct {
	void *p;//存储数组的首地址
	int size;//byte/member
	int nmemb;//当前数组中的成员个数
	int maxnmemb;//已有空间最多存放的成员个数
}seqlist_t;

//函数的声明
//实例化表头结构
seqlist_t *seqlist_init(int size);

//插入
int seqlist_insert(seqlist_t *q, const void *data);

//查
void *seqlist_search(const seqlist_t *q, const void *key, int (*cmp)(const void *data, const void *key));

//删除
/*
 	q:表头地址,找到数组
	key:删除关键字的地址,由于不确定数据类型,所以用void *指针可以存储任意类型的地址
	cmp:函数指针，存储的是用户提供的比较数组元素和key的函数
	return:
		0	删除成功	
		-1	失败
 */
int seqlist_delete(seqlist_t *q, const void *key, int (*cmp)(const void *data, const void *key));


//遍历
void seqlist_traval(const seqlist_t *q, void (*pri)(const void *data));

//销毁
void seqlist_destroy(seqlist_t *q);

#endif

