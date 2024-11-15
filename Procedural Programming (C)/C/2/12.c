#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    long weight, cost;
    int country;
    double surcharge, total;
    weight = (printf("Enter the weight: "), GetLong());
    country = (printf("Enter the country code for delivery <0, 1>: "), GetInteger());
    printf("The weight is %d\n", weight);

    // Calculate the additional cost based on weight
    if (weight >= 1 && weight < 20)
    {
        cost = weight * 15;
    }
    else if (weight >= 20 && weight < 100)
    {
        cost = 20 * 15 + (weight - 20) * 20;
    }
    else
    {
        cost = 20 * 15 + 80 * 20 + (weight - 100) * 25;
    }

    printf("The additional cost is %d\n", cost);

    // Calculate the surcharge based on country
    if (country == 0)
    {
        surcharge = (120 + cost) * 0.12;
    }
    else
    {
        surcharge = (120 + cost) * 0.15;
    }

    printf("The surcharge is %g\n", surcharge);

    // Calculate total postage
    total = surcharge + 120 + cost;
    printf("The total postage cost is %g\n", total);

    return 0;
}
