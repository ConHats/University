#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    long FPA004, FPA008, FPA018;
    double total;
    printf("Enter the total revenue for FPA 0.04: ");
    FPA004 = GetInteger();
    printf("Enter the total revenue for FPA 0.08: ");
    FPA008 = GetInteger();
    printf("Enter the total revenue for FPA 0.18: ");
    FPA018 = GetInteger();
    total = (FPA004 * 0.04) + (FPA008 * 0.08) + (FPA018 * 0.18);
    printf("The total FPA amount is: %g \n", total);
    return 0;
}
