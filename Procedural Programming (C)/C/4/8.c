#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

// Function to calculate the Greatest Common Divisor (GCD)
int GCD(int x, int y);
// Function to calculate the Least Common Multiple (LCM)
int LCM(int x, int y);

int main() {
    int x, y, gcd, lcm;
    // Input two numbers
    x = GetInteger();
    y = GetInteger();
    // Compute GCD and LCM
    gcd = GCD(x, y);
    lcm = LCM(x, y);
    // Output GCD and LCM
    printf("%d %d", gcd, lcm);
    return 0;
}

int GCD(int x, int y) {
    int a = x, b = y;
    if (a == 0 && b != 0) {
        return b; // GCD is b when a is 0
    } else if (a != 0 && b == 0) {
        return a; // GCD is a when b is 0
    } else if (a > b) {
        return GCD(a - b, b); // Recursive call
    } else if (a < b) {
        return GCD(b - a, a); // Recursive call
    }
}

int LCM(int x, int y) {
    int a = x, b = y;
    return (a / GCD(a, b)) * b; // LCM formula
}
