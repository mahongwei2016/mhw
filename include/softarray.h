#ifndef __SOFTARRAY_H__
#define __SOFTARRAY_H__
#include <stdio.h>
#include <malloc.h>
typedef struct _softarray
{
    int len;
    int array[];
}softarray;
softarray* creat_soft_array(int len);
void fac(softarray* sa);
void delet_soft_array(softarray* sa);
void print_softarry(softarray* sa);
#endif
