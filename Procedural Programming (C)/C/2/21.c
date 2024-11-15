#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    double allowance;
    int salary, children;
    salary = (printf("Enter the base salary: "), GetInteger());
    children = (printf("Enter the number of children: "), GetInteger());
    {
        if (children == 1)
            {
                 allowance = salary * 0.4;
            }
        else if (children == 2)
            {
                 allowance = salary * 0.9;
            }
        else if (children == 3)
            {
                allowance = salary * 0.15;
            }
        else
            {
                allowance = salary * 0.15 * 3 + salary * 0.4 * (children - 3);
            }
    }
    printf("The allowance is %.2f", allowance);
    return 0;
}
