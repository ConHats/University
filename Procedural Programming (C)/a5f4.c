#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

bool IsArmstrong(int i);
int Sum_Cube(int i);

int main()
{
    int i, athrisma=0;
    for(i=1;i<1000;i++)
    {
        if (IsArmstrong(i))
        {
            printf("%d\n",i);
        }
    }
    return 0;
}

bool IsArmstrong(int i)
{
    int athrisma;
    athrisma=Sum_Cube(i);
    return (athrisma==i);
}

int Sum_Cube(int i)
{
    int z,sum=0;
    while(i!=0)
    {
        z=i%10;
        i/=10;
        sum+=z*z*z;
    }
    return(sum);
}







