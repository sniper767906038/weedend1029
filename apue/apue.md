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

密码存在哪----》/etc/shadow 

获取加密密码--->getspnam(3)

以root身份

getpass(3)

crypt(3)



主要章节:7,8,9,13,10,15

##进程环境

###main

### 进程终止

####正常终止方式

   	1. main()使用return语句
  2. exit(3) 
  3. _exit(2) / _Exit(2)
  4. 最后一个线程从启动例程返回
  5. 最后一个线程调用了pthread_exit(3)

#### 异常终止方式

1.  调用abort()
2.  信号
3.  最后一个线程对取消做出响应

终止处理程序注册函数atexit(3)

### 命令行参数/环境表/环境变量

### ｃ存储空间布局/共享库/堆开辟

### setjmp() / longjmp()

##进程控制

### 进程

1.   进程的状态变迁

    准备　	就绪		运行

    ps

    ​	ps aux	

    ​		USER PID STAT CMD

    ​	ps axj

    ​		PPID PID PGID SID

    ​	ps axm -L

    ​		LWP-->线程

    ​	ps ef

    进程标识:PID 

    ​			0	调度进程（内核）

    ​			1	init（用户态祖先）

    获取进程标识

    ​	getpid(2)

    ​	getppid(2)

2.  进程关系

    会话－－－－》进程组－－－－》进程－－－－》线程

### fork(2)

1.  在父进程中返回子进程pid, 子进程中返回0

2.  当fork()调用成功，此代码将相当于有两份同时允许，没有先后顺序

3.  如果子进程等待父进程结束－－－－》是子进程称为孤儿进程

    ​	while (getppid() != 1349)

    ​		sleep(1);

4.  父进程为子进程收尸 wait(2)

当进程创建成功那一刻,父子进程之间的关系

1.  子进程进程表项在创建成功的时候是复制父进程的
2.  虚拟地址空间也会复制－－－》写时复制

fork()实际应用中两点：

1.  网络服务:创建子进程运行不同的代码
2.  shell,创建子进程运行不同的进程

### wait(2)

​	为任意子进程收尸，获取到收尸子进程的ｐｉｄ以及终止状态

终止状态用WEXITSTATUS(status)获得

### waitpid(2)

The value of pid can be:

```ｃ
   < -1   meaning wait for any child process whose  process  group  ID  is
          equal to the absolute value of pid.

   -1     meaning wait for any child process.

   0      meaning  wait  for  any  child process whose process group ID is
          equal to that of the calling process.

   > 0    meaning wait for the child whose process  ID  is  equal  to  the
          value of pid.
```
###exec(3)

​	execl(3)/execlp()/execv()/execvp()/execle()

## 进程关系

会话：

​	打开一个终端，在创建一个会话

在会话中至少有一个进程组

进程组内至少有一个进程

进程内至少有一个线程

### 进程组

​	getpgid(pid)

​	getpgid(0) == getpgrp()

​	setpgid(pid, pgid)	

### 会话

​	getsid(2);

​	setsid(2)

### 守护进程

1.  意义
2.  创建

## 进程间通信

### 同一台主机	

1.  信号

    初步异步(不可预测)	

    *   初步认识信号

        ​	man 7 signal

        　信号的分类

        ​		kill -l

        ​		reliable signals (standard signals)

        ​			1~31			默认行为的　丢失的

        ​			标准信号的默认行为（决定了接受到此信号进程的行为）

        ​			 Term   Default action is to terminate the process.	

        ```
            Ign    Default action is to ignore the signal.
         	Core   Default action is to terminate the process and  dump  core  (see
                  core(5)).

           Stop   Default action is to stop the process.

           Cont   Default  action  is  to  continue the process if it is currently
                  stopped.
        ```

        ​		

        ​		real-time signals

        ​			34~64		没有默认行为，排队

        ​

    *   signal(2) 

        *   The signals SIGKILL and SIGSTOP cannot be caught, blocked, or ignored

    *   信号的属性特点

        *   信号会打断阻塞的系统调用
        *   信号会丢失（因为响应信号的结构是用位图维护的）
        *   在执行一个信号的信号处理函数期间不会再响应此信号
        *   在信号处理函数内不允许用longjmp()跳转
        *   signal(signum, SIG_IGN)实质就是将信号ｍａｓｋ位图置1

    *   信号的发送和接收

        ​	kill(2) / raise(2)

        ​	pause(2)

        ​	alarm(2)

    *   信号集

    *   设置信号屏蔽字

        ​	sigprocmask(2)

    *   sigaction(2)

2.  管道

3.  ＸＳＩ(sysV)

    *   消息队列
    *   共享内存
    *   信号量数组

练习题：

1.  调用进程创建一个子进程，子进程将argv[1]文件的内容写入argv[2]

argv[2]文件中要求第二行插入一个字符串"我们是最棒的",此字符串必须是父进程写入的

2.   man 2 alarm

​	利用SIGARLM信号实现将argv[1]文件1s向标准输出写10个字节(不许用sleep函数)

复习:

1.  查找并理解什么是同步？什么是异步?	什么是并发

 2.  进程终止的方式　

 3.  wait()和waitpid(2)区别和联系

 4.  man 2 vfork()　总结与fork()差别

 5.  当新创建一个进程的时候，父子进程间有什么区别

     ​

### 跨主机

​	套接字

## 多线程

##网络编程













