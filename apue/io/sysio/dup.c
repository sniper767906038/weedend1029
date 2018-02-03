#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd1, fd2;
	char buf[100] = {};
	int cnt;

	// 不原子操作:完成一件事情需要多个函数完成，那么一定不原子
#if 0
	close(2);
	fd1 = dup(0);
#endif
	//原子操作
	dup2(0, 2);
		
	fd2 = dup(1);
	
	printf("fd1:%d, fd2:%d\n", fd1, fd2);

	cnt = read(fd1, buf, 100);
	write(fd2, buf, cnt);

	close(fd1);
	close(fd2);

	return 0;
}


