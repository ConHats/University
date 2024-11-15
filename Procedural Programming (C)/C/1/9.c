#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main ()
{
    double rate, amount, discount;
    long purchaseAmount;
    printf("Enter the price of the item: ");
    purchaseAmount = GetInteger();
    printf("Enter the discount percentage: ");
    rate = GetReal();
    discount = purchaseAmount * rate;
    amount = purchaseAmount - discount;
    printf("The payment amount is %g\n", amount);
    printf("The discount is %g", discount);
    return 0;
}
