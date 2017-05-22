#include "softarray.h"
#include <stdlib.h>
softarray* creat_soft_array(int len)
{
    softarray *ret=NULL;
    if(len>0)
	{
	ret=malloc(sizeof(*ret)+sizeof(*(ret->array))*len);
	ret->len=len;
	}
    return ret;
}
void delet_soft_array(softarray* sa)
{
    free(sa);
}
void fac(softarray* sa)
{
    int i=0;
    if(sa->len==1)
	sa->array[0]=1;
    else if(sa->len==2)
	{
	sa->array[0]=1;
	sa->array[1]=1;
	}
    else if(sa->len>2)
	{
	sa->array[0]=1;
        sa->array[1]=1;
	for(i=2;i<sa->len;i++)
		sa->array[i]=sa->array[i-2]+sa->array[i-1];	
	}
}	
int main(int argc,char* argv[])
{
    if(argc<2)
	{
	printf("usag:./fac len!");
	return 0;
	}
    int len=0,i=0;
    softarray* sa;
    len=atoi(argv[1]);
    sa=creat_soft_array(len);
    fac(sa);
    for(i=0;i<len;i++)
	printf("%d\t",sa->array[i]);
    printf("\n");
    return 0;
}
