#include <stdio.h>
#include "simpio.h"
#include <math.h>

main(){
    long years, total, tour, limit;
    double rate;
    printf("Enter the current tourist transaction: ");
    tour = GetLong();
    printf("Enter the rate of decrease: ");
    rate = GetReal();
    printf("Dwse the limit: ");
    limit = GetLong();
    total = tour;
    years = 0;
    while (total>=limit)
    {
        total = ceil(total*(1-rate));
        years++;
    }
    printf("%ld\n%ld\n", years, total);
    return 0;
}
