#include <stdio.h>
#include <genlib.h>
#include <simpio.h>
#include <math.h>

int add(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
int divd(int x, int y);

int main()
{
    printf("Dwse ton 1o arithmo: ");
    int x=GetInteger();
    printf("Dwse ton 2o arithmo: ");
    int y=GetInteger();
    printf("add: %d\nsub: %d\nmult: %d\ndivd: %d\nexp1: %d\nexp2: %d\n",
           add(x,y),
           sub(x,y),
           mult(x,y),
           divd(x,y),
           mult(add(x,y), sub(y, divd(x,y))),
           divd(sub(mult(x,y),x), add(x,y)) );
    return 0;
}

int add(int x, int y)
{
    return x+y;
}

int sub(int x, int y)
{
    return x-y;
}

int mult(int x, int y)
{
    return x*y;
}

int divd(int x, int y)
{
    int z=0;
    if(y!=0)
    {
        z=x/y;
    }
    return z;
}
