#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int m, n, gcd, r = 1, temp;
    printf("Enter the first number :");
    m = GetInteger();
    printf("Enter the second number :");
    n = GetInteger();
    if (n > m) {
        temp = n;
        n = m;
        m = temp;
    }
    if (n == 0) {
        gcd = m;
    }
    else {
        while (r != 0) {
            r = m%n;
            if (r == 0) {
                gcd = n;
            }
            else {
                m = n;
                n = r;
            }
        }
    }
    printf("The greatest common divisor is %d", gcd);
    return 0;
}
