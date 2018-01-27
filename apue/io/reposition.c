

//作业：实现重定向功能

//./a.out hello > newfile

fd = open(argv[1], O_RDONLY);

if (argc > 2 && !strcmp(argv[2], ">")) {
	//重定向
	fd2 = open(argc[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);

	dup2(fd2, 1);

}


while (1) {

	read(fd, )

	write(1, );
}



