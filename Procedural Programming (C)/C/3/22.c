#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int N, i;
    printf("Enter number : ");
    N = GetInteger();
    printf("The decreasing sequence is: ");
    for(i=N; i>=1; i--)
    {
        printf("%d,", i);
    }
    printf("0");
    return 0;
}
