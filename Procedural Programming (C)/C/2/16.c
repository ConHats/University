#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main() {
    int sms;
    double price;
    printf("Enter the number of SMS: ");
    sms = GetInteger();
    {
        if (sms > 0 && sms <= 10) {
            price = sms * 2;  // First 10 SMS cost 2 cents each
        }
        else if (sms > 10 && sms <= 60) {
            price = 10 * 2 + (sms - 10) * 1.5;  // SMS from 11 to 60 cost 1.5 cents each
        }
        else if (sms > 60 && sms <= 160) {
            price = 10 * 2 + 50 * 1.5 + (sms - 60) * 1.2;  // SMS from 61 to 160 cost 1.2 cents each
        }
        else {
            price = 10 * 2 + 50 * 1.5 + 100 * 1.2 + (sms - 160) * 1.0;  // SMS above 160 cost 1 cent each
        }
    }
    printf("Total cost in euros: %.2f", price / 100);  // Convert the price from cents to euros and print
    return 0;
}
