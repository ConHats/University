#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

// Function to calculate the charge based on parking hours
double calc_charge(int hours);

int main() {
    int hours;
    double charge;

    // Get the number of parking hours from the user
    printf("Enter hours of stay: ");
    hours = GetInteger();

    // Calculate charge
    charge = calc_charge(hours);

    // Print
    printf("The charge is %g euros", charge);

    return 0;
}

// Function to compute the parking charge
double calc_charge(int hours) {
    int i;
    double sum = 2;  // Initial charge for the first hour

    // Add 0.5 euros for each additional hour
    for (i = 2; i <= hours; i++) {
        sum += 0.5;
    }

    return sum;
}
