#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define StackLimit 6


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
int StackMin(StackType Stack, int newNum);


int main ()
{
    StackElementType i,x,j;
    StackType S,minS;
    CreateStack(&S);
    CreateStack(&minS);

    for(i=1;i<=StackLimit;i++)
    {
        printf("Give next element: ");
        scanf("%d",&x);
        Push(&S, x);
        printf("count of stack %d\n",i);
        for(j=0;j<i;j++)
        {
            printf("%d ",S.Element[j]);
        }

        if(EmptyStack(minS)||S.Element[S.Top]<=minS.Element[minS.Top])
        {
            Push(&minS, x);

        }

        printf("\nMin=%d \n",minS.Element[minS.Top]);
    }

    printf("\nEmptying stack\n");
    for(i=5;i>=0;i--)
    {
        if(S.Element[S.Top]==minS.Element[minS.Top])
        {
            Pop(&minS, &minS.Element[minS.Top]);
        }
        Pop(&S, &S.Element[S.Top]);

        printf("Min= %d",minS.Element[minS.Top]);
        printf("\ncount of stack %d\n",i);
        for(j=0;j<i;j++)
        {
            printf("%d ",S.Element[j]);
        }
        printf("\n");
    }
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

int StackMin(StackType Stack, int newNum)
{

}
