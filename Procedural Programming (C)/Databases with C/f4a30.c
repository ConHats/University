#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10
#define StackLimit 5
#define NilValue -1

typedef int StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef struct {
    int AM;
    float grade;
} ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
void TraverseLinked(ListPointer List, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
void Push(StackType *Stack, StackElementType Item);
boolean FullStack(StackType Stack);
void TraverseStack(StackType Stack);

float FindMaxs(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);

int main(){
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr, PredPtr;
    ListPointer AList;
    ListElementType Student;
    int i;
    float maximum;
    StackType AStack;
    StackElementType StackItem;


    InitializeStoragePool(Node, &FreePtr);
    CreateList(&AList);

    printAll(AList, FreePtr, Node);

    printf("Question 4\n");
    printf("Linked list\n");
    TraverseLinked(AList, Node);

    printf("Question 5\n");
    for (i=0; i<StackLimit; i++)
    {
        printf("Give an AM to insert in the list: ");
        scanf("%d", &Student.AM);
        printf("give a grade to insert in the list: ");
        scanf("%f", &Student.grade);
        PredPtr=NilValue;
        Insert(&AList, Node, &FreePtr, PredPtr, Student);
    }

    printf("Question 6\n");
    printf("Storage pool\n");
    printAll(AList, FreePtr, Node);

    printf("Question 7\n");
    printf("Linked list\n");
    TraverseLinked(AList, Node);

    printf("Question 8\n");
    if (EmptyList(AList))
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Not an Empty List\n");
    }

    printf("Question 9\n");
    if (FullList(AList))
    {
        printf("Full List\n");
    }
    else
    {
        printf("Not a Full List\n");
    }

    printf("Question 10\n");
    maximum = FindMaxs(AList, Node, &AStack);
    printf("Max grade=%.1f\n", maximum);

    printf("AM with max grade:");
    while (!EmptyStack(AStack))
    {
        Pop(&AStack, &StackItem);
        printf(" %d", StackItem);
    }
    printf("\n");

    printf("Question 11\n");
    TraverseStack(AStack);

    printf("Question 12\n");
    printf("Storage pool\n");
    printAll(AList, FreePtr, Node);

    printf("Question 13\n");
    printf("Linked list\n");
    TraverseLinked(AList, Node);

    return 0;
}

float FindMaxs(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack)
{
    float max;
    ListPointer CurrPtr;
    StackElementType stit;

    CreateStack(Stack);

    if (!EmptyList(List))
    {
        CurrPtr = List;
        max = Node[0].Data.grade;;

        while (CurrPtr != NilValue)
        {
            if (Node[CurrPtr].Data.grade >= max)
            {
                if (Node[CurrPtr].Data.grade > max)
                {
                    while (!EmptyStack(*Stack))
                    {
                        Pop(Stack, &stit);
                    }
                    max = Node[CurrPtr].Data.grade;
                }
                Push(Stack, Node[CurrPtr].Data.AM);
            }
            CurrPtr = Node[CurrPtr].Next;
        }
    }
    else
    {
        printf("Empty List ...\n");
    }

    return max;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
    int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.AM=-1;
        Node[i].Data.grade=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.AM=-1;
    Node[NumberOfNodes-1].Data.grade=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
{
    *List=NilValue;
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1st element of list=%d, 1st Free Position=%d\n", List, FreePtr);
    printf("Storage pool has the elements:\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f> ->%d) ",i,Node[i].Data.AM,Node[i].Data.grade, Node[i].Next);
    printf("\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
{
    ListPointer CurrPtr;

    if (!EmptyList(List))
    {
        CurrPtr = List;
        while (CurrPtr != NilValue)
        {
            printf("(%d:<%d,%.1f>->%d) ",CurrPtr,Node[CurrPtr].Data.AM,Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
            CurrPtr=Node[CurrPtr].Next;
        }
        printf("\n");
    }
    else
    {
       printf("Empty List ...\n");
    }
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
{
    ListPointer TempPtr;
    GetNode(&TempPtr,FreePtr,Node);
    if (!FullList(TempPtr))
    {
        if (PredPtr==NilValue)
        {
            Node[TempPtr].Data.AM =Item.AM;
            Node[TempPtr].Data.grade =Item.grade;
            Node[TempPtr].Next =*List;
            *List =TempPtr;
        }
        else
          {
            Node[TempPtr].Data.AM =Item.AM;
            Node[TempPtr].Data.grade =Item.grade;
            Node[TempPtr].Next =Node[PredPtr].Next;
            Node[PredPtr].Next =TempPtr;
          }
    }
    else
    {
        printf("Full List ...\n");
    }
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
{
    *P = *FreePtr;
    if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

boolean EmptyList(ListPointer List)
{
    return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
{
    return (FreePtr == NilValue);
}

void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
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
