#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int max(int a, int b);

int main(){
    int a, b, MAX;
    printf("Enter x: ");
    a = GetInteger();
    printf("Enter y: ");
    b = GetInteger();
    MAX = max(a,b);
    printf("Max: %d", MAX);
    return 0;
}

int max(int a, int b){
    if (a>b)
        return a;
    return b;
}
