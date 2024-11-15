#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main ()
{
    int gradeA, gradeB, gradeC, average;
    printf("Give grade for A semester? ");
    gradeA = GetInteger();
    printf("Give grade for B semester? ");
    gradeB = GetInteger();
    printf("Give grade for C semester? ");
    gradeC = GetInteger();
    average = (gradeA + gradeB + gradeC) / 3;
    printf("The average grade of the student is: %d\n", average);
    return 0;
}
