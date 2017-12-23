/*
 字符串
 	"hello"--->char *
	由若干字符组成,'\0'字符结束
 字符数组
	char	 
 */
#include <stdio.h>

int main(void)
{
	//字符数组　不是字符串
	char str[5] = {'h', 'e', 'l', 'l', 'o'};
	//用字符串初始化字符数组
	char str2[6] = "hello";
	char str3[8] = {'h', 'e', 'l', 'l', 'o', '\0', 'm', 'n'};
	char str4[] = {"hello"};

	printf("%s, %s, %s\n", str2, str3, str4);

	return 0;
}


