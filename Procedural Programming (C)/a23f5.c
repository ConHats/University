#include "simpio.h"
#include "genlib.h"
#include "stdio.h"
#include "math.h"

int main()
{
    int i, j, A[4], B[4], sum=0;

    for (i=0;i<4;i++)
    {
        printf("Insert SetA num %d:",i);
        scanf("%d",&A[i]);
        sum+=A[i];
    }
    for (i=0;i<4;i++)
    {
        printf("Insert SetB num %d:",i);
        scanf("%d",&B[i]);
        sum+=B[i];
    }

    printf("Sum: %d\n",sum);

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%6d",A[j]+B[i]);
        }
        printf("\n");
    }
    return 0;
}
