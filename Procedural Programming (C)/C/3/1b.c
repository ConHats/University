#include <stdio.h>
#include "simpio.h"
#include <math.h>

main(){
    long count_of_Cars, Limit, Eth=0, Sum_of_Cars;
    double rate;
    printf("Enter the initial number of cars: ");
    count_of_Cars = GetLong();
    printf("Enter the yearly rate of increase: ");
    rate = GetReal();
    printf("Enter the limit: ");
    Limit = GetLong();
    Sum_of_Cars = count_of_Cars;
    while(Sum_of_Cars<=Limit)
        {
            Sum_of_Cars = ceil(Sum_of_Cars*(1+rate));
            Eth++;
        }
    printf("%ld\n%ld\n", Eth, Sum_of_Cars);
    return 0;
}
