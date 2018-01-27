#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	int fd;
	char buf[100] = {};
	off_t offset;

	if (argc < 2)
		return 1;

	fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		perror("open()");
		return 1;
	}

	//从文件的末尾　将offset+
	offset = lseek(fd, 1024*1024*1024*2UL, SEEK_END);
	printf("%ld\n", offset);

	write(fd, "hello", 5);

	close(fd);	

	return 0;
}

