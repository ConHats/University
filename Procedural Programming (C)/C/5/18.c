#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define JAN 31
#define FEB 29
#define MAR 31
#define APR 30
#define MAY 31
#define JUN 30
#define JUL 31
#define AUG 31
#define SEP 30
#define OCT 31
#define NOV 30
#define DEC 31

int month(int number, int size, int array[]);
int findmax(int size, int array[]);

int main() {
    int j, k, temp, max[12];
    int January[JAN], February[FEB], March[MAR], April[APR], May[MAY], June[JUN], July[JUL], August[AUG];
    int September[SEP], October[OCT], November[NOV], December[DEC];

    printf("Month 1\n---------------\n");
    month(1, JAN, January);
    printf("Month 2\n---------------\n");
    month(2, FEB, February);
    printf("Month 3\n---------------\n");
    month(3, MAR, March);
    printf("Month 4\n---------------\n");
    month(4, APR, April);
    printf("Month 5\n---------------\n");
    month(5, MAY, May);
    printf("Month 6\n---------------\n");
    month(6, JUN, June);
    printf("Month 7\n---------------\n");
    month(7, JUL, July);
    printf("Month 8\n---------------\n");
    month(8, AUG, August);
    printf("Month 9\n---------------\n");
    month(9, SEP, September);
    printf("Month 10\n---------------\n");
    month(10, OCT, October);
    printf("Month 11\n---------------\n");
    month(11, NOV, November);
    printf("Month 12\n---------------\n");
    month(12, DEC, December);

    // Finding the maximum value for each month
    max[0] = findmax(JAN, January);
    max[1] = findmax(FEB, February);
    max[2] = findmax(MAR, March);
    max[3] = findmax(APR, April);
    max[4] = findmax(MAY, May);
    max[5] = findmax(JUN, June);
    max[6] = findmax(JUL, July);
    max[7] = findmax(AUG, August);
    max[8] = findmax(SEP, September);
    max[9] = findmax(OCT, October);
    max[10] = findmax(NOV, November);
    max[11] = findmax(DEC, December);

    // Sorting the maximum values to find the highest
    for (j = 0; j < 12; j++) {
        for (k = j + 1; k < 12; k++) {
            if (max[k] > max[j]) {
                temp = max[j];
                max[j] = max[k];
                max[k] = temp;
            }
        }
    }

    // Output the highest maximum charge
    printf("Days with the biggest charge: %d\n", max[0]);

    return 0;
}

// Function to take charge values for a month
int month(int number, int size, int array[]) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Charge %d/%d: ", i + 1, number);
        array[i] = GetInteger();
    }
    return 0;  // Instead of returning array, return 0 as it's not necessary
}

// Function to find the maximum charge for a month
int findmax(int size, int array[]) {
    int i, maximum = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

int month(int number, int size, int array[]);
int findmax(int size, int array[]);

int main(){
    int j, k, temp, January[31], February[29], March[31], April[30], May[31], June[30], July[31], August[31], September[30], October[31], November[30], December[31], max[12];
    printf("Month 1\n---------------\n");
    January[31] = month(1, 31, January);
    printf("Month 2\n---------------\n");
    February[29] = month(2, 29, February);
    printf("Month 3\n---------------\n");
    March[31] = month(3, 31, March);
    printf("Month 4\n---------------\n");
    April[30] = month(4, 30, April);
    printf("Month 5\n---------------\n");
    May[31] = month(5, 31, May);
    printf("Month 6\n---------------\n");
    June[30] = month(6, 30, June);
    printf("Month 7\n---------------\n");
    July[31] = month(7, 31, July);
    printf("Month 8\n---------------\n");
    August[31] = month(8, 31, August);
    printf("Month 9\n---------------\n");
    September[30] = month(9, 30, September);
    printf("Month 10\n---------------\n");
    October[31] = month(10, 31, October);
    printf("Month 11\n---------------\n");
    November[30] = month(11, 30, November);
    printf("Month 12\n---------------\n");
    December[31] = month(12, 31, December);
    max[0] = findmax(31, January);
    max[1] = findmax(29, February);
    max[2] = findmax(31, March);
    max[3] = findmax(30, April);
    max[4] = findmax(31, May);
    max[5] = findmax(30, June);
    max[6] = findmax(31, July);
    max[7] = findmax(31, August);
    max[8] = findmax(30, September);
    max[9] = findmax(31, October);
    max[10] = findmax(30, November);
    max[11] = findmax(31, December);
    for (j=0; j<12; j++)
        {
            for (k=0; k<12; k++)
                {
                    if (max[k] > max[j])
                        {
                            temp = max[j];
                            max[j] = max[k];
                            max[k] = temp;
                        }
                }

        }
    printf("Days with the biggest charge:%d", max[11]);
    return 0;
}

int month(int number, int size, int array[]){
    int i;
    for (i=0; i<size; i++)
        {
            printf("Charge %d/%d:", i+1, number);
            array[i] = GetInteger();
        }
    return array;
}

int findmax(int size, int array[]){
    int i, maximum;
    maximum = array[0];
    for (i=1; i<size; i++)
        {
            if (maximum < array[i])
                {
                    maximum = array[i];
                }
        }
    return maximum;
}
