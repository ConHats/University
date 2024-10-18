#include<stdio.h>
#include<string.h>


int main()
{
    char data[6][21],search[2];
    int i,n=5,c=0,sum=0;

    for(i=0;i<n;i++)
    {
        printf("Give name %d :",i);
        scanf("%s",data[i]);
    }

    printf("\nGive initial char: ");
    scanf("%s",search);

    for(i=0;i<n;i++)
    {
        if(data[i][0]==search[0])
        {
            c=1;
            sum++;
        }
    }
    printf("\nNames starting with %s are: %d\n",search,sum);

    if(c==1)
    {
        for(i=0;i<n;i++)
        {
            if(data[i][0]==search[0])
            {
                printf("%s\n",data[i]);
            }
        }
    }

    return 0;
}
