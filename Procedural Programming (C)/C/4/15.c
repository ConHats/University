#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

// Function prototypes
int Menu(int number);
double Transactions(int choice, double Euro);

int main() {
    int choice, number;
    double Euro, Currency;

    // Display menu and get the user's choice
    choice = Menu(number);

    while (choice != 6) {  // Loop until the user chooses to exit
        // Prompt the user for an amount in euros
        printf("Enter the amount of money in euros: ");
        Euro = GetReal();

        // Convert the amount based on the chosen currency
        Currency = Transactions(choice, Euro);

        // Display the converted amount
        printf("%g\n", Currency);

        // Display the menu again for the next transaction
        choice = Menu(number);
    }

    return 0;
}

// Function to display the menu and return the user's choice
int Menu(int number) {
    printf("1. Convert to US Dollars\n");
    printf("2. Convert to British Pounds\n");
    printf("3. Convert to Swiss Francs\n");
    printf("4. Convert to Canadian Dollars\n");
    printf("5. Convert to Japanese Yen\n");
    printf("6. Exit\n");
    number = GetInteger();  // Get the user's choice
    return number;
}

// Function to perform currency conversion based on user's choice
double Transactions(int choice, double Euro) {
    if (choice == 1) {
        return (1 / 0.89) * Euro;  // Convert to US Dollars
    } else if (choice == 2) {
        return (1 / 0.618) * Euro;  // Convert to British Pounds
    } else if (choice == 3) {
        return (1 / 1.5465) * Euro;  // Convert to Swiss Francs
    } else if (choice == 4) {
        return (1 / 1.3565) * Euro;  // Convert to Canadian Dollars
    } else if (choice == 5) {
        return (1 / 109.22) * Euro;  // Convert to Japanese Yen
    } else {
        system("PAUSE");  // Pause if invalid choice
        return 0;
    }
}
