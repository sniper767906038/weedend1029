#include <stdio.h>

/*
 	大端存储
		低字节存高地址,高字节存低地址
	小端存储
		低字节存低地址,高字节存高地址
 */

union test_un {
	char ch;
	int num;
};

int main(void)
{
	union test_un t;	

	printf("%p, %p\n", &t.ch, &t.num);
	printf("%ld\n", sizeof(t));

	t.num = 0x12345678;

	if (t.ch == 0x78) {
		printf("小端\n");
	} else {
		printf("大端:%#x\n", t.ch);
	}

	return 0;
}

