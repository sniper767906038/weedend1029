#　第四章

##　文件和目录

1. ####stat(2)----->const char *pathname

   ####fstat(2)---->int fd

   ####lstat(2)---->符号链接文件，获取的是符号链接文件本身的属性信息

2. ### 读目录

   **opendir(3)**

   **readdir(3)**

   **closedir(3)**

   **glob(3)**

   ​	找与给定pattern匹配的路径

   ​	用途:

   ​		**解析目录**

   ​		**存储多个字符串**

   ​	作业:

   ​		实现du -sh命令

   ​	与标准opendir(3)/readdir(3)/closedir(3)读取目录不同:

   ​		glob默认不读隐藏文件

   ​		glob读取目录得到的是路径，而open....得到是文件名

   **getopt(3)**

   ​	读取可执行程序的参数和选项

   ​	int getopt(int argc, char *argv[], const char *optstring);

   ​	argc和argv就是main函数的参数

   ​	optstring:

   ​		包含所有的选项字符

   ​		如果'-'开头，标识可识别分选项参数

   ​			

   # 第五章

   ## 标准ｉｏ

   #### 1. FILE

   ​	结构体类型：文件描述符，缓存区地址，缓存区大小，出错标识

   ​	fopen(3)---->得到FILE地址,标识打开的文件

   #### 2.缓冲

   ​	为什么?

   ​		合并系统调用（减少程序运行期间用户态向内核态切换的次数）

   ​	缓冲方式

   ​		行缓：标准输入(stdin)	标准输出(stdout)

   ​		全缓冲

   ​		无缓冲:标准错误输出(stderr)

   ​	强制刷新输出缓冲区:

   ​		fflush(3)

   #### 3.io 函数

   	#### 	按字节读写	

   ​		fgetc(3) / fputc(3)

   ​		getchar(3) / putchar(3)

   	#### 	按行读写

   ​		fgets(3) / fputs(3)

   ​		getline(3)

   ​		作业练习:

   ​			实现getline(3)函数

   	#### 	按结构读写

   ​		fread(3)  / fwrite(3)

   #### 	格式化读写

   ​		fscanf(3) / fprintf(3) 	

   	#### 	区分读文件是读到结束了还是出错了

   ​		feof(3);

   ​		ferror(3);

   ####	改变文件偏移量

   ​		fseek(3);

   ​		ftell(3);

   ​		rewind(3);

   ####4.临时文件

   ​	The file will be automatically deleted when it is closed or the program terminated

   ​	tmpfile(3)	

   ####5.比较文件ｉｏ　和　标准ｉｏ

   |    文件ｉｏ    |                  标准ｉｏ                  |
   | :--------: | :------------------------------------: |
   |    系统调用    |                   库                    |
   | 打开open(2)  |                fopen(3)                |
   |  read(2)   |       fgetc(3)/fgets(3)/fread(3)       |
   |  write(2)  | fputc(3)/fputs(3)/fwrite(3)/fprintf(3) |
   |  lseek(2)  |      fseek(3)/ftell(3)/rewind(3)       |
   |  close(2)  |               fclose(3)                |
   |    无缓存     |                  有缓存                   |
   | 用户态--->内核态 |                 合并系统调用                 |

   fd---->FILE *

   ​	fdopen(3)

   FILE *----->fd

   ​	fileno(3)

# 并发－－－>多进程

补充：密码校验过程















