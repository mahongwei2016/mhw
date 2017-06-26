#include <stdio.h>
#include "mhwdefine.h"
#include "softarray.h"
#include "mhwlist.h"
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
				
    }
    
    return 0;
}

