#ifndef __MHWLIST_H__
#define __MHWLIST_H__
struct list_head{
    struct list_head *next,*prev;
};
#define LIST_HEAD_INIT(name) {&(name),&(name)}
#define LIST_HEAD(name) \
	struct list_head name= LIST_HEAD_INIT(name)
#define mhwoffsetof(TYPE,MEMBER) ((char *)&((TYPE*)0)->MEMBER)
#define container_off(ptr,type,member) ({\
	const typeof(((type *)0)->member) * __mptr = (ptr);\
	(type *)((char *)__mptr-mhwoffsetof(type,member));})
#define list_entry(ptr,type,member)\
	container_off(ptr,type,member)
#define list_first_entry(ptr,type,member)\
	list_entry(ptr->next,type,member)
#define list_for_each(pos,head)\
	for(pos=(head)->next;prefetch(pos->next),pos!=(head);\
		pos=pos->next)
#define __list_for_each(pos,head)\
	for(pos=(head)->next;pos!=head;pos=pos->next)
#define list_for_each_safe(pos,n,head)\
	for(pos=(head)->next,n=pos->next;pos!=(head);pos=n,n=pos->next)
void INIT_LIST_HEAD(struct list_head *list)
{
    list->next=list;
    list->prev=list;
}
void __list_add(struct list_head *new,struct list_head *prev,struct list_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}
void list_add(struct list_head *new,struct list_head *head)
{
    __list_add(new,head,head->next);
}
void list_add_tail(struct list_head *new,struct list_head *head)
{
    __list_add(new,head->prev,head);
}
void __list_del(struct list_head *prev,struct list_head *next)
{
    next->prev = prev;
    prev->next = next;
}
void list_del(struct list_head *entry)
{
    __list_del(entry->prev,entry->next);
    entry->prev=(void *)0xDEADBEEF;
    entry->next=(void *)0xBEEFDEAD;
}
void list_replace(struct list_head *old,struct list_head *new)
{
    new->next=old->next;
    new->next->prev=new;
    new->prev=old->prev;
    new->prev->next=new;
}
void list_replace_init(struct list_head *old,struct list_head *new)
{
	list_replace(old,new);
	INIT_LIST_HEAD(old);
}
void list_del_init(struct list_head *entry)
{
	__list_del(entry->prev,entry->next);
	INIT_LIST_HEAD(entry);
}
void list_move(struct list_head *list,struct list_head *head)
{
	__list_del(list->prev,list->next);
	list_add(list,head);
}
void list_move_tail(struct list_head *list,struct list_head *head)
{
	__list_del(list->prev,list->next);
	list_add_tail(list,head);
}
int list_is_last(const struct list_head *list,const struct list_head *head)
{
	return list->next==head;
}
int list_empty(const struct list_head *head)
{
	return head->next==head;
}
int list_empty_careful(const struct list_head *list,const struct list_head *head)
{
	struct list_head *next=head->next;
	return (next==head)&&(next==head->prev);
}
void list_rotate_left(struct list_head *head)
{
	struct list_head *first;
	if(!list_empty(head))
	{
		first=head->next;
		list_move_tail(first,head);	
	}
}

#endif
