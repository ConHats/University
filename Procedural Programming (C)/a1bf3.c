#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    long total, years=0, orio;
    double pososto;

    printf("Dwse ton arxiko arithmo autokinhtwn: ");
    total=GetInteger();

    printf("Dwse ton ethsio rythmo ayxhshs: ");
    pososto=GetReal();

    printf("Dwse to orio: ");
    orio=GetInteger();

    while (TRUE)
    {

        if(total>orio)break;
        total=ceil(total*(1+pososto));
        years++;

    }

    printf("%ld\n%ld",years,total);
    return 0;
}
