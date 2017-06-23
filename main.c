#include <stdio.h>
#include "mhwdefine.h"
#include "softarray.h"
int main(int argc,char**argv)
{
    LOG("hello word");
    LOG("aa");
    softarray* mhwsa=creat_soft_array(10);
    fac(mhwsa);
    print_softarry(mhwsa);
    delet_soft_array(mhwsa);
    return 0;
}

