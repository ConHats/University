#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int positions, passengers;
    positions = (printf("Enter the number of positions: "), GetInteger());
    passengers = (printf("Enter the number of passengers: "), GetInteger());

    // Check if profit, loss, or cost based on passenger count and available positions
    if (positions * 0.5 <= passengers)
    {
        printf("Profit");
    }
    else if (positions * 0.3 >= passengers)
    {
        printf("Loss");
    }
    else
    {
        printf("Cost");
    }

    return 0;
}
