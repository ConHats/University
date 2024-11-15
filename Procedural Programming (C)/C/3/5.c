#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int code, gender, weight, height, age, N, i, maxage = 0, maxcode, maxweight, maxheight;
    printf("N: ");
    N = GetInteger();
    for (i=1; i<=N; i++) {
        printf("Enter code: ");
        code = GetInteger();
        printf("Enter gender(0 for male, 1 for female): ");
        gender = GetInteger();
        printf("Enter weight: ");
        weight = GetInteger();
        printf("Enter height: ");
        height = GetInteger();
        printf("Enter age: ");
        age = GetInteger();
        if (gender == 0 && maxage < age) {
            maxage = age;
            maxcode = code;
            maxweight = weight;
            maxheight = height;
        }
    }
    printf("%d_%d_%d_%d_%d", maxcode, gender, maxweight, maxheight, maxage);
    return 0;
}
