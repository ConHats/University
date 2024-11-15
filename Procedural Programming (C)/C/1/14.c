#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int weight, height, age;
    double bmr;
    printf("Enter weight in kilograms: ");
    weight = GetInteger();
    printf("Enter height in centimeters: ");
    height = GetInteger();
    printf("Enter age in years: ");
    age = GetInteger();
    bmr = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);
    printf("The BMR is: %g\n", bmr);
    return 0;
}
