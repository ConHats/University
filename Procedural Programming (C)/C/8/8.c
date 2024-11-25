#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

typedef struct{
    int width, height, depth;
    int area, volume;
}box;

void ReadFill(box *cu);
void FindAr(box *cu);
void FindVol(box *cu);

int main(){
    box cuboid;
    ReadFill(&cuboid);
    FindAr(&cuboid);
    FindVol(&cuboid);
    printf("The surface area of the box is %d cm²\n", cuboid.area);
    printf("The volume of the box is %d cm³\n", cuboid.volume);
    return 0;
}

void ReadFill(box *cu){
    printf("Enter the length of the box in cm: ");
    (*cu).width = GetInteger();
    printf("Enter the height of the box in cm: ");
    (*cu).height = GetInteger();
    printf("Enter the depth of the box in cm: ");
    (*cu).depth = GetInteger();
}

void FindAr(box *cu){
    (*cu).area = 2 * ((*cu).depth * (*cu).width + (*cu).width * (*cu).height + (*cu).depth * (*cu).height);
}

void FindVol(box *cu){
    (*cu).volume = (*cu).depth * (*cu).width * (*cu).height;
}
