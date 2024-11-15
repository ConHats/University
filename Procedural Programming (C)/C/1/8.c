#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main ()
{
    long domestic_mail, international_mail;
    double shipping_cost;
    printf("Enter the number of domestic mail items: ");
    domestic_mail = GetInteger();
    printf("Enter the number of international mail items: ");
    international_mail = GetInteger();
    shipping_cost = domestic_mail * 0.3 + international_mail * 0.8;
    printf("The total shipping cost is %g\n", shipping_cost);
    return 0;
}
