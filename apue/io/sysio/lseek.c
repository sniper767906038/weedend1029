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
	int cnt;
	off_t offset;

	if (argc < 2)
		return 1;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("open()");
		return 1;
	}

	cnt = read(fd, buf, 99);
	puts(buf);

	offset = lseek(fd, 5, SEEK_CUR);
	printf("offset: %ld\n", offset);

	memset(buf, '\0', 100);
	read(fd, buf, 10);
	puts(buf);

	close(fd);	

	return 0;
}

