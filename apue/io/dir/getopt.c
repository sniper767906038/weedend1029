#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int c;
	//-s -l -a arg -m 

	while (1) {
		c = getopt(argc, argv, "-sla:m");
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
			default:
				printf("c:%c\n", c);
				printf("不认识你\n");
				break;	
		}
	}

	return 0;
ERROR:
	return 1;
}

