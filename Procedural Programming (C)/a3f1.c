#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    char all[16],fcoef[3],fmark[3];
    int i=0,j,x,y;
    float z;

    printf("Please insert course info (name/coef/mark) : ");
    scanf("%s",&all);

    while(all[i]!='/')
    {
        i++;
    }
    if(i<9)
    {
        printf("lesson: ");
        for(j=0;j<i;j++)
        {
            printf("%c",all[j]);
        }

       for(j=0;j<2;j++)
       {
           fcoef[j]=all[j+i+1];
           fmark[j]=all[j+i+4];
       }
        z=atof(fcoef)*atof(fmark)/100;

        printf("\ncoef: %d\nmark: %d\nfinal mark: %.2f",atoi(fcoef),atoi(fmark),z);


    }
    else
    {
        printf("Error! Name should not be more than 9 chars");
    }

    return 0;
}
