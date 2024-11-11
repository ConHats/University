#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 15

typedef int StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void TraverseStack(StackType Stack);

int main()
{
    StackElementType i, number = 0, n, x, temp, top;
    StackType S, tempS;

    CreateStack(&S);

    for (i=0; i<StackLimit; i++){
            number = i*10;
            Push(&S, number);
    }

    TraverseStack(S);

    printf("Give nth element (n<=6) ");
    scanf("%d", &n);

    printf("\n");
    Pop(&S, &x);
    Pop(&S, &x);
    printf("Question a: x=%d", x);
    TraverseStack(S);

    printf("\n");
    Pop(&S, &temp);
    Pop(&S, &x);
    Push(&S, x);
    Push(&S, temp);
    printf("Question b: x=%d", x);
    TraverseStack(S);

    printf("\n");
    for (i=0; i<n; i++)
    {
        Pop(&S, &x);
    }
    printf("Question c: x=%d", x);
    TraverseStack(S);

    printf("\n");
    CreateStack(&tempS);
    for (i=0; i<n; i++)
    {
        Pop(&S, &x);
        Push(&tempS, x);
    }
    printf("Question d: x=%d", x);
    while (!EmptyStack(tempS))
    {
        Pop(&tempS, &top);
        Push(&S, top);
    }
    TraverseStack(S);

    printf("\n");
    while (!EmptyStack(S))
    {
        Pop(&S, &x);
        Push(&tempS, x);
    }
    printf("Question e: x=%d", x);
    while (!EmptyStack(tempS))
    {
        Pop(&tempS, &top);
        Push(&S, top);
    }
    TraverseStack(S);

    printf("\n");
    while (S.Top>1)
    {
        Pop(&S, &x);
        Push(&tempS, x);
    }
    printf("Question f: x=%d", x);
    while (!EmptyStack(tempS))
    {
        Pop(&tempS, &x);
        Push(&S, x);
    }
    TraverseStack(S);

    printf("\n");
    while (!EmptyStack(S))
    {
        Pop(&S, &top);
    }
    printf("Question g: x=%d", x);
    TraverseStack(S);
}

void CreateStack(StackType *Stack)
/* Function: Creates an empty stack.
   Output:   An empty stack. */
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Input:    A stack Stack.
   Function: Checks if the Stack is empty.
   Output:   True if the Stack is empty, False otherwise.
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Input:    A stack Stack.
   Function: Checks if the Stack is full.
   Output:   True if the Stack is full, False otherwise.
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Input:    A stack Stack and an element Item.
   Function: Inserts the element Item into the stack Stack if the Stack is not full.
   Returns:  The modified Stack.
   Output:   A message indicating the stack is full, if the stack Stack is full.
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Input:    A stack Stack.
   Function: Removes the element Item from the top of the Stack if the Stack is not empty.
   Returns:  The element Item and the modified Stack.
   Output:   A message indicating the stack is empty if the Stack is empty.
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\ncount of stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
