#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 1000

typedef enum{
    FALSE, TRUE
} boolean;

typedef boolean set_type[MAX_SIZE];
typedef int set_element;

void displaySet(set_type set);
void createFibonacciSet(set_element threshold, set_type set);
boolean isFibonacci(set_element candidate, set_type fibonacciSet);
void initializeSet(set_type set);
void insert(set_element element, set_type set);
boolean isMember(set_element element, set_type set);

main()
{
    set_type fibonacciSet;
    set_element max, tmp;
    max = 0;
    while ((max < 2) || (max > 1000))
    {
        printf("Enter the maximum number: ");
        scanf("%d", &max);
    }

    createFibonacciSet(max, fibonacciSet);
    displaySet(fibonacciSet);
    tmp = 0;
    while (tmp >= 0)
    {
        printf("Enter number to check: ");
        scanf("%d", &tmp);
        if (tmp >= 0 && tmp <= 1000)
        {
            if (isFibonacci(tmp, fibonacciSet))
            {
               printf("Fibonacci!\n");
            }
            else
            {
                printf("Not Fibonacci...\n");
            }
        }
    }
    system("PAUSE");
}

void initializeSet(set_type set)
{
    set_element i;

    for (i = 0; i < MAX_SIZE; i++)
        set[i] = FALSE;
}

void createFibonacciSet(set_element threshold, set_type set)
{
    set_element f1, f2, tmp;
    set_element i;
    initializeSet(set);
    f1 = 0;
    f2 = 1;
    insert(f1, set);
    while (f2 <= threshold)
    {
        insert(f2, set);
        tmp = f1 + f2;
        f1 = f2;
        f2 = tmp;
    }
}

boolean isFibonacci(set_element candidate, set_type fibonacciSet)
{
    if (isMember(candidate, fibonacciSet))
        return TRUE;
    else
        return FALSE;
}

void displaySet(set_type set)
{
    set_element i;

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (set[i] == TRUE)
            printf(" %d", i);
    }
    printf("\n");
}

boolean isMember(set_element element, set_type set)
{
    return set[element];
}

void insert(set_element element, set_type set)
{
    set[element] = TRUE;
}
