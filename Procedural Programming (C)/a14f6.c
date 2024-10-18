#include "stdio.h"
#include "simpio.h"
#include "genlib.h"
#include "math.h"

#define STUD 30
#define SUB 3
#define DEM 2

void fillTable(int demention,int A[STUD][SUB]);
void AverageTable(int A[STUD][SUB],double B[STUD]);
void PrintForStud(int A[STUD][SUB],double B[STUD]);
void FailsAndExcels(double B[STUD],int *fail,int *excel);

int main()
{
    int  A[STUD][SUB],fail,excel;
    double B[STUD];

    fillTable(DEM,A);
    AverageTable(A,B);
    PrintForStud(A,B);

    FailsAndExcels(B,&fail,&excel);
    printf("Apotyxontes: %d\nPososto apotyxonton:%5.2f%%\n",fail,(double)fail/STUD);
    printf("Aristouxoi: %d\nPososto aristouxwn:%5.2f%%",excel,(double)excel/STUD);

    return 0;
}


void fillTable(int dem,int A[STUD][SUB])
{
    int i,j;

    for(i=0;i<STUD;i++)
    {
        for(j=0;j<SUB;j++)
        {
            A[i][j]=rand()%21+1;
        }
    }
}


void AverageTable(int A[STUD][SUB],double B[STUD])
{
    int i,j,sum;

    for(i=0;i<STUD;i++)
    {
        sum=0;
        for(j=0;j<SUB;j++)
        {
            sum+=A[i][j];
        }
        B[i]=(double)sum/3;
    }
}


void PrintForStud(int A[STUD][SUB],double B[STUD])
{
    int i;

    for(i=0;i<STUD;i++)
    {
        printf("%2d:  %2d %2d %2d : %5.2f\n",i,A[i][0],A[i][1],A[i][2],B[i]);
    }
}


void FailsAndExcels(double B[STUD],int *fail,int *excel)
{
   int i;

   *excel=0;
   *fail=0;

   for(i=0;i<STUD;i++)
   {
       if(B[i]>=18.5)
       {
           (*excel)++;
       }
       else if(B[i]<9.5)
       {
           (*fail)++;
        }
   }
}
