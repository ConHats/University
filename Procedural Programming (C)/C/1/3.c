#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int household_appliances, container50, container20, container5, remaining;
    printf("Enter the number of appliances: ");
    household_appliances = GetInteger();
    container50 =  household_appliances / 50;
    remaining = household_appliances % 50;
    container20 = remaining / 20;
    remaining = remaining % 20;
    container5 = remaining / 5;
    remaining = remaining % 5;
    printf("50: %d \n", container50);
    printf("20: %d \n", container20);
    printf("5: %d \n", container5);
    printf("1: %d \n", remaining);
    return 0;
}
