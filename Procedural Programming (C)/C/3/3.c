#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    long domestic_boxes, foreign_boxes, domestic_amount, foreign_amount, total_domestic = 0, total_foreign = 0;
    printf("Number of domestic boxes? ");
    domestic_boxes = GetLong();
    while (domestic_boxes != -9999)
        {
            printf("Number of foreign boxes? ");
            foreign_boxes = GetLong();
            domestic_amount = domestic_boxes * 3500;
            total_domestic += domestic_amount;
            foreign_amount = foreign_boxes * 5000;
            total_foreign += foreign_amount;
            printf("%10ld%10ld%10ld\n", domestic_amount, foreign_amount, domestic_amount + foreign_amount);
            printf("Number of domestic boxes? ");
            domestic_boxes = GetLong();
        }
    printf("%10ld%10ld%10ld", total_domestic, total_foreign, total_domestic + total_foreign);
    return 0;
}
