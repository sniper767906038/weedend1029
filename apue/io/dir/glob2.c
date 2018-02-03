#include <stdio.h>
#include <glob.h>

int main(int argc, char **argv)
{
	glob_t res;
	int flag = 0;

	for (int i = 0; i < argc; i++) {
		glob(argv[i], GLOB_NOCHECK | GLOB_APPEND * flag, NULL, &res);
		flag = 1;
	}

	for (int i = 0; i < res.gl_pathc; i++) {
		puts((res.gl_pathv)[i]);	
	}

	globfree(&res);

	return 0;
}

