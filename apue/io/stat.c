#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char *argv[])
{
	struct stat res;

	if (argc < 2)
		return 1;

	//获取argv[1]文件的属性
	stat(argv[1], &res);

	// 获取文件的类型
	switch ((res.st_mode & S_IFMT)) {
		case S_IFREG:
			printf("-");
			break;
		case S_IFDIR:
			printf("d");
			break;
		default:
			break;
	}
	
	//文件权限
	if (res.st_mode & S_IRUSR)
		putchar('r');
	else
		putchar('-');
	if (res.st_mode & S_IWUSR)
		putchar('w');
	else
		putchar('-');
	if (res.st_mode & S_IXUSR)
		putchar('x');
	else
		putchar('-');

	//文件硬链接个数
	printf(" %ld ", res.st_nlink);

	//获取文件拥有者
	struct passwd *userp = NULL;

	userp = getpwuid(res.st_uid);
	if (NULL == userp) {
		perror("getpwuid()");
		return 1;
	}
	printf("%s ", userp->pw_name);

	//组
	struct group *groupp = NULL;

	groupp = getgrgid(res.st_gid);
	//if error
	printf("%s ", groupp->gr_name);

	//获取文件的字节个数
	printf("%ld ", res.st_size);

	//获取文件的mtime
	struct tm *tmp = NULL;
	char timebuf[100] = {};

	tmp = localtime(&res.st_mtim.tv_sec);
	strftime(timebuf, 100, "%m月  %d %H:%M", tmp);
	printf("%s ", timebuf);

	printf("%s\n", argv[1]);

		

	return 0;
}

