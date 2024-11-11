#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define QueueLimit 22
#define StackLimit 21


typedef float QueueElementType;
typedef float StackElementType;


typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;


typedef struct
{
    int Top;
    StackElementType Element[StackLimit];
} StackType;


typedef enum {FALSE, TRUE} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void ReverseQ(QueueType *Queue);


int main()
{
    QueueType Queue;
    QueueElementType AnItem, i;
    float x=0.00;
    CreateQ(&Queue);
    for(i=-1;i<20;i++)
    {
        AddQ(&Queue, x);
        x+=0.5;
    }
    TraverseQ(Queue);

    printf("\nReverse Queue\n");
    ReverseQ(&Queue);
    TraverseQ(Queue);

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
		printf("Empty Queue\n");
}


void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}


void TraverseQ(QueueType Queue)
{
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear)
	    {
	        printf("%.2f ", Queue.Element[current]);
            current = (current + 1) % QueueLimit;
        }
        printf("\n");
    }
    else printf("Empty Queue\n");
}


void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
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

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}


boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}


void ReverseQ(QueueType *Queue)
{
    StackType Stack;
    CreateStack(&Stack);

    float x=0.00;

    while(!EmptyQ(*Queue))
    {
        RemoveQ(Queue, &x);
        Push(&Stack, x);
        x+=0.5;
    }

    while(!EmptyStack(Stack))
    {
        Pop(&Stack, &x);
        AddQ(Queue, x);
        x+=0.5;
    }
}
