#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

// Function to calculate the VAT (Value Added Tax) amount
double Calculation(double total_amount, int fpa_category);

int main() {
    int i, quantity, fpa_category;
    double price, total_amount, total_fpa, final_cost = 0, total_fpa_sum = 0;

    // Loop for 5 products
    for (i = 1; i <= 5; i++) {
        printf("Enter the quantity of product %d: ", i);
        quantity = GetInteger();
        printf("Enter the price for product %d: ", i);
        price = GetReal();
        printf("Enter the VAT category for product %d: ", i);
        fpa_category = GetInteger();

        total_amount = quantity * price;                      // Calculate total cost without VAT
        total_fpa = Calculation(total_amount, fpa_category);  // Calculate VAT for the product
        final_cost += total_amount + total_fpa;               // Accumulate the total cost including VAT
        total_fpa_sum += total_fpa;                           // Accumulate the total VAT
    }

    // Results
    printf("Total cost including fpa: %.2f\n", final_cost);
    printf("Total fpa: %.2f\n", total_fpa_sum);

    return 0;
}

// Function to calculate VAT based on the category
double Calculation(double total_amount, int fpa_category) {
    if (fpa_category == 1)
        return total_amount * 0.00;  // No VAT
    else if (fpa_category == 2)
        return total_amount * 0.06;  // 6% VAT
    else if (fpa_category == 3)
        return total_amount * 0.13;  // 13% VAT
    else if (fpa_category == 4)
        return total_amount * 0.19;  // 19% VAT
    else {
        printf("Invalid fpa category\n");
        return 0;
    }
}

