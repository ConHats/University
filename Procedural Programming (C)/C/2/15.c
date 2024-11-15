#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main(){
    double a, b, c, D, x, x1, x2;
    printf("Enter the coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a != 0) {
        D = (b * b) - 4 * a * c;  // Calculate the discriminant
        if (D > 0) {
            // Two real and distinct roots
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            printf("The roots are: %lf and %lf\n", x1, x2);
        }
        else if (D == 0) {
            // One real root (repeated root)
            x = -b / (2 * a);
            printf("The root is: %lf\n", x);
        }
        else {
            // Complex roots (no real solution)
            printf("There are no real roots\n");
        }
    }
    else {
        printf("There are no real roots\n");
    }
    return 0;
}
