#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NumberOfNodes 10    // limit of the linked list (50)

#define NilValue -1         // A special null value indicating the end of the linked list

//typedef int ListElementType2;   A data type for the elements of the linked list (int)
typedef int ListPointer;

typedef struct{
    char name[20];
    int school;
}ListElementType;

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
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType *Item);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main()
{
    int i=0, pos;
    FILE *fp = fopen("students.dat", "r");
    ListElementType AnItemA, AnItemB,item;
    NodeType Node[NumberOfNodes],Node2[NumberOfNodes];
    ListPointer FreePtrA, AList, PredPtrA, FreePtrB, BList, PredPtrB,CurrPtr;

    PredPtrA=NilValue;
    InitializeStoragePool(Node, &FreePtrA);
    CreateList(&AList);

    PredPtrB=NilValue;
    InitializeStoragePool(Node2, &FreePtrB);
    CreateList(&BList);

    if(fp== NULL){
        printf("Problem opening students.dat file.\n");
        system("Pause");
        return 0;
    }
    else {
        while(!feof(fp)&&(i<NumberOfNodes))
            {
                fscanf(fp, "%s", &AnItemA.name);
                //printf("%s\n", &AnItemA.name);
                fscanf(fp, "%d", &AnItemA.school);
                //printf("%d\n", AnItemA.school);
                Insert(&AList, Node,&FreePtrA, PredPtrA, AnItemA);
                i++;
            }
        fclose(fp);
    }

    printf("Question a:\n");
    printAll(AList,FreePtrA,Node);

    printf("List A\n");
    TraverseLinked(AList,Node);


    for(i=0;i<4;i++){
        do{
            printf("The position of the student who was called:");
            scanf(" %d", &pos);
        }while (!((pos>=0)&&(pos<10)));

        PredPtrA=NilValue;
        CurrPtr=AList;

        while(CurrPtr!=pos){
            PredPtrA=CurrPtr;
            CurrPtr=Node[CurrPtr].Next;
        }

        Delete(&AList,Node,&FreePtrA,PredPtrA,&item);
        Insert(&BList, Node2,&FreePtrB, PredPtrB, item);

        PredPtrB=BList;

        while (Node2[PredPtrB].Next!=NilValue){
            PredPtrB=Node2[PredPtrB].Next;
        }
    }


    printf("Question b\n");

    printAll(AList,FreePtrA,Node);
    printf("List A\n");
    TraverseLinked(AList,Node);

    printAll(BList,FreePtrB,Node2);
    printf("List B\n");
    TraverseLinked(BList,Node2);

    printf("Question c:\n");

    PredPtrB=NilValue;
    CurrPtr=BList;
    while (CurrPtr!=1){
        PredPtrB=CurrPtr;
        CurrPtr=Node2[CurrPtr].Next;
    }

    Delete(&BList,Node2,&FreePtrB,PredPtrB,&item);
    PredPtrA=NilValue;
    Insert(&AList, Node,&FreePtrA, PredPtrA, item);

    printAll(AList,FreePtrA,Node);
    printf("List A\n");
    TraverseLinked(AList,Node);

    printAll(BList,FreePtrB,Node2);
    printf("List B\n");
    TraverseLinked(BList,Node2);


system("Pause");
return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/*Input:      The Node array and the FreePtr pointer that points to the first available
              node.
  Function:   Initializes the Node array as a linked list by connecting successive
              entries of the array, and initializes the FreePtr pointer.
  Returns:    The modified Node array and the FreePtr pointer pointing to the first
              available node.
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        //Node[i].Data=-1;    // Not necessary to assign an initial value to the data
                              // field, but it helps in printing.
        strcpy(Node[i].Data.name, " ");
        Node[i].Data.school=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    strcpy(Node[NumberOfNodes-1].Data.name, " ");
    Node[NumberOfNodes-1].Data.school=-1;
   // Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* Function:    Creates an empty linked list.
   Returns:     A (null) pointer indicating an empty list.
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* Input:       A pointer, List, pointing to a linked list.
   Function:    Checks if the linked list is empty.
   Returns:     True if the linked list is empty, false otherwise.
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* Input:       A linked list.
   Function:    Checks if the linked list is full.
   Returns:     True if the linked list is full, false otherwise.
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Input:       The Node array and the FreePtr pointer.
   Function:    Acquires a "free" node, indicated by the pointer P.
   Returns:     The pointer P and the modified FreePtr, which points to the next
                available node.
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Input:       The Node array, representing the pool of available nodes,
                a pointer TempPtr, and the pointer FreePtr.
   Function:    Returns to the pool the node pointed to by TempPtr.
   Returns:     The modified Node array and the FreePtr pointer.
*/
{
  Node[P].Next =*FreePtr;
  strcpy(Node[P].Data.name, " ");
    Node[P].Data.school=-1;

  //Node[P].Data = -1;  Not a necessary command, auxiliary to display deleted nodes
  //                    in the output.
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Input:      A linked list, the array Node, the pointer PredPtr, and an element Item.
   Function:   Inserts the element Item into the linked list, if it is not full, after
               the node pointed to by PredPtr.
   Returns:    The modified linked list, the updated Node array, and the FreePtr
               pointer.
   Output:     A "list full" message if the linked list is full.
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

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType *Item)
/* Input:      A linked list and the pointer PredPtr, which points to the node
               preceding the one to be deleted.
   Function:   Deletes from the linked list, if it is not empty, the node preceding
               the one pointed to by PredPtr.
   Returns:    The modified list and the FreePtr pointer.
   Output:     An empty list message if the linked list is empty.
*/
{
  ListPointer TempPtr ;

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        *Item=Node[TempPtr].Data;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        *Item=Node[TempPtr].Data;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* Input:      A linked list.
   Function:   Traverses the linked list, if it is not empty.
   Output:     Depends on the type of processing.
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: < %s, %.d> ->%d) ",CurrPtr,Node[CurrPtr].Data.name, Node[CurrPtr].Data.school, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1st item of list=%d, 1st free position=%d\n", List, FreePtr);
    printf("Storage pool has the following items\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:< %s, %d> ->%d) ", i, Node[i].Data.name, Node[i].Data.school, Node[i].Next);
    printf("\n");
}
