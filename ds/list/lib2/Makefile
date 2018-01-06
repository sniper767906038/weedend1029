
#变量CFLAGS makefile文件自动读变量
CFLAGS+=-I.
#LDFLAGS += -lmath 链接动态库名

#定义变量
SRC=main.o 
SRC+=list.o

list:$(SRC)
	@gcc -o $@ $^ 
#$@取目标  $^依赖文件

clean:
	@rm *.o list	


