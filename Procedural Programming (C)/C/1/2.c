#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    long side_1, side_2;
    double area;
    printf("Enter the length of the first side: ");
    side_1 = GetInteger();
    printf("Enter the length of the second side: ");
    side_2 = GetInteger();
    area = side_1 * side_2 / 2.0;
    printf("The area is: %g\n", area);
    return 0;
}
