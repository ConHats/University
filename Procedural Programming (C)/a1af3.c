#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    long total=80000, years=0;
    while (TRUE)
    {
        if(total>160000)break;
        total=ceil(total*(1+0.07));
        years++;
    }

    printf("%ld\n%ld",years,total);
    return 0;
}
