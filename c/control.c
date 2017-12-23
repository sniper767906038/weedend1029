#include <stdio.h>

/*
 
 	if (条件表达式) {
		执行体;	
	} else {
		
	}
 
	if (条件表达式) {
	
	} else if (condition) {
	
	} else {
	
	}

	switch (变量/变量表达式) {
		case 常量:
			break;
		case 常量:
			break;
		default:
			break;
	}

从标准输入读入一个成绩，判断其等级
	90~100 	A
	80~89	B
	70~79	C
	60~69	D
	0~59	E
 */

int main(void)
{
#if 0
	int num;
		
	scanf("%d", &num);

	if (num % 2) {
		printf("%d 是一个奇数\n", num);	
	} else {
		printf("%d 是一个偶数\n", num);
	}
#endif

#if 0
	int month;

	scanf("%d", &month);

	if (month >= 3 && month <= 5) {
		printf("Spring\n");
	} else if (month >= 6 && month <= 8) {
		printf("Summer\n");
	} else if (month >= 9 && month <= 11) {
		printf("Autumn\n");
	} else if (month == 12 || month == 1 || month == 2) {
		printf("Winter\n");
	} else {
		printf("i don't know\n");
	}

	switch (month) {
		case 1:
		case 2:
		case 12:
			printf("Winter\n");	
			break;//结束分支
		case 3:
		case 4:
		case 5:
			printf("Spring\n");	
			break;
		case 6:
		case 7:
		case 8:
			printf("Summer\n");
			break;
		case 9: case 10: case 11:
			printf("Autumn\n");
			break;
		default:
			printf("i don't know\n");	
			break;
	}
#endif

	//score
	int score;

	//校验
	do {
		scanf("%d", &score);
	} while (score < 0 || score > 100);

	switch (score / 10) {
		case 10:
		case 9:
			printf("A\n");	
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default:
			printf("E\n");
			break;
	}



	return 0;
}

