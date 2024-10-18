#include "stdio.h"
#include "math.h"

int calc(int x, int y, int z);


int main()
{
    int k, j, i, n, sum=0;
    printf("Dwse  n: ");
    scanf("%d",&n);
    for(k=1;k<=3;k++)
    {
        for(j=1;j<=n;j++)
        {
            for(i=1;i<=n;i++)
            {
                sum+=calc(k,j,i);
            }
        }
    }
    printf("Result: %d", sum);
    return 0;
}


int calc (int x, int y, int z)
{
    int a;

    if(x==1)
    {

        a=y+z;
    }
    else if(x==2)
    {
        a=y-z;
    }
    else if(x==3)
    {
        a=floor((y+z)/2);
    }
    else
    {
        a=0;
    }

    return a;
}
