#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    long weight, postage_cost;
    weight = (printf("Enter the weight: "), GetLong());
    {
        if (weight > 0 && weight <= 20)
            postage_cost = 250;
        else if (weight > 20 && weight <= 200)
            postage_cost = 600;
        else
            postage_cost = weight * 4;
    }
    printf("The postage cost is %ld", postage_cost);
    return 0;
}
