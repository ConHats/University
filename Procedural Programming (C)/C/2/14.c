#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main() {
    double weight, height, BMI;
    height = (printf("Enter height: "), GetReal());  // Prompt for height
    weight = (printf("Enter weight: "), GetReal());  // Prompt for weight
    BMI = weight / (height * height);  // Calculate BMI

    // Check BMI category
    if (BMI < 18.5)
        printf("Underweight");
    else if (BMI >= 18.5 && BMI < 25)
        printf("Normal");
    else if (BMI >= 25 && BMI < 30)
        printf("Overweight");
    else
        printf("Obese");

    return 0;
}
