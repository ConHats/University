#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int i, sum=0;
    for (i=1; i<=20; i++)
    {
        sum=sum+i;
    }
    printf("The sum of numbers from 1 to 20 except for 5 and 15 is %d", sum-20);
    return 0;
}

