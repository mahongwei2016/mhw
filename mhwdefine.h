#ifndef __MHWDEFINE_H__
#define __MHWDEFINE_H__
#include <time.h>
#define DIM(A) ((sizeof(A)/(sizeof(*A))))
#define MALLOC(type,x) (type*)malloc(sizeof(type)*x)
#define log(s) printf("%s:%d %s\n",__FILE__,__LINE__,s)
#define LOG(s) do{		\
	time_t mhw_t;		\
	struct tm *mhw_ti;	\
	time(&mhw_t);		\
	mhw_ti=localtime(&mhw_t);	\
	printf("%s[%s:%d]:%s\n",asctime(mhw_ti),__FILE__,__LINE__,s);\
	}while(0)
#define mhw_buffer[100][1000];
//typedef struct __sdb{}sdb;sdb *s=mhw_buffer;   //the start addr of mhw_buffer equal s
//5
#define CONVER(X) #X
//6
#define CALL(F,P) (printf("call function %s ",#F,f(p)))


#endif
