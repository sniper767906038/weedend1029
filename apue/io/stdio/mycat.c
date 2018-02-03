#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 10

int main(int argc, char **argv)
{
	FILE *fp = NULL;	
	int c;

	if (argc < 2)
		return 0;

	fp = fopen(argv[1], "r");
	if (NULL == fp) {
		perror("fopen()");
		return 1;
	}

#if 0
	//r--->argv[1] w---->stdout
	while (1) {
		c = fgetc(fp);
		if (c == EOF) {
			//eof error	
			if (ferror(fp)) {
				fprintf(stderr, "fgetc() failed\n");
				goto ERROR;
			}
			break;
		}
		fputc(c, stdout);	
		fflush(stdout);
		sleep(1);
	}
#endif

#if 0
	//line
	char buf[BUFSIZE] = {};
	char *ret = NULL;
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t r = 0;
	while (1) {
		//ret = fgets(buf, BUFSIZE, fp);	
		r = getline(&lineptr, &n, fp);
		if (r == -1) {
			if (feof(fp))
				 break;
			perror("getline()");
			goto ERROR;
		}
		printf("lineptr:%p\n", lineptr);
		printf("size:%ld\n", n);

		fputs(lineptr, stdout);	
		fflush(NULL);
		sleep(1);
	}
#endif

	//结构化	
	char ptr[BUFSIZE] = {};	
	size_t cnt;
	while (1) {
		cnt = fread(ptr, 1, BUFSIZE, fp);		
		if (cnt == 0) {
			if (ferror(fp))
				goto ERROR;
			break;
		}
		fwrite(ptr, 1, cnt, stdout);
	}  

	fclose(fp);

	return 0;
ERROR:
	fclose(fp);
	return 1;
}

