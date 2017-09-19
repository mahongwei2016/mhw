#ifndef __MHWDEFINE_H__
#define __MHWDEFINE_H__
#include <time.h>
//1
#define DIM(A) ((sizeof(A)/(sizeof(*A))))
//2
#define MALLOC(type,x) (type*)malloc(sizeof(type)*x)
//3
#define log(s) printf("%s:%d %s\n",__FILE__,__LINE__,s)
#define LOG(s) do{		\
	time_t mhw_t;		\
	struct tm *mhw_ti;	\
	time(&mhw_t);		\
	mhw_ti=localtime(&mhw_t);	\
	printf("%s[%s:%d]:%s\n",asctime(mhw_ti),__FILE__,__LINE__,s);\
	}while(0)
//4
#define mhw_buffer [100][1000];
//typedef struct __sdb{}sdb;sdb *s=mhw_buffer;   //the start addr of mhw_buffer equal s
//5
#define CONVER(X) #X
//6
#define CALL(F,p) (printf("call function %s(%d):%d\n",#F,p,F(p)))
//7
#define STRUCT(type) typedef struct _mhw_##type type;struct _mhw_##type {char *name;int age;};
//8
#define printf_function
#ifdef printf_function
#define printf_function(); printf("%s begin\n",__FUNCTION__);
#else
#define printf_function(); 
#endif
//9
#define printf_var(s) printf("%s:%d\n",#s,s)
#endif
