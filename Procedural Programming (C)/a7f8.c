#include <simpio.h>
#include <stdio.h>
#include <genlib.h>
#include <ctype.h>
#include <string.h>


typedef struct
    {
        int num;
        char type[20];
        int cc;
        char name[10];
        int days;
        int price;
        int total;
    }RentACar;


int main()
{
    int size,i,sum=0;
    char temp;
    printf("Dose ton arithmo ton enoikiaseon: ");
    scanf("%d",&size);

    RentACar emp[size];

    for(i=0;i<size;i++)
    {
        printf("\nDose ta stoixeia tis enoikiasis %d\n",i);

        emp[i].num=i;
        printf("Dose marka: ");
        scanf("%c",&temp);
        scanf("%[^\n]",&emp[i].type);
        printf("Dose kyvika: ");
        scanf("%d",&emp[i].cc);
        printf("Dose onoma pelati: ");
        scanf("%s",&emp[i].name);
        printf("Dose imeres enoikiasis: ");
        scanf("%d",&emp[i].days);
        printf("Dose timi ana imera: ");
        scanf("%d",&emp[i].price);

        emp[i].total=emp[i].days*emp[i].price;
    }

    printf("\n\nNumber  Name                 Type       CC    Days  Price  Total\n");
    printf("--------------------------------------------------------------------------\n");

    for(i=0;i<size;i++)
    {
        printf("%-2d      %-20s %-10s %-4d  %-2d    %-d.00 %-d.00\n",emp[i].num,emp[i].name,emp[i].type,emp[i].cc,emp[i].days,emp[i].price,emp[i].total);
    }
    printf("--------------------------------------------------------------------------\n");

    for(i=0;i<size;i++)
    {
        sum+=emp[i].total;
    }
    printf("                                                    Total %d.00",sum);

    int max=0,index=-1;
    for(i=0;i<size;i++)
    {
        if(max<emp[i].total)
        {
            max=emp[i].total;
            index=i;
        }
    }
    printf("\nBest car: %s %d rented for %d.00 Euros",emp[index].type,emp[index].cc,emp[index].total);
}
