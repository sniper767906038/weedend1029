#include <stdio.h>

/*
c基本类型 
	整型
		char 字符型		1 
		short			2
		int				4
		long			8
		long long		8
	
	实型
		float			4
		double			8
		long double		16
	空类型
		void
	复合类型
		struct 
		union	


	类型字节宽度
		sizeof---->运算符		 

标识符
	变量名、函数名、类型名
	由字母、数字、下划线组成
	由字母/下划线开头
	避开c关键字
关键字
	类型
	signed unsigned for if else return goto while do 
	break continue sizeof const volatile static register...

运算符
	优先级
	man operator
	单目运算符
		& * ! ~ ++ --		
	双目运算符
		+ - * / % & | ^
	多目运算符
		? :
		,
	功能:
		算术运算符
			+ - * / % = += /= *= %= 
		位运算符
			& | ^ ~ << >> 
		逻辑运算符
			&& || ! 
		条件运算符	
			> < >= <= != ==
			num > 10 && num < 100
		其他
			++ --
			a++;
			++a;	

			exp1?exp2:exp3
			if (exp1) {
				exp2;
			} else {
				exp3;
			}

			,
			
变量/常量
	int a;
	char ch = 1;
	a = 10;
	a = ch;//a = (int)ch;

	double d = 1.2;
	ch = a + d;

vim ---->vimtutor
gcc 
	预处理
		-E
		处理预处理命令(#)
		#include-->头文件	
		宏
	编译
		-S
		c--->汇编	
	汇编
		-c	
	链接
		--->可执行文件

 */



int main(void)
{
	char ch;
	int num1, num2;

	ch = 100;

	ch += 1;//ch = ch + 1;

	num1 = 10;
	num2 = 50;

	//num1 = num2 + 1;

	num1 = num1 ^ num2;
	num2 = num1 ^ num2;//num2 = num1 ^ (num2 ^ num2);
	num1 = num1 ^ num2;//num1 = (num1 ^ num1) ^ num2

	printf("num1:%d, num2:%d\n", num1, num2);

	//++ --
	int t = 10;
	int m;

	//t = t + 1;
	m = t++;
	printf("m:%d, t:%d\n", m, t);
	
	m = ++t;
	printf("m:%d, t:%d\n", m, t);

	//强转
	int i;
	double d, d2;

	d = 10.91;
	i = d;

	d2 = d + (double)i;

	printf("i:%d, d:%lf, d2:%lf\n", i, d, d2);
	printf("the bytes of d is %ld\n", sizeof(d));
	printf("the bytes of d is %ld\n", sizeof d);
	printf("the bytes of d is %ld\n", sizeof(double));

	//[]
	printf("%d %d\n",(&i)[0], 0[&i]);
	//*(&i+0) == *&i == i

	//? :
	int n1, n2;

	n1 = 101;

	n2 = n1 % 2 ? n1++ : --n1;
	printf("n1:%d, n2:%d\n", n1, n2);

	//,
	n1 = 10;
	n2 = 20;

	n1 = (n1+n2, n1++, n2++, n1-n2);
	printf("n1:%d, n2:%d\n", n1, n2);

	printf("float--->%ld\n", sizeof(float));
	printf("double--->%ld\n", sizeof(double));
	printf("long double--->%ld\n", sizeof(long double));

	return 0;
}

