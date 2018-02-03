#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char buf[100] = {};

	fp = tmpfile();
	//if error
	fwrite("hello world", 1, 11, fp);

	//获取文件偏移量
	printf("%ld\n", ftell(fp));
	//offset = 0
	rewind(fp);//fseek(fp, 0, SEEK_SET);
	printf("%ld\n", ftell(fp));

	//设置文件偏移量
	fseek(fp, 6, SEEK_SET);

	fread(buf, 1, 100, fp);
	puts(buf);

	fclose(fp);

	return 0;
}

