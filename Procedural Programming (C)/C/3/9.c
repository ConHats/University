#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int grade, sum=0, i=0;
    double avarage;
    printf("Enter grade: ");
    grade = GetInteger();
    while (grade!=-1) {
        sum+=grade;
        i++;
        printf("enter grade: ");
        grade = GetInteger();
    }
    printf("%d\n", i);
    printf("%d\n", sum);
    avarage=(double)sum/i;
    printf("%g\n", avarage);
    return 0;
}
