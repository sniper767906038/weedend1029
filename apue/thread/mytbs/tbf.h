
#ifndef __TBF_H
#define __TBF_H

#define MAXTBF 1024

/*
 初始化令牌桶
 返回的桶描述符
 */
int tbf_init(int cps, int burst);

/*
 取令牌
tf:描述符
 */
int tbf_fetch(int tf, int n);

//还令牌
int tbf_return(int tf, int n);

void tbf_destroy(int tf);

#endif

