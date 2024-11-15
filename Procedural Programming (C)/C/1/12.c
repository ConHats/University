#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main ()
{
    int cleanArea, mixedArea;
    double municipalTax, municipalFee;
    printf("Enter the clean area of the house (in square meters): ");
    cleanArea = GetInteger();
    printf("Enter the mixed area of the house (in square meters): ");
    mixedArea = GetInteger();
    municipalTax = cleanArea * 1.33 * 61 / 365;
    municipalFee = mixedArea * 0.13 * 61 / 365;
    printf("The municipal tax is: %.2f\n", municipalTax);
    printf("The municipal fee is: %.2f\n", municipalFee);
    return 0;
}
