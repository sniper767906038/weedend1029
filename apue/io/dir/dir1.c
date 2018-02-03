#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

//argv[1]
int main(int argc, char **argv)
{
	DIR *dp = NULL;
	struct dirent *dir = NULL;

	if (argc < 2)	
		return 1;

	dp = opendir(argv[1]);
	if (NULL == dp) {
		perror("opendir()");
		return 1;
	}

	while (1) {
		errno = 0;
		dir = readdir(dp);
		if (NULL == dir) {
			//error or end
			if (errno) {
				perror("readdir()");
				goto ERROR;
			}
			break;//end
		}
		//succeffully	
		printf("%s\n", dir->d_name);
	}

	closedir(dp);

	return 0;
ERROR:
	closedir(dp);
	return 1;
}

