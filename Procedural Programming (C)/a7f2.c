#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    long kwdikos;

    printf("Dwse ton kwdiko:");
    kwdikos=GetLong();

    if(kwdikos>=1000)
    {
        double em;
        printf("Dwse ton ethsio mistho:");
        em=GetReal();
        printf("H ebdomadiaia amoih einai %.2f ", em/52);
    }
    else
    {
        int wres;
        double amoibh;
        printf("Dwse tis wres ebdomadiaias ergasias:");
        wres=GetInteger();
        printf("Dwse thn amoibh ana wra:");
        amoibh=GetReal();

        if (wres>40)
        {
            int extra= wres-40;
            printf("H ebdomadiaia amoih einai %.2f", (40*amoibh)+(extra*amoibh*1.5));
        }
        else
        {
            printf("H ebdomadiaia amoih einai %.2f", wres*amoibh);
        }

    }

    return 0;
}
