#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    long N, c50, c20, c5, c1, yp;
    printf("Give the amount of devices: ");
    N = GetLong();
    c50 = N/50;
    yp = N%50;
    c20 = yp/20;
    yp = yp%20;
    c5 = yp/5;
    c1 = yp%5;
    printf("%ld\n%ld\n%ld\n%ld\n", c50, c20, c5, c1);
    return 0;
}
