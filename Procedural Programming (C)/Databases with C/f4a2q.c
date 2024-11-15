#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int ListElementType;
typedef struct ListNode *ListPointer;
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void UniqueList(ListPointer InList, ListPointer *OutList);

int main()
{
    ListPointer List, FinalList, PredPtr;
    ListElementType item;
    int count,i;

    CreateList(&List);

    printf("Give the number of elements in the list: ");
    scanf("%d",&count);

    for(i=0;i<count;i++)
    {
        PredPtr= NULL;
        printf("Enter the number to insert at the top of the list: ");
        scanf("%d",&item);
        LinkedInsert(&List, item, PredPtr);
    }

    printf("Initial list\n");
    LinkedTraverse(List);

    UniqueList(List, &FinalList);

    printf("\nFinal list\n");
    LinkedTraverse(FinalList);

    return 0;
}

void UniqueList(ListPointer InList, ListPointer *OutList)
{
    ListPointer CurrPtr, LastPtr;

    if(!EmptyList(InList))
    {
        CreateList(OutList);
        CurrPtr=InList;
        LinkedInsert(&(*OutList),CurrPtr->Data,NULL);
        CurrPtr=CurrPtr->Next;
        LastPtr=*OutList;
        while(CurrPtr!=NULL)
        {
            if(CurrPtr->Data!=LastPtr->Data)
            {
                LinkedInsert(&(*OutList),CurrPtr->Data,LastPtr);
                LastPtr=LastPtr->Next;
            }
            CurrPtr=CurrPtr->Next;
        }
    }
    else
    {
        printf("EMPTY LIST");
    }
}

void CreateList(ListPointer *List)
/* Function: Creates an empty linked list.
   Returns:  The null pointer List:
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* Input:    A linked list with List pointing to the first node.
   Function: Checks if the linked list is empty.
   Returns:  True if the list is empty, and false otherwise
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Input:    A linked list with List pointing to the first node, a data element Item, and a pointer PredPtr.
   Function: Inserts a node containing Item into the linked list after the node pointed to by PredPtr,
             or at the beginning of the linked list if PredPtr is NULL.
   Returns:  The modified linked list with the first node pointed to by List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
/* Input:    A linked list with List pointing to the first node, and a pointer PredPtr.
   Function: Deletes the node from the linked list that has its previous node pointed to by PredPtr,
             or deletes the first node if PredPtr is NULL, unless the list is empty.
   Returns:  The modified linked list with the first node pointed to by List.
   Output:   A message indicating the list is empty if the linked list was empty.
*/
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
/* Input:    A linked list with List pointing to the first node.
   Function: Traverses the linked list and processes each data exactly once.
   Returns:  Depends on the type of processing.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
   	    //printf("%-16s\t%-4s\t%-16s\n", "CurrPtr","Data","Next");
         while ( CurrPtr!=NULL )
        {
            printf("%d ",(*CurrPtr).Data);
             //printf("%p\t%d\t%p\n",CurrPtr,(*CurrPtr).Data, (*CurrPtr).Next);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* Accepts:  A linked list with List pointing to the first node.
   Function: Performs a linear search on the unsorted linked list for a node containing the item Item.
   Returns:  If the search is successful, Found is true, CurrPtr points to the node containing Item,
             and PredPtr points to its predecessor, or is nil if there is no predecessor. If the search
             is unsuccessful, Found is false
*/
{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* Input:    An element Item and a sorted linked list with elements in ascending order, where the List pointer points to
             the first node.
   Function: Performs a linear search on the sorted linked list for the first node containing the element Item, or finds
             the position to insert a new node containing the element Item.
   Returns:  If the search is successful, Found is true, CurrPtr points to the node containing Item, and PredPtr points to
             its predecessor, or is nil if there is no predecessor. If the search is unsuccessful, Found is false.
*/
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}
