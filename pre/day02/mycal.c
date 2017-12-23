#include <stdio.h>

//已知1990.1.1是星期1 求得90年以后的任意日历
//1998/3

/*
 函数的声明
 	参数类型
	函数名
	返回值类型
 */
int isleap(int year);
int dayofmonth(int month, int year);
int main(void)
{
	int year, month;
	int sum = 0;
	int monthdays = 0;

	//1990～year(读入)总共多少天  &&   ||
	printf("请输入查看的日期(yy/mm)\n");
	scanf("%d/%d", &year, &month);

	for (int i = 1990; i < year; i++) {
		sum += (365 + isleap(i));
	}	
	//printf("sum:%d\n", sum);
	//year.1~year/month
	for (int i = 1; i < month; i++) {
		sum += dayofmonth(i, year);
	}
	//month.1
	sum += 1;

	/*
	 	函数的调用
			函数的传参是值传递的过程
	 */
	monthdays = dayofmonth(month, year);

	printf("星期%d, 共%d天\n", sum % 7, monthdays);

	printf("        %d月%d\n", month, year);	
	printf("sun mon thu wed thr fri sat\n");
	for (int i = 0; i < sum % 7; i++) {
		printf("    ");	
	}
	for (int i = 1; i <= monthdays; i++) {
		printf("%3d", i);		
		if ((i+sum%7) % 7 == 0)
			printf("\n");
		else
			printf(" ");
	}
	printf("\n");

	return 0;
}

/*
 	函数定义　　声明　　　调用
	函数定义 
		函数功能
		参数:已知值 
		结果:返回值
	返回值类型 函数名(参数列表)
 */
int isleap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))	
		return 1;

	return 0;
}

/*
	计算出月份对应的天数 
 */
int dayofmonth(int month, int year)
{
	int monthdays;

	if (month == 1 || month == 3 || month == 5 || month == 7 ||\
			month == 8 || month == 10 ||  month == 12)	
		monthdays = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		monthdays = 30; 
	else {
		monthdays = 28 + isleap(year);
	}

	return monthdays;
}


