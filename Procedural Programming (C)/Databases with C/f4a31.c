// Filename ListADT.h
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 25     //  size limit of the linked list
#define NumberOfNodes2 10
#define NilValue -1          // special null value indicating the end of
                             // the linked list

typedef int ListElementType; // data type for the elements of the linked list

typedef int ListPointer;


typedef struct{
    int Class;
    int frequency;
}ListElementType2;

typedef struct{
    ListElementType2 Data;
    ListPointer  Next;
}NodeType2;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);

void InitializeStoragePool2(NodeType2 Node[], ListPointer *FreePtr);
void CreateList2(ListPointer *List);
boolean EmptyList2(ListPointer List);
boolean FullList2(ListPointer FreePtr);
void GetNode2(ListPointer *P, ListPointer *FreePtr, NodeType2 Node2[]);
void ReleaseNode2(NodeType2 Node2[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert2(ListPointer *List, NodeType2 Node[],ListPointer *FreePtr, ListPointer PredPtr, int ena, int duo);
void Delete2(ListPointer *List, NodeType2 Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked2(ListPointer List, NodeType2 Node2[]);


void GetFrequencies(ListPointer List,NodeType Node[], ListPointer List2, NodeType2 Node2[]);

int main()
{
    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;
    ListElementType AItem;

    ListPointer BList;
    NodeType2 Node2[NumberOfNodes];
    ListPointer FreePtr2,PredPtr2;
    ListElementType2 BItem;

    int i,count;

   InitializeStoragePool(Node, &FreePtr);
   CreateList(&AList);

   InitializeStoragePool2(Node2, &FreePtr2);
   CreateList2(&BList);

   for(i=0; i<10; i++){
       BItem.Class=i;
       BItem.frequency=0;

       PredPtr2=NilValue;
       Insert2(&BList, Node2,&FreePtr2, PredPtr2, BItem.Class, BItem.frequency);
   }


   do {
    printf("Enter observations number: ");
    scanf("%d",&count);
   }while (!(count<=25 && count>0));

   for(i=0;i<count;i++){
       do {
            printf("Enter an observation in [0,9]:");
            scanf("%d",&AItem);
       }while (!(AItem>=0 && AItem<=9));
       PredPtr=NilValue;
       Insert(&AList, Node, &FreePtr, PredPtr, AItem);
   }

   printf("1st List of Observations\n");
   TraverseLinked(AList, Node);

   GetFrequencies(AList,Node,BList,Node2);
   printf("2nd List of Frequencies\n");
   TraverseLinked2(BList, Node2);



}

void GetFrequencies(ListPointer List,NodeType Node[], ListPointer List2, NodeType2 Node2[]){
    if (!EmptyList(List)){
        ListPointer CurrPtr1, CurrPtr2;
        int thisValue;

        CurrPtr1=List;
        while (CurrPtr1!=NilValue){
            thisValue=Node[CurrPtr1].Data;
            CurrPtr2=List2;
            while (CurrPtr2!=NilValue){
                if (Node2[CurrPtr2].Data.Class==thisValue){
                    Node2[CurrPtr2].Data.frequency=Node2[CurrPtr2].Data.frequency+1;
                    break;
                }
                else{
                    CurrPtr2=Node2[CurrPtr2].Next;
                }
            }
            CurrPtr1=Node[CurrPtr1].Next;
        }
    }
    else{
       printf("Empty List ...\n");
    }

}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* Input:    The Node array and the FreePtr pointer that points to the first available
             node.
   Function: Initializes the Node array as a linked list by connecting consecutive
             entries of the array, and initializes the FreePtr pointer.
   Returns:  The modified Node array and the FreePtr pointer to the first available
             node.
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;    /* It is not necessary to assign an initial value to
                               the data field; it helps with printing*/
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* Function: Creates an empty linked list.
   Returns:  A (null) pointer that points to an empty list.
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* Input:    A pointer List that points to a linked list.
   Function: Checks if the linked list is empty.
   Returns:  True if the linked list is empty, and false otherwise.
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* Input:    A linked list.
   Function: Checks if the linked list is full.
   Returns:  True if the linked list is full, and false otherwise.
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Input:    The Node array and the FreePtr pointer.
   Function: Acquires a 'free' node pointed to by the pointer P.
   Returns:  The pointer P and the modified FreePtr, which points to the first available node.
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Input:    The Node array, which represents the pool of available nodes,
             a pointer TempPtr, and the FreePtr pointer.
   Function: Returns the node pointed to by TempPtr to the pool.
   Returns:  The modified Node array and the FreePtr pointer.
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data = -1;    /* Not a necessary command, auxiliary to display the deleted
                           nodes in the printout */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Accepts:  A linked list, the Node array, the PredPtr pointer, and an Item element.
   Function: If the list is not full, inserts the Item element into the linked list
             after the node pointed to by the PredPtr pointer.
   Returns:  The modified linked list, the modified Node array, and the FreePtr pointer.
   Output:   A "full list" message if the linked list is full.
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

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* Accepts:  A linked list and the PredPtr pointer, which points to the previous node
             of the one to be deleted.
   Function: If the list is not empty, deletes the previous node of the one pointed to
             by the PredPtr pointer from the linked list.
   Returns:  The modified list and the FreePtr pointer.
   Output:   A "empty list" message if the linked list is empty.
*/
{
  ListPointer TempPtr ;

  if (!EmptyList(*List)) {
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
      }
      ReleaseNode(Node,TempPtr,FreePtr);
  }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* Accepts:  A linked list.
   Function: Traverses the linked list, if it is not empty.
   Output:   Depends on the processing.
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d) ",Node[CurrPtr].Data);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else{
    printf("Empty List ...\n");
  }
}

void InitializeStoragePool2(NodeType2 Node[], ListPointer *FreePtr)
/* Accepts:  The Node array and the FreePtr pointer that points to the first available
             node.
   Function: Initializes the Node array as a linked list by connecting consecutive
             entries in the array, and initializes the FreePtr pointer.
   Returns:  The modified Node array and the FreePtr pointer pointing to the first
             available node.
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.Class=-1;    /* It is not necessary to assign an initial value to
                                     the data field, but it helps with printing*/
        Node[i].Data.frequency=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.Class=-1;
    Node[NumberOfNodes-1].Data.frequency=-1;
    *FreePtr=0;
}

void CreateList2(ListPointer *List)
/* Function: Creates an empty linked list.
   Returns:  A (null) pointer that points to an empty list.
*/
{
  *List=NilValue;
}

boolean EmptyList2(ListPointer List)
/* Input:    A pointer List that points to a linked list.
   Function: Checks if the linked list is empty.
   Returns:  True if the linked list is empty, and False otherwise.
*/
{
  return (List==NilValue);
}

boolean FullList2(ListPointer FreePtr)
/* Input:    A linked list.
   Function: Checks if the linked list is full.
   Returns:  True if the linked list is full, and False otherwise.
*/
{
  return (FreePtr == NilValue);
}

void GetNode2(ListPointer *P, ListPointer *FreePtr, NodeType2 Node2[])
/* Input:    The Node array and the FreePtr pointer.
   Function: Acquires a "free" node pointed to by the pointer P.
   Returns:  The pointer P and the modified FreePtr pointer, which points to the first
             available node.
*/
{
  *P = *FreePtr;
  if (!FullList2(*FreePtr))
    *FreePtr =Node2[*FreePtr].Next;
}

void ReleaseNode2(NodeType2 Node2[], ListPointer P, ListPointer *FreePtr)
/* Input:    The Node array, which represents the pool of available nodes, a pointer
             TempPtr, and the FreePtr pointer.
   Function: Returns the node pointed to by TempPtr back to the pool.
   Returns:  The modified Node array and the FreePtr pointer.
*/
{
  Node2[P].Next =*FreePtr;
  //Node2[P].Data = -1;     Not a necessary command, auxiliary to display the
                        //  deleted nodes in the printout.
  *FreePtr =P;
}


void Insert2(ListPointer *List, NodeType2 Node[],ListPointer *FreePtr2, ListPointer PredPtr2, int ena, int duo)
/* Input:    A linked list, the array Node, the pointer PredPtr, and an element Item.
   Function: Inserts the element Item into the linked list, if it is not full, after
             the node pointed to by PredPtr.
   Returns:  The modified linked list, the modified Node array, and the pointer FreePtr.
   Output:   A message indicating the list is full if the linked list is full.
*/
{
  ListPointer TempPtr;
  GetNode2(&TempPtr,FreePtr2,Node);
  if (!FullList2(TempPtr)) {
    if (PredPtr2==NilValue)
    {
        Node[TempPtr].Data.Class =ena;
        Node[TempPtr].Data.frequency =duo;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data.Class =ena;
        Node[TempPtr].Data.frequency =duo;
        Node[TempPtr].Next =Node[PredPtr2].Next;
        Node[PredPtr2].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}


void TraverseLinked2(ListPointer List, NodeType2 Node2[])
/* Input:    A linked list.
   Function: Traverses the linked list, if it is not empty.
   Output:   Depends on the processing.
*/
{
  ListPointer CurrPtr;

  if (!EmptyList2(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d:%d) ",Node2[CurrPtr].Data.Class, Node2[CurrPtr].Data.frequency);
          CurrPtr=Node2[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}



