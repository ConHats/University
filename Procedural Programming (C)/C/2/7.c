#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main (){
    long code;
    double salary, weekly_salary, wage;
    int hours;
    printf("Enter the code: ");
    code = GetLong();
    if (code >= 1000) {
        printf("Enter the annual salary: ");
        salary = GetReal();
        weekly_salary = salary / 52;
    }
    else {
        printf("Enter the weekly working hours: ");
        hours = GetInteger();
        printf("Enter the hourly wage: ");
        wage = GetReal();
        if (hours > 40) {
            weekly_salary = 40 * wage + (hours - 40) * wage * 1.5;
        }
        else {
            weekly_salary = hours * wage;
        }
    }
    printf("The weekly salary is %g", weekly_salary);
    return 0;
}
