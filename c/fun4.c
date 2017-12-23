#include <stdio.h>

/*
 变量
 	全局变量
		定义在函数体外的变量
		未初始化,值是0
		从定义开始，到整个工程，都是有效的
 	局部变量
		定义在函数体内的变量
		未初始化，值是随机值
		从定义开始，到函数结束，都是有效的

		静态:
			

		作用域及生存周期不同
	修饰词
		默认 auto
		volatile
		static 静态变量--->静态区
			修饰局部变量
			修饰全局变量
			修饰函数
		register
			寄存器变量
		const
			只读变量
 */

static int m;//只能在本文件中使用
int glob1, glob2, glob3;//全局变量 == auto int glob;
static void test(int n1, int n2);//此函数只能在本文件中调用
int main(void)
{
	int var1, var2, var3;//局部变量
	const int num = 10;

	//num = 100;

	printf("glob1:%d, glob2:%d, glob3:%d\n", glob1, glob2,\
			glob3);
	printf("var1:%d, var2:%d, var3:%d\n", var1, var2, var3);

	test(1, 2);
	test(1, 2);
	test(1, 2);

	return 0;
}

//n1 n2相当于test函数内的局部变量
static void test(int n1, int n2)
{
	static int i = 1;//局部静态变量, 只初始化一次，函数结束，空间不释放
	printf("i:%d\n", i);	
	i++;
}

