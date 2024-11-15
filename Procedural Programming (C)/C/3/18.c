#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int index=0, max=0, min=100000, sum=0, amount;
    while (sum<100000)
        {
            printf("Enter amount: ");
            amount = GetInteger();
            sum += amount;
            index += 1;
            if (max<amount)
                {
                    max = amount;
                }
            if (min>amount)
                {
                    min = amount;
                }
        }
    printf("Number of people: %d\n", index);
    printf("Total amount: %d\n", sum);
    printf("Largest amount: %d  ", max);
    printf("Smallest amount: %d", min);
    return 0;
}
