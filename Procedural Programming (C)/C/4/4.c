#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

long Calculate(long Principal, double InterestRate, int Years);

int main(){
    long Principal, total;
    double InterestRate;
    int Years;
    printf("Enter the principal: ");
    Principal = GetLong();
    printf("Enter the interest rate: ");
    InterestRate = GetReal();
    printf("Enter the years: ");
    Years = GetInteger();
    total = Calculate(Principal, InterestRate, Years);
    printf("%ld", total);
    return 0;
}

long Calculate(long Principal, double InterestRate, int Years){
    long totalAmount;
    totalAmount = ceil(Principal * (1 + InterestRate * Years));
    return totalAmount;
}
