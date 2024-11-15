#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main ()
{
    long price_per_package, number_of_package;
    double vat, cost;
    printf("Enter the price per package: ");
    price_per_package = GetInteger();
    printf("Enter the VAT percentage: ");
    vat = GetReal();
    printf("Enter the number of package: ");
    number_of_package = GetInteger();
    cost = (price_per_package * number_of_package) + price_per_package * number_of_package * vat;
    printf("The total cost of the order is %g\n", cost);
    return 0;
}
