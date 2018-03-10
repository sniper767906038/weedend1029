#include <stdio.h>
#include <stdlib.h>
#include <shadow.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char name[128] = {};
	struct spwd *p;
	char *gp;
	char *encryp;

	printf("用户名:");
	fgets(name, 128, stdin);
	name[strlen(name)-1] = 0;

	gp = getpass("密码:");

	p = getspnam(name);
	//name用户加密后的密码p->sp_pwdp


	//将输入的密码加密
	encryp = crypt(gp, p->sp_pwdp);

	if (!strcmp(p->sp_pwdp/*real passwd*/, encryp))
		printf("密码正确\n");
	else
		printf("鉴定错误\n");


	exit(0);
}

