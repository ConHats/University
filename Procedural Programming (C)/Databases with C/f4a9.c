#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define StackLimit 40
#define QueueLimit 40

typedef char StackElementType;
typedef char QueueElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
boolean FullStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
void TraverseStack(StackType Stack);
void TraverseQ(QueueType Queue);

int main()
{
    int i;
    StackType AStack;
    QueueType AQueue;
    char str[40];
    char ch1, ch2;
    boolean flag;

    CreateStack(&AStack);
    CreateQ(&AQueue);

    printf("Give the string: ");
    gets(str);

    for(i=0; i<strlen(str); i++)
    {
        Push(&AStack, str[i]);
        AddQ(&AQueue, str[i]);
    }

    printf("-------Stack of characters-------\n");
    TraverseStack(AStack);
    printf("-------Queue of characters-------\n");
    TraverseQ(AQueue);

    i=0;
    flag=TRUE;
    while (flag==TRUE && str[i]!='\0')
    {
        Pop(&AStack, &ch1);
        RemoveQ(&AQueue, &ch2);
        if (ch1!=ch2)
        {
            flag=FALSE;
        }
        i++;
    }

    if (flag==FALSE)
    {
        printf("%s REJECTED", str);
    }
    else
    {
        printf("%s ACCEPTED", str);
    }
    return 0;
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit; ;
	}
	else
		printf("Full Queue");
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

void TraverseStack(StackType Stack)
{
    int i;
    for (i=Stack.Top;i>=0;i--) {
        printf("%c ", Stack.Element[i]);
    }
    printf("\n");
}

void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%c ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}
