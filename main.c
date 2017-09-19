#include <stdio.h>
#include "mhwdefine.h"
#include "softarray.h"
#include "mhwlist.h"
int f2c(unsigned char i)
{
	return (int)(i*i);
}
void define_test(void)
{
	//1
	{
		int buffer[100]={0};
		printf("buffer length:%d\n",DIM(buffer));	
	}
	//2
	{
		char *buffer=MALLOC(int,100);
		printf("buffer length:%d\n",DIM(buffer));	
	}
	//3
	{
		log("mhw");	
	}
	//4
	{
		LOG("mhw");	
	}
	{
		int buffer[1000]={1,2,3,4};
		typedef struct _sbd{
			int a;
			int b;
			int c;
		}sbd;
		sbd* sbd_p=buffer;
		printf_var(sbd_p->c);
	}
	//5
	{
		printf("%s\n",CONVER(mhw));	
	}
	//6
	{
		CALL(f2c,5);	
	}
	//7
	STRUCT(student);
	student mhw; 
	mhw.name="mhw";
	mhw.age=100;
	printf("%s\t",mhw.name);
	printf("%d\n",mhw.age);
	//8
	printf_function();
	//9
	int a=100;
	printf_var(a);
}
int main(int argc,char**argv)
{
    LOG("hello word");
    LOG("aa");
    softarray* mhwsa=creat_soft_array(10);
    fac(mhwsa);
    print_softarry(mhwsa);
    delet_soft_array(mhwsa);
    {
		struct list_head h;
		struct list_head *head=&h,*pos,*n;
		struct student{
			int num;
			int score;
			struct list_head l;
		};
		struct student a,b,c,*temp;
		INIT_LIST_HEAD(head);
		a.num=1;
		a.score=100;
		list_add_tail(&a.l,head);
		b.num=2;
		b.score=50;
		list_add_tail(&b.l,head);
		c.num=3;
		c.score=10;
		list_add_tail(&c.l,head);
		list_for_each_safe(pos,n,head)
		{
			temp=list_entry(pos,struct student,l);
			printf("num:%d\t,score%d\t",temp->num,temp->score);
		}
		printf("\n");		
    }
    define_test();
    return 0;
}

