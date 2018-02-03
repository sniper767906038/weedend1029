#include <stdio.h>
#include <glob.h>
#include <string.h>

int main(int argc, char **argv)
{
	glob_t res;
	char buf[100] = {};

	//pattern ---->argv[1]
	if (argc < 2)
		return 1;

	glob(argv[1], GLOB_NOSORT, NULL, &res);

	//glob默认不读取隐藏文件
	//读隐藏文件
	//argv[1] ----> "/etc/*" -----> "/etc/.*"
	strcpy(buf, argv[1]);
	memmove(buf+strlen(buf), buf+strlen(buf)-1, 1);	//"/etc/**"
	buf[strlen(buf)-2] = '.';
	//puts(buf);
	glob(buf, GLOB_APPEND | GLOB_NOSORT, NULL, &res);

	for (int i = 0; i < res.gl_pathc; i++) {
		printf("%s\n", (res.gl_pathv)[i]);	
	}


	globfree(&res);

	return 0;
}

