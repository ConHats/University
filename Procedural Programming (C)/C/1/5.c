#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    int workHours;
    long hourlyWage;
    double deductionPercentage;
    double grossIncome, deductions, netIncome;
    printf("Enter the number of work hours: ");
    workHours = GetInteger();
    printf("Enter the hourly wage: ");
    hourlyWage = GetLong();
    printf("Enter the deduction percentage: ");
    deductionPercentage = GetReal();
    grossIncome = (double) workHours * hourlyWage;
    deductions = grossIncome * deductionPercentage;
    netIncome = grossIncome + deductions;
    printf("The gross income is: %g\n", grossIncome);
    printf("The deductions are: %g\n", deductions);
    printf("The net income is: %g\n", netIncome);
    return 0;
}
