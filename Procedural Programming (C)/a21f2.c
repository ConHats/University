#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int bm, kids;
    printf("Dwse vasiko mistho: ");
    bm=GetInteger();
    printf("Dwse arithmo paidion: ");
    kids=GetInteger();
    switch (kids)
    {
    case 0:
        printf("Epidoma: 0");
        break;
    case 1:
        printf("Epidoma: %.2f", 0.04*bm);
        break;
    case 2:
        printf("Epidoma: %.2f", 0.09*bm);
        break;
    case 3:
        printf("Epidoma: %.2f", 0.15*bm);
        break;
    default:
        printf("Epidoma: %.2f",(((kids-3)*0.04)+0.15)*bm);
    }
    return 0;
}
