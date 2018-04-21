#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	char *p = NULL;
	struct stat res;

	if (argc < 2)
		exit(1);

	fd = open(argv[1], O_RDONLY);
	//if error

	//　获取文件字节个数
	if (fstat(fd, &res) < 0) {
		perror("fstat()");
		close(fd);
		exit(1);
	}

	p = mmap(NULL, res.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (MAP_FAILED == p) {
		perror("mmap()");
		goto ERROR;
	}
	puts(p);	

	munmap(p, res.st_size);

	exit(0);
ERROR:
	close(fd);
	exit(1);
}

