#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int N;
    float sum = 0, i;
    printf("Enter the limit:");
    N = GetInteger();
    for (i = 1; i <= N; i++) {
        sum = sum + (1/i);
    }
    printf("The sum is %.2f", sum);
    return 0;
}
