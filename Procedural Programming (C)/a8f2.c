#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main()
{
    int t1, t2, y, z;

    printf("Dose problepomeno xrono:");
    t1=GetInteger();

    printf("Dose pragmatiko xrono:");
    t2=GetInteger();

    y=(t1>=360)? 17: (t1>=240)? 13: (t1>=180)? 8: (t1>=120)? 6: (t1>=90)? 4: (t1>=60)? 3: (t1>=30)? 2: 1;
    z=abs(t1-t2);

    printf("Apodekth diafora: %d\n",y);
    printf(t1<t2? "Diafora eisodou:-%d\n" : "Diafora eisodou: %d\n", z);
    printf(y==z? "GOOD":(t1>t2)? "BIG": "SMALL");

    return 0;
}
