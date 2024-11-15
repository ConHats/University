#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main() {

    int degree;
    int coefficientsA[10], coefficientsB[10], coefficientsSum[10];
    int i;
    double x, value1, value2, valueSum;

    // Reading the degree of polynomials.
    printf("Polynomials grade: \n");
    degree = GetInteger();


    //Reading the coefficients of the first polynomial.
    for(i=0; i<=degree; i++) {
        printf("Coefficient of the %dth term: ", i);
        coefficientsA[i] = GetInteger();
    }

    //Print of first polynomial
    i=degree;
    while(i>=1) {
        printf("%dx^%d + ", coefficientsA[i], i);
        i--;
    }
    printf("%d\n", coefficientsA[0]);

    //Reading the coefficients of the second polynomial.
    for(i=0; i<=degree; i++) {
        printf("Coefficient of the %dth term: ", i);
        coefficientsB[i] = GetInteger();
    }

    //Print the 2nd polynomial
    i=degree;
    while(i>=1) {
        printf("%dx^%d + ", coefficientsB[i], i);
        i--;
    }
    printf("%d\n", coefficientsB[0]);

    //Adding polynomials
    for(i=0; i<=degree; i++) {
        coefficientsSum[i] = coefficientsA[i] + coefficientsB[i];
    }

    //Print of sum
    i=degree;
    while(i>=1) {
        printf("%dx^%d + ", coefficientsSum[i], i);
        i--;
    }
    printf("%d\n", coefficientsSum[0]);


    printf("Give x's value: ");
    x = GetReal();


    //Printing of polynomial values
    value1 = 0;
    for(i=0; i<=degree; i++)
        value1 += coefficientsA[i]*pow(x, (double)i);

    value2 = 0;
    for(i=0; i<=degree; i++)
        value2 += coefficientsB[i]*pow(x, (double)i);

    valueSum = 0;
    for(i=0; i<=degree; i++)
        valueSum += coefficientsSum[i]*pow(x, (double)i);

    printf("Value1: %g  Value2: %g  Value of Sum: %g", value1, value2, valueSum);

    return 0;
}
