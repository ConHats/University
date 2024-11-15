#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define StackLimit 25


typedef int StackElementType;


typedef struct
{
    int Top;
    StackElementType Element[StackLimit];
} StackType;


typedef enum
{
    FALSE, TRUE
} boolean;


void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
int GetNthElementA(StackType Stack, int n);
int GetNthElementB(StackType Stack, int n);
void printStack(StackType Stack);

int main()
{
    StackElementType i,n,x, number = 0;
    StackType S;
    CreateStack(&S);

    for (i=2; i<=StackLimit*2; i+=2)
    {
        number = i;
        Push(&S, number);
    }

    printStack(S);

    printf("Give n: ");
    scanf("%d",&n);

    printf("Top with GetNthElementA = %d\n", GetNthElementA(S,n));;

    printStack(S);
    printf("Top with GetNthElementB = %d\n",GetNthElementB(S,n));
    printStack(S);

    return 0;
}


void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
}


boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}


boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}


void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}


void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


int GetNthElementA(StackType Stack, int n)
{
    StackType tempS;
    StackElementType i,x;
    CreateStack(&tempS);

    for(i=0;i<n;i++)
    {
        Pop(&Stack, &x);
        Push(&tempS, x);
    }
    return x;
}


int GetNthElementB(StackType Stack, int n)
{
    return Stack.Element[StackLimit-n];
}


void printStack(StackType Stack)
{
    int i;
    printf("count of stack %d\n",StackLimit);

    for(i=0;i<StackLimit;i++)
    {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
