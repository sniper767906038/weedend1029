
# 依赖关系
#list目标 main.o list.o依赖文件
list:main.o list.o
	#规则
	@gcc -o list main.o list.o

# test伪目标 没有依赖文件
test:
	ls -l

clean:
	@rm *.o list	
