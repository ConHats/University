#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main() {
    int coffee, euro1, euro2, cents50, cents20, cents10, remainder, change;
    printf("Enter number of coffees: ");
    coffee = GetInteger();
    if (coffee < 8) {
        change = 500 - coffee * 70;  // calculate the change from 500 cents (5 EUR)
        printf("Change:\n");

        euro2 = change / 200;  // Number of 2 EUR coins
        remainder = change % 200;  // Remaining change after 2 EUR coins
        printf("2 EUR coins: %d\n", euro2);

        euro1 = remainder / 100;  // Number of 1 EUR coins
        remainder = remainder % 100;  // Remaining change after 1 EUR coins
        printf("1 EUR coins: %d\n", euro1);

        cents50 = remainder / 50;  // Number of 50 cent coins
        remainder = remainder % 50;  // Remaining change after 50 cent coins
        printf("50 cent coins: %d\n", cents50);

        cents20 = remainder / 20;  // Number of 20 cent coins
        remainder = remainder % 20;  // Remaining change after 20 cent coins
        printf("20 cent coins: %d\n", cents20);

        cents10 = remainder / 10;  // Number of 10 cent coins
        printf("10 cent coins: %d\n", cents10);
    }
    else
        printf("Not enough money for that many coffees.\n");

    return 0;
}
