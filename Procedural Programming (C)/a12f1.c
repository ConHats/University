#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{   float ktm, mtm;
    printf("Dose kathara tm: ");
    ktm= GetInteger();
    printf("Dose mikta tm: ");
    mtm= GetInteger();
    printf("DT: %.2f\n",(ktm*1.33*61)/365);
    printf("DF: %.2f",(mtm*0.13*61)/365);
    return 0;
}
