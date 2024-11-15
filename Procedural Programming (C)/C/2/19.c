#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    float traffic_fee;
    int grams;
    printf("Enter grams of CO2/km: ");
    grams = GetInteger();
    if (grams >= 0 && grams <= 120)
    {
        traffic_fee = grams * 0.9;
    }
    else if (grams >= 121 && grams <= 140)
    {
        traffic_fee = grams * 1.1;
    }
    else
    {
        traffic_fee = grams * 1.7;
    }
    printf("The payment amount is: %g", traffic_fee);
    return 0;
}
