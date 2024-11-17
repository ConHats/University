#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <stdlib.h>

double Function(double a, double b, double c);
void exit(int status);

int main(){
    double a, b=5, c=10, abc;
    for (a=1;a<=3;a++)
        {
            abc = Function(a, b, c);
            printf("%f\n", abc);
        }
    a=10;
    abc = Function(a, b, c);
    printf("%f\n", abc);
    return 0;
}

double Function(double a, double b, double c){
    if (a==1)
        {
            printf("Sum=");
            return b+c;
        }
    else if (a==2)
        {
            printf("Multiply=");
            return b*c;
        }
    else if (a==3)
        {
            printf("Average=");
            return (b+c)/2;
        }
    else
        {
            printf("Invalid function execution\n");
            exit(1);
        }
}
