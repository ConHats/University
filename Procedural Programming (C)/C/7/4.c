#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"

int main(){
    int number;
    printf("Give number: ");
    number = GetInteger();
    // Delete 7 and put any other number you want
    printf("%07d\n", number);
    return 0;
}