#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int workDays;
    long dailySalary, gift;
    double giftPercentage;
    printf("Enter the number of workdays of the year: ");
    workDays = GetInteger();
    printf("Enter the daily salary: ");
    dailySalary = GetInteger();
    printf("Enter the gift percentage: ");
    giftPercentage = GetReal();
    gift = (long)(workDays * dailySalary * giftPercentage);
    printf("The gift is: %d \n", gift);
    return 0;
}
