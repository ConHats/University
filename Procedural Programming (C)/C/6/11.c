#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void read_temperatures(int array[]);
void find_max_min_average(int array[], int *max, int *min, float *meanscore);

int main(){
    int array[30], max, min;
    float meanscore;
    read_temperatures(array);
    find_max_min_average(array, &max, &min, &meanscore);
    printf("Max temperature: %d\n", max);
    printf("Min temperature: %d\n", min);
    printf("Average: %.2f\n", meanscore);
    system("pause");
    return 0;
}

void read_temperatures(int array[]){
    int i;
    printf("Temperatures of the month\n");
    for (i=0; i<30; i++)
        {
            printf("Enter value %d: ", i);
            array[i] = GetInteger();
        }
}

void find_max_min_average(int array[], int *max, int *min, float *meanscore){
    int i;
    float sum = 0;
    *max = array[0];
    for (i=1; i<30; i++)
        {
            if (*max < array[i])
                {
                    *max = array[i];
                }
        }
    *min = array[0];
    for (i=1; i<30; i++)
        {
            if (*min > array[i])
                {
                    *min = array[i];
                }
        }
    for (i=0; i<30; i++)
        {
            sum = sum + array[i];
        }
    *meanscore = sum/30;
}
