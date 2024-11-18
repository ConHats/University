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
