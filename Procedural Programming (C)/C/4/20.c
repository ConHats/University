#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define TRUE 1
#define FALSE 0

bool isLeapYear(int year);

int main(){
    int year1, year2, year;
    printf("From year:");
    year1 = GetInteger();
    printf("Till year:");
    year2 = GetInteger();
    for (year=year1;year<=year2;year++)
        {
            if (isLeapYear(year))
                printf("%d Leap year\n", year);
        }
    return 0;
}

bool isLeapYear(int year){
    if (((year % 4 == 0) && (year % 100 != 0)) || (year% 400 == 0))
        {
            return TRUE;
        }
    return FALSE;
}
