#include "stdio.h"
#include "simpio.h"
#include "genlib.h"
#include "math.h"


#define ROWS 4
#define COLUMNS 5
#define HELP 2

void calculateSales(int A[ROWS][COLUMNS],int rows,int col,int B[ROWS]);
void calculateProductSales(int A[ROWS][COLUMNS],int rows,int col,int B[COLUMNS]);
void maxArray(int A[COLUMNS],int size, int B[HELP]);
void printArray(int A[COLUMNS],int size);


int main()
{
    int SALES[ROWS][COLUMNS]={{10,4,5,6,7},
                              {7,0,12,1,3},
                              {4,19,5,0,8},
                              {3,2,1,5,6}};

    int salesPerson[ROWS],productSale[COLUMNS],B[HELP];



    calculateSales(SALES,ROWS,COLUMNS,salesPerson);
    calculateProductSales(SALES,ROWS,COLUMNS,productSale);



    printf("SalesMan-Sales\n");
    printArray(salesPerson,ROWS);

    maxArray(salesPerson,ROWS,B);
    printf("Best Salesman was %d with %d sales\n",B[0],B[1]);


    printf("Product-Items\n");
    printArray(productSale,COLUMNS);

    maxArray(productSale,COLUMNS,B);
    printf("Best Product was %d with %d items",B[0],B[1]);


    return 0;
}

void calculateSales(int A[ROWS][COLUMNS],int rows,int col,int B[ROWS])
{
    int i,j,sum1;
    for(i=0;i<rows;i++)
    {
        sum1=0;
        for(j=0;j<col;j++)
        {
            if(j==0)
            {
                sum1+=250*A[i][j];
            }
            if(j==1)
            {
                sum1+=150*A[i][j];
            }if(j==2)
            {
                sum1+=320*A[i][j];
            }if(j==3)
            {
                sum1+=210*A[i][j];
            }
            if(j==4)
            {
                sum1+=920*A[i][j];
            }
        }
        B[i]=sum1;
    }
}

void calculateProductSales(int A[ROWS][COLUMNS],int rows,int col,int B[COLUMNS])
{
    int i,j,sum2;

    for(j=0;j<col;j++)
    {
        sum2=0;
        for(i=0;i<rows;i++)
        {
           sum2+=A[i][j];
        }
        B[j]=sum2;
    }

}

void maxArray(int A[COLUMNS],int size,int B[HELP])
{
    int i, max=A[0], index=0;
    for(i=1;i<size;i++)
    {
        if(max<A[i])
        {
            max=A[i];
            index=i;
        }
    }
    B[0]=index;
    B[1]=max;
}

void printArray(int A[COLUMNS],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("   %d     %-d\n",i,A[i]);
    }
}
