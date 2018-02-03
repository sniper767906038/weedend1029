#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <getopt.h>

int main(int argc, char **argv)
{
	int c;
	int fd = -1;
	struct option opts[4] = {
		{"help", no_argument, NULL, 'h'},
		{"list", optional_argument, NULL, 'i'},
		{"save", required_argument, NULL, 'v'},
		{0, 0, 0, 0}
	};
	int longdex;
	//-s -l -a arg -m  --help --list --save

	while (1) {
		//c = getopt(argc, argv, "-sla:m");
		c = getopt_long(argc, argv, "-sla:m", opts, &longdex);
		if (c == -1)
			break;
		switch (c) {
			case 's':
				printf("-s 抓到你了\n");
				break;
			case 'm':
				printf("-m 哪里跑\n");	
				break;
			case 'l':
				printf("-l 快到碗里来\n");
				break;
			case 'a':
				printf("-a 参数来了\n");
				printf("arg:%s\n", optarg);
				break;
			case 1:
				printf("这家伙不是选项吧\n");
				printf("%s\n", argv[optind-1]);
				break;
			case 'h':
				printf("help me....\n");
				break;
			case 'i':
				printf("list all\n");
				if (optarg != NULL) {
					printf("list argument: %s\n", optarg);
				}
				break;
			case 'v':
				//--save hello
				printf("save all! are you sure?\n");	
				fd = open(optarg, O_WRONLY | O_CREAT | O_TRUNC, 0666);
				if (fd < 0) {
					perror("open()");
					goto ERROR;
				}
				dup2(fd, 1);
				break;
			default:
				printf("c:%c\n", c);
				printf("不认识你\n");
				break;	
		}
	}

	if (fd >= 0)
		close(fd);

	return 0;
ERROR:
	return 1;
}

