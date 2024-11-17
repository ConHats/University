#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define TRUE 1
#define FALSE 0

bool Valid_Time(int h, int m, int s);

int main(){
    int h, m, s;
    printf("Enter hours: ");
    h = GetInteger();
    printf("Enter minutes: ");
    m = GetInteger();
    printf("Enter seconds: ");
    s = GetInteger();
    if (Valid_Time(h, m, s))
        printf("Valid input");
    else
        printf("Wrong input");
    return 0;
}

bool Valid_Time(int h, int m, int s){
    if (h>=0 && h<=23)
        if (m>=0 && m<=59)
            if (s>=0 && s<=59)
                return TRUE;
            return FALSE;
        return FALSE;
    return FALSE;
}
