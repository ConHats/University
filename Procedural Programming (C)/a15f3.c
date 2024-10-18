#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int i, x=10;
    for(i=1; i<=100; i++)
    {
        printf( "%4d ", i);

        if(i==x)
        {
            printf("\n");
            x+=10;
        }

    }
}
