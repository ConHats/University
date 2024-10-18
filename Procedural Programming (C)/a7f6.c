#include "stdio.h"
#include "simpio.h"
#include "genlib.h"
#include "math.h"


#define N 5


void readData(int r,int c,int A[r][c]);
void findMean(int r,int c,int j,int A[r][c],double *Aver_Men,double *Aver_Wom);


int main()
{
    int A[4][N];
    double Aver_Men,Aver_Wom;

    readData(N,4,A);

    findMean(N,4,1,A,&Aver_Men,&Aver_Wom);
    printf("Mesos oros barous andrwn: %.1f\nMesos oros barous gynaikwn: %.1f\n",Aver_Men,Aver_Wom);

    findMean(N,4,2,A,&Aver_Men,&Aver_Wom);
    printf("\nMesos oros ypsous andrwn: %.1f\nMesos oros ypsous gynaikwn: %.1f\n",Aver_Men,Aver_Wom);

    findMean(N,4,3,A,&Aver_Men,&Aver_Wom);
    printf("\nMesos oros hlikias andrwn: %.1f\nMesos oros hlikias gynaikwn: %.1f\n",Aver_Men,Aver_Wom);

    return 0;
}


void readData(int r,int c,int A[r][c])
{
    int i;

    for(i=0;i<r;i++)
    {
        printf("Dwse fylo: ");
        scanf("%d",&A[i][0]);

        printf("Dwse baros: ");
        scanf("%d",&A[i][1]);

        printf("Dwse ypsos: ");
        scanf("%d",&A[i][2]);

        printf("Dwse ilikia: ");
        scanf("%d",&A[i][3]);

        printf("-----\n");
    }
}

void findMean(int r,int c,int j,int A[r][c],double *Aver_Men,double *Aver_Wom)
{
    int i,sumx=0,sumy=0,x=0,y=0;
    for(i=0;i<r;i++)
    {
        if(A[i][0]==0)
        {
            sumx++;
            x+=A[i][j];
        }
        else
        {
            sumy++;
            y+=A[i][j];
        }
    }
    *Aver_Men=(double)x/sumx;
    *Aver_Wom=(double)y/sumy;
}
