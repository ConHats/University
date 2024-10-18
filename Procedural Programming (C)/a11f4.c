#include "stdio.h"
#include "genlib.h"
#include "simpio.h"
#include "math.h"


long Read_and_Calculate(int year); /*dexetai to year, diabazei ta dd,
                                    mm,yy kai fpa, kai epistrefei to
                                    sunoliko fpa (sum_fpa)*/

bool Valid_Date(int dd, int mm, int yy); /*dexetai dd, mm, yy kai
                                            epistrefei true h false
                                            an einai dekto to date*/


int main()
{

    int year;
    long sum_fpa;
    printf("Current year: ");
    scanf("%d",&year);
    sum_fpa= Read_and_Calculate(year);
    printf("SYNOLO FPA: %ld", sum_fpa);
    return 0;
}


long Read_and_Calculate(int year)
{
    int dd, mm, yy;
    long fpa, sum_fpa=0;
    do{
        printf("Day: ");
        scanf("%d",&dd);
        if(dd==-1)break;
        printf("Month: ");
        scanf("%d",&mm);
        printf("Year: ");
        scanf("%d",&yy);
        printf("FPA: ");
        scanf("%ld",&fpa);
        if(yy==year && Valid_Date(dd, mm, yy))
        {
            sum_fpa+=fpa;
        }

    } while(TRUE);
    return sum_fpa;
}

bool Valid_Date(int dd, int mm, int yy)
{
    bool flag=0;
    if(mm>=1 && mm<=12)
        {
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                flag=1;
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                flag=1;
            else if((dd>=1 && dd<=28) && (mm==2))
                flag=1;
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                flag=1;
        }
        return flag;
}
