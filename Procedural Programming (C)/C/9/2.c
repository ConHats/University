#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genlib.h"

#define M 100

typedef struct{
    char name[30];
    int absences;
}studentT;

void readInput(FILE* infile, studentT students[], int *pAbsences, int *pStudents);
void WriteOutput(FILE* outfile, int size, studentT students[], int total);

int main(){
    char infilename[30];
    char outfilename[30];
    FILE* infile;
    FILE* outfile;

    printf("Enter name of input file:");
    gets(infilename);
    infile = fopen(infilename,"r");

    if(infile == NULL){
        printf("Cannot open input file %s\n", infilename);
        exit(1);
    }

    printf("Enter name of output file:");
    gets(outfilename);
    outfile = fopen(outfilename,"w");

    studentT students[M];
    int numberOfStudents, numberOfAbsences;
    readInput(infile, students, &numberOfAbsences, &numberOfStudents);

    WriteOutput(outfile, numberOfAbsences, students, numberOfStudents);

    fclose(infile);
    fclose(outfile);

    return 0;
}

void readInput(FILE* infile, studentT students[], int *pAbsences, int *pStudents){
    int nscan, absences, line;
    char name[30], comments[68], termch;

    *pAbsences = 0;
    *pStudents = 0;

    while(TRUE){
        nscan = fscanf(infile, "%30[^,], %d, %68[^\n]%c", name, &absences, comments, &termch);

        if (nscan == EOF)
            break;

        line++;
        if (nscan != 4 || termch != '\n'){
            printf("Error in line %d. Program termination\n", line);
            exit(1);
        }

        if (absences > 100){
            strcpy(students[*pAbsences].name, name);
            students[*pAbsences].absences = absences;
            (*pAbsences)++;
        }
        (*pStudents)++;
    }
}

void WriteOutput(FILE* outfile, int size, studentT students[], int total){
    int i;

    fprintf(outfile, "%-30s%-9s\n", "NAME", "ABSENCES");
    for (i = 0; i < 39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    for (i = 0; i < size; i++){
        fprintf(outfile, "%-30s%9d\n", students[i].name, students[i].absences);
    }

    for (i = 0; i < 39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    fprintf(outfile, "%-30s%9d\n", "TOTAL STUDENTS", total);
    fprintf(outfile, "%-30s%9d\n", "TOTAL ABSENCES", size);
}
