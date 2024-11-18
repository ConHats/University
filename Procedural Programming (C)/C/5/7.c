#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int M1, N1, M2, N2, i, j;
    long A[50][50], B[50][50];
    printf("Enter number of lines m1: ");
    M1 = GetInteger();
    printf("Enter number of columns  n1: ");
    N1 = GetInteger();
    printf("Enter number of lines m2: ");
    M2 = GetInteger();
    printf("Enter number of columns n2: ");
    N2 = GetInteger();
    for (i=0; i<M1; i++)
        {
            for (j=0; j<N1; j++)
                {
                    A[i][j] = GetLong();
                }
        }
    for (i=0; i<M2; i++)
        {
            for (j=0; j<N2; j++)
                {
                    B[i][j] = GetLong();
                }
        }
    return 0;
}
