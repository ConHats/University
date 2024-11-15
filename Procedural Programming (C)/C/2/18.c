#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    double miles, liters;
    miles = (printf("Enter miles: "), GetReal());
    liters = (printf("Enter liters: "), GetReal());
    {
        if (liters/miles >= 0 && liters/miles < 0.9)
            {
                printf("Very low");
            }
        else if (liters/miles >= 0.9 && liters/miles < 1.2)
            {
                printf("Low");
            }
        else if (liters/miles >= 1.2 && liters/miles < 1.8)
            {
                printf("Normal");
            }
        else
            {
                printf("High");
            }
    }
    return 0;
}
