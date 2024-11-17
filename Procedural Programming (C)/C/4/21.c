#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

double calculation_bmi(double height, double weight);
void results(double bmi);

int main(){
    double height, weight, bmi;
    printf("Enter height :");
    height = GetReal();
    printf("Enter weight :");
    weight = GetReal();
    while(height!=0 && weight!=0)
        {
            bmi = calculation_bmi(height,weight);
            results(bmi);
            printf("Enter height :");
            height = GetReal();
            printf("Enter weight :");
            weight = GetReal();
        }
    return 0;
}

double calculation_bmi(double height, double weight){
    double calc;
    calc = weight/(height*height);
    return calc;
}

void results(double bmi){
    if (bmi<18.5)
        printf("Underweight\n");
    else if (bmi>=18.5 && bmi<25)
        printf("Normal weight\n");
    else if (bmi>=25 && bmi<30)
        printf("Overweight\n");
    else
        printf("Obese\n");
}
