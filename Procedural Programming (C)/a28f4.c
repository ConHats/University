#include <stdio.h>
#include <genlib.h>
#include <simpio.h>
#include <math.h>

int get_code(int kwd);
int discount_percentage(int kwd);
int product_points(int kwd, double price);


int main()
{
    int kwd, ekptwsh=0,tel_syn=0, sum=0, points, prices=0;
    double price;
    do
    {
        printf("Dwse ton kwdiko: %d",kwd=get_code(kwd));
        printf("Dwse thn timh: %g", price=GetReal());
        ekptwsh=discount_percentage(kwd);
        points=product_points(kwd,price);
        tel_syn+= price-(ekptwsh/100)*price;
        sum+= points;
        prices+=((ekptwsh)/100)*price;
    } while(kwd!=0);
    printf("--------------------\n Teliko synolo: %g Euro\n Ekptwsh: %g Euro/n Pontoi: %d", tel_syn, prices, sum );
}


int get_code(int kwd)
{
    if( kwd<0 | kwd>2000)
    {
        printf("Lathos Kwdikos(0-2000)\n");

    }
    return kwd;
}

int discount_percentage(int kwd)
{
    int x;
    if (kwd<=300)
    {
        x=5;
    }
    else if (kwd<=500)
    {
        x=10;
    }
    else if (kwd<=1000)
    {
        x=15;
    }
    else
    {
        x=20;
    }
    return x;
}


int product_points(int kwd,double price)
{
    int y=1;
    if (kwd>=1000 & kwd<=1500)
    {
        y=ceil(price/5);
    }
    return y;
}
