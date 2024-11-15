#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

main(){
    int code, people;
    long total, outcome, sum = 0;
    printf("Enter password: ");
    code = GetInteger();
    while (code != 1 && code != 2) {
        printf("Wrong password.\n");
        printf("Enter password: ");
        code = GetInteger();
    }
    while (code==1) {
        printf("Enter the number of people: ");
        people = GetInteger();
        if (people <= 10) {
            total = people * 350;
        }
        else{
            total = ceil(people * 350 - (people * 0.1 * 350));
        }
        sum += total;
        printf("Price of vacancy: %ld\n", total);
        printf("Enter password: ");
        code = GetInteger();
        while (code != 1 && code != 2) {
            printf("Wrong password.\n");
            printf("Enter password: ");
            code = GetInteger();
        }
    }
    if (code==2) {
        outcome = sum - 20000;
        printf("Profit or loss (-) for the trip: %ld", outcome);
    }
    return 0;
}
