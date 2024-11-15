#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    long purchaseAmount;
    int rate;
    double profit, saleAmount;
    printf("Enter the purchase amount: ");
    purchaseAmount = GetLong();
    printf("Enter the profit percentage: ");
    rate = GetInteger();
    profit = purchaseAmount * (rate / 100.0);
    printf("The profit is: %g\n", profit);
    saleAmount = purchaseAmount + profit;
    printf("The total amount is: %g\n", saleAmount);
    return 0;
}
