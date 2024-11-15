#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int n, i=1, j, sum=0, x, N;
    printf("Enter number:");
    n = GetInteger();
    N = n;
    while (n/10!=0) {
        n /= 10;
        i++;
    }
    for (j=1; j<=i; j++) {
        x=N%10;
        N=N/10;
        sum=sum+x;
    }
    printf("The sum of digits is %d", sum);
    return 0;
}
