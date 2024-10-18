#include "stdio.h"
#include "stdio.h"
#include "genlib.h"
#include "math.h"

#define SIZE 30
#define BATHMOI 20

void fillTable(int size,int A[SIZE]);/*reads and fills table A with students grades*/
void createTable(int A[SIZE],int sizeA,int B[BATHMOI],int sizeB);/*creates table B with the frequency of each grade*/
void MaxTable(int B[BATHMOI],int *max, int *index);/*finds max and index of table B*/
void MinTable(int B[BATHMOI],int *min, int *index);/*finds min and index of table B*/
void PrintAll(int B[BATHMOI],int size,int indexmax,int max,int indexmin,int min);/*prints table B, max, mix and their indexs of table B*/


int main()
{
    int A[SIZE], B[BATHMOI]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, max, min, indexmax, indexmin;

    fillTable(SIZE,A);
    createTable(A,SIZE,B,BATHMOI);
    MaxTable(B,&max,&indexmax);
    MinTable(B,&min,&indexmin);

    PrintAll(B,BATHMOI,indexmax,max,indexmin,min);


    return 0;
}

void fillTable(int size,int A[SIZE])
{
    int i;

    for(i=0;i<size;i++)
    {
        printf("Dwse bathmo %d:",i+1);
        scanf("%d",&A[i]);
    }
}


void createTable(int A[SIZE],int sizeA,int B[BATHMOI],int sizeB)
{
    int i;
    for(i=0;i<sizeA;i++)
    {
        B[A[i]-1]++;
    }

}


void MaxTable(int B[BATHMOI],int *max, int *index)
{
    int i;

    *max=B[0];
    *index=0;

    for(i=1;i<BATHMOI;i++)
    {
        if(*max<B[i])
        {
            *max=B[i];
            *index=i;
        }
    }
}


void MinTable(int B[BATHMOI],int *min, int *index)
{
    int i;

    *min=B[0];
    *index=0;

    for(i=1;i<BATHMOI;i++)
    {
        if(*min>B[i])
        {
            *min=B[i];
            *index=i;
        }
    }
}


void PrintAll(int B[BATHMOI],int size,int indexmax,int max,int indexmin,int min)
{
    int i;

    printf("Syxnotites bathmwn \n");

    for(i=0;i<size;i++)
    {
        printf("%d: %d\n",i+1,B[i]);
    }

    printf("Bathmos me th megalyteri syxnotita: %d\nSyxnotita: %d\n",indexmax+1, max);
    printf("Bathmos me th mikroteri syxnotita: %d\nSyxnotita: %d",indexmin+1, min);
}
