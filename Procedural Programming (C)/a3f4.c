#include <stdio.h>
#include <genlib.h>
#include <simpio.h>
#include <math.h>

double ceil_dec(double number, int places);

int main()
{
    double number=GetReal();
    int places=GetInteger();
    printf("%g", ceil_dec(number, places));
}


double ceil_dec(double number, int places)
{
    int z;
    z= pow( 10,places);
    return ceil( number * z) / z;
}
