#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int age, max = 0, min = 100;
    printf("Enter age: ");
    age = GetInteger();
    while (age != -1) {
        if (max < age) {
            max = age;
        }
        if (min > age) {
            min = age;
        }
        printf("Enter age: ");
        age = GetInteger();
    }
    printf("The oldest age is %d\n", max);
    printf("The youngest age is %d", min);
    return 0;
}
