#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int code, number, price;
    double discount, total;
    code = (printf("Enter the product code: "), GetInteger());
    number = (printf("Enter the number of items: "), GetInteger());
    price = (code % 100) + (code / 100);
    printf("The sale price of the product is %d\n", price);

    if (number > 0 && number <= 30)
    {
        discount = 10;
    }
    else if (number > 30 && number <= 70)
    {
        discount = 20;
    }
    else
    {
        discount = 35;
    }

    discount = number * price * discount / 100;
    printf("The discount is %g\n", discount);
    total = number * price - discount;
    printf("The final price of the order is %g", total);
    return 0;
}
