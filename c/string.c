/*
 	strlen(3);
 	strcpy(3);---->man 3 strncpy 实现，并得出与strcpy()区别
	strcat(3);---->man 3 strncat 实现
	strcmp(3);---->man 3 strncmp

作业:
	strchr(3);
	strrchr(3);
	strstr(3);

 */
#include <stdio.h>
int mystrlen(const char *s);
int mystrcmp(const char *s1, const char * s2);
char *mystrcpy(char *d, const char *s);
char *mystrcat(char *d, const char *s);

int main(void)
{
#if 0
	char *p = "good moring";

	printf("%d\n", mystrlen(p));
#endif
#if 0
	//const
	char str[] = "helmoworld";	
	//指针常量(只读指针)　　　常量指针(*p只读)
	const char *p1 = str;//常量指针
	char const *p2 = str;//同上
	char * const p3 = str;//指针常量

	char *s = str;

	//printf(const char *s, int m);

	printf("%c\n", *s++);//m = *s++;--->m = *s, s ++;
	printf("%c\n", *(s++));// m = *(s++);--->m = *s, s++;
	printf("%c\n", (*s)++);// m = (*s)++;--->m = *s, *s = *s+1
	printf("%c\n", *++s);//m = *++s;--->s ++, m = *s
	printf("%c\n", ++*s);//m = ++*s;--->*s = *s+1; m = *s

	printf("%s\n", str);
#endif

#if 0
	//*p1  = 'm';//str[0]
	str[0] = 'm';
	p1++;
	printf("%s\n", p1);

	//*p2 = 'n';
	*p3 = 'k';
	//p3++;
	printf("%s\n", p3);
#endif

	char arr1[64] = "uplooking where are you";
	char *p = "good afternoon";
	int ret;

	//printf("%s\n", mystrcpy(arr1, p));
	//printf("%s\n", mystrcat(arr1, p));

	if ((ret = mystrcmp(arr1, p)) < 0) {
		printf("(%s) is less than (%s)\n", arr1, p);
	} else if (ret > 0) {
		printf("(%s) is more than (%s)\n", arr1, p);
	} else {
		printf("(%s) is equal to (%s)\n", arr1, p);
	}

	return 0;
}

int mystrlen(const char *s)
{
	int len = 0;	

#if 0
	while (*s) {// while (*s++)
		len ++;
		s++;
	}
#endif
	while (*s++)
		len ++;

	return len;
}

char *mystrcpy(char *d, const char *s)
{
	int i = 0;	

	for (; s[i]	!= '\0'; i++) {
		d[i] = s[i];	
	}
	d[i] = '\0';

	return d;
}

char *mystrcat(char *d, const char *s)
{
	char *ret = d;
	
	while (*d)
		d++;
	
	mystrcpy(d, s);

	return ret;
}

int mystrcmp(const char *s1, const char * s2)
{
	while (*s1 || *s2) {
		if (*s1 != *s2)
			return *s1 - *s2;
		s1++;
		s2++;
	}

	return 0;
}
