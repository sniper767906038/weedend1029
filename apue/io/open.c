#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// 谁申请谁释放，谁打开谁关闭

int main(int argc, char **argv)
{
	int fd;

	if (argc < 2)
		return 1;

	//close(0);
	fd = open(argv[1], O_RDONLY | O_CREAT, 0666);
	//if error

	printf("fd:%d\n", fd);

	close(fd);

	return 0;
}

