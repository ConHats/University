#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define Athletes 8

void Num_of_Successes(float swim[], float bike[], float run[], int code[], float success[], int successful[]);
void print(float success[], int successful[]);

int main() {
    int AthletesID[Athletes] = {115, 136, 187, 254, 281, 290, 301, 314};
    float pointsforSwimming[Athletes];
    float pointsforBiking[Athletes];
    float pointsforRunning[Athletes];
    float s2[Athletes];
    int s[Athletes];
    int i;
    float maxSwimming, maxBiking, maxRunning;
    float avgSwimming, avgBiking, avgRunning;

    printf("Enter points for Swimming\n");
    for(i=0; i<Athletes; i++) {
        printf("Enter points for athlete %d: ", AthletesID[i]);
        pointsforSwimming[i] = GetReal();
    }

    printf("Enter points for Biking\n");
    for(i=0; i<Athletes; i++) {
        printf("Enter points for athlete %d: ", AthletesID[i]);
        pointsforBiking[i] = GetReal();
    }

    printf("Enter points for Running\n");
    for(i=0; i<Athletes; i++) {
        printf("Enter points for athlete %d: ", AthletesID[i]);
        pointsforRunning[i] = GetReal();
    }

    maxSwimming = pointsforSwimming[0];
    maxBiking = pointsforBiking[0];
    maxRunning = pointsforRunning[0];
    for(i=1; i<Athletes; i++) {
        if(pointsforSwimming[i] > maxSwimming)
            maxSwimming = pointsforSwimming[i];
        if(pointsforBiking[i] > maxBiking)
            maxBiking = pointsforBiking[i];
        if(pointsforRunning[i] > maxRunning)
            maxRunning = pointsforRunning[i];
    }
    printf("Greatest scores: %.1f (Swim) %.1f (Bike) %.1f (Run)\n", maxSwimming, maxBiking, maxRunning);

    avgSwimming = 0;
    avgBiking = 0;
    avgRunning = 0;
    for(i=0; i<Athletes; i++) {
        avgSwimming += pointsforSwimming[i];
        avgBiking += pointsforBiking[i];
        avgRunning += pointsforRunning[i];
    }
    avgSwimming /= Athletes;
    avgBiking /= Athletes;
    avgRunning /= Athletes;
    printf("Average scores: %.1f (Swim) %.1f (Bike) %.1f (Run)\n", avgSwimming, avgBiking, avgRunning);

    Num_of_Successes(pointsforSwimming, pointsforBiking, pointsforRunning, AthletesID, s2, s);
    print(s2, s);
    system("PAUSE");
}

void Num_of_Successes(float swim[], float bike[], float run[], int code[], float success[], int successful[]) {
    int j;
    float sum[Athletes], ms;
    int successCount = 0;
    for (j=0; j<Athletes; j++) {
        sum[j] = swim[j] + bike[j] + run[j];
    }
    for (j=0; j<Athletes; j++) {
        ms = sum[j] / 3;
        if (ms > 5) {
            success[j] = ms;
            successful[successCount] = code[j];
            successCount++;
        }
    }
}

void print(float success[], int successful[]) {
    int j=0;
    for (j=0; j<Athletes; j++) {
        if (success[j] > 5) {
            printf("Athlete's ID %d, Average score %.1f\n", successful[j], success[j]);
        }
    }
}
