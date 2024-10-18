#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int x, y, i, z;
    printf("Dose ypsos: ");
    y=GetInteger();
    printf("Dose platos: ");
    x=GetInteger();


    /*platos1*/
    for(i=0; i<x; i++)
    {
        printf("*");

    }
    printf("\n");

    /*ypsos*/
    for(i=0; i<y-2; i++)
    {
        printf("*");
        for(z=1;z<x-1;z++)
        {
            printf(" ");
        }
        printf("*\n");
    }

    /*platos2*/
    for(i=1;i<x+1;i++)
    {
        printf("*");
    }
    return 0;
}
