#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

void printpolywnymo(int A[10], int degree);

void CalculatingSum(int A[10],int B[10],int SUM[10],int degree);

double Value(int degree, int A[10], double x);
double SumValue(int degree, int A[10], double x);

int main()
{
    int degree,coefficientsA[10],coefficientsB[10],coefficientsSum[10];
    double x;

    printf("Ti vathmo exoyn ta polywnyma?\n");
    degree = GetInteger();

    printpolywnymo(coefficientsA, degree);
    printpolywnymo(coefficientsB, degree);

    CalculatingSum(coefficientsA,coefficientsB,coefficientsSum,degree);

    printf("Dwse mia timi gia to x: ");
    x = GetReal();

    printf("Value1: %g  Value2: %g  Value of Sum: %g",Value(degree,coefficientsA,x),Value(degree,coefficientsB,x), SumValue(degree,coefficientsSum,x));
}


void printpolywnymo(int A[10],int degree)
{
    int i;

    //Ανάγνωση συντελεστών πολυωνύμου
    for(i=0; i<=degree; i++) {
        printf("Eisagete to syntelesti tou orou %d: ", i);
        A[i] = GetInteger();
    }

    //Εκτύπωση πολυωνύμου
    i=degree;
    while(i>=1) {
        printf("%dx^%d + ", A[i], i);
        i--;
    }
    printf("%d\n", A[0]);
}

void CalculatingSum(int A[10],int B[10],int SUM[10], int degree)
{
    int i;
    //πρόσθεση πολυωνύμων
    for(i=0; i<=degree; i++) {
        SUM[i] = A[i] + B[i];
    }

    //Εκτύπωση αθροίσματος
    while(degree>=1) {
        printf("%dx^%d + ", SUM[degree], degree);
        degree--;
    }
    printf("%d\n", SUM[0]);
}

double Value(int degree, int A[10], double x)
{
    int i;
    double value = 0;
    for(i=0; i<=degree; i++)
    {
        value += A[i]*pow(x, (double)i);
    }
    return value;
}

double SumValue(int degree, int A[10], double x)
{
    int i;
    double valueSum = 0;
    for(i=0; i<=degree; i++)
    {
        valueSum += A[i]*pow(x,(double)i);
    }
    return valueSum;
}
