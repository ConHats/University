#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main ()
{
    int cm, kgr;
    double Y;
    printf("Enter weight: ");
    kgr = GetInteger();
    Y = (1.12 * kgr + 65) * 1.2 + 7.0;
    cm = ceil(Y);
    printf("The height is %d\n", cm);
    return 0;
}
