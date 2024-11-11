#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10     // size limit of the linked list
#define NilValue -1          // special null value indicating the end of the Linked List

typedef int ListElementType; // data type for the elements of the linked list,
                             // an integer type has been chosen as an example

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr);

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
void TraverseLinked(ListPointer List, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);

int main(){
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr, PredPtr;
    ListPointer AList;
    ListElementType AnItem;
    boolean found;
    char ch;
    int i;

    //A
    InitializeStoragePool(Node, &FreePtr);

    //B
    CreateList(&AList);

    //C
    printf("---------------Question C---------------\n");
    printf("---------------Storage pool---------------\n");
    printAll(AList, FreePtr, Node);

    //D
    printf("---------------Question D---------------\n");
    printf("---------------Linked list---------------\n");
    TraverseLinked(AList, Node);

    //E
    printf("---------------Question E---------------\n");
    do
    {
        printf("Give a number:");
        scanf("%d", &AnItem);
        printf("\n");

        found = Search(FreePtr, AList, Node, AnItem, &PredPtr);
        Insert(&AList, Node, &FreePtr, PredPtr, AnItem);

        printf("Continue Y/N:");
        do
        {
            scanf("%c", &ch);
        }
        while (toupper(ch) != 'N' && toupper(ch) != 'Y');
    }
    while (toupper(ch) != 'N');

    //F
    printf("---------------Question F---------------\n");
    printf("---------------Storage pool---------------\n");
    printAll(AList, FreePtr, Node);

    //G
    printf("---------------Question G---------------\n");
    printf("---------------Linked list---------------\n");
    TraverseLinked(AList, Node);

    //H
    printf("---------------Question H---------------\n");
    if (EmptyList(AList))
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Not an Empty List\n");
    }

    //I
    printf("---------------Question I---------------\n");
    if (FullList(AList))
    {
        printf("Full List\n");
    }
    else
    {
        printf("Not a Full List\n");
    }

    //J
    printf("---------------Question J---------------\n");
    printf("---------------Search for a number---------------\n");
    for (i=0; i<2; i++)
    {
        printf("Give a number ");
        scanf("%d", &AnItem);
        found = Search(FreePtr, AList, Node, AnItem, &PredPtr);
        if (found == TRUE)
        {
            printf("The number is in the list and its predecesser is in position %d\n", PredPtr);
        }
        else
        {
            printf("The number is not in the list\n");
        }
    }

    return 0;
}

boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr)
{
    boolean stop;
    boolean found;
    ListPointer current;

    stop = FALSE;
    found = FALSE;
    *PredPtr = NilValue;

    if (!EmptyList(List))
    {
        current = List;
        while (current != NilValue && !stop)
        {
            if (Node[current].Data>=Item)
            {
                stop = TRUE;
                found = (Node[current].Data==Item);
            }
            else
            {
                *PredPtr = current;
                current = Node[current].Next;
            }
        }
    }
    else
    {
        found = FALSE;
    }

    return found;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/*
   Input:     The array Node and the pointer FreePtr, which points to the first available
              node.
   Operation: Initializes the Node array as a linked list by linking successive entries
              of the array together, and initializes the FreePtr pointer.
   Returns:   The modified Node array and the FreePtr pointer to the first available node.
*/

{
    int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1; // It is not necessary to assign an initial value to the
        Node[i].Data=-1;  // data field, but it helps with printing.
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/*
   Function: Creates an empty linked list.
   Returns: A (null) pointer pointing to an empty list.

*/
{
    *List=NilValue;
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1st element of list=%d, 1st free position=%d\n", List, FreePtr);
    printf("Storage pool has the elements\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/*
   Inputs:    A linked list.
   Function:  Traverses the linked list if it is not empty.
   Output:    Depends on the processing.
*/

{
    ListPointer CurrPtr;

    if (!EmptyList(List))
    {
      CurrPtr = List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
    }
    else printf("Empty List ...\n");
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/*
   Input:      A linked list, the Node array, the PredPtr pointer, and an Item element.
   Function:   Inserts the Item element into the linked list, if it is not full,
               after the node pointed to by the PredPtr pointer.
   Returns:    The modified linked list, the modified Node array, and the FreePtr pointer.
   Output:     A message indicating that the list is full, if the linked list is full.
*/

{
    ListPointer TempPtr;
    GetNode(&TempPtr,FreePtr,Node);
    if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
    }
    else
    printf("Full List ...\n");
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/*
   Input:     The Node array and the FreePtr pointer.
   Function:  Acquires a "free" node pointed to by P.
   Returns:   The pointer P and the modified FreePtr pointer,
              which points to the first available node.
*/
{
    *P = *FreePtr;
    if (!FullList(*FreePtr))
        *FreePtr = Node[*FreePtr].Next;
}

boolean EmptyList(ListPointer List)
/*
   Input:      A pointer List that points to a linked list.
   Function:   Checks if the linked list is empty.
   Returns:    True if the linked list is empty, false otherwise.
*/
{
    return (List == NilValue);
}

boolean FullList(ListPointer FreePtr)
/*
   Input:      A linked list.
   Function:   Checks if the linked list is full.
   Returns:    True if the linked list is full, false otherwise.
*/
{
    return (FreePtr == NilValue);
}
