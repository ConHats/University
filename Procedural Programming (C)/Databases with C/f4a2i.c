#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int ListElementType;            // type of elements in linked list (int)
typedef struct ListNode *ListPointer;   // type of node pointers
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

void intersection_list(ListPointer AList, ListPointer BList, ListPointer *FinalList);

int main()
{
   ListPointer AList, BList, FinalList, PredPtr;
   ListElementType item;
   int countA,i,countB;

   CreateList(&AList);
   CreateList(&BList);

   printf("Give the number of list1's elements: ");
   scanf("%d",&countA);

   for(i=0;i<countA;i++){
        PredPtr= NULL;
        printf("Enter the number to insert at the beginning of the list1: ");
        scanf("%d",&item);
        LinkedInsert(&AList, item, PredPtr);
   }

   printf("Give the number of list2's elements: ");
   scanf("%d",&countB);

   for(i=0;i<countB;i++){
        PredPtr= NULL;
        printf("Enter the number to insert at the beginning of the list2: ");
        scanf("%d",&item);
        LinkedInsert(&BList, item, PredPtr);
   }

   printf("1st list\n");
   LinkedTraverse(AList);
   printf("\n2st list\n");
   LinkedTraverse(BList);

   intersection_list(AList,BList,&FinalList);
   printf("\nFinal list\n");
   LinkedTraverse(FinalList);

   return 0;

}


void intersection_list(ListPointer AList, ListPointer BList, ListPointer *FinalList){
    ListPointer CurrPtr, PredPtr, CurrPtr2,Temp;
    boolean found;

    CreateList(&(*FinalList));
    CurrPtr=AList;

    while(CurrPtr!=NULL){
        CurrPtr2=BList;
        boolean Intersection=FALSE;

        while(CurrPtr2!=NULL && !Intersection){
            if (CurrPtr->Data==CurrPtr2->Data){
                LinearSearch(*FinalList,CurrPtr->Data,&PredPtr,&found);

                if (!found){
                    Temp=NULL;
                    LinkedInsert(&(*FinalList),CurrPtr2->Data,Temp);
                    Intersection=TRUE;
                }
            }
            CurrPtr2=CurrPtr2->Next;
        }
        CurrPtr=CurrPtr->Next;
    }
}


void CreateList(ListPointer *List)
/* Function: Creates an empty linked list.
   Returns:  The null pointer List.
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* Input:    A linked list with the List pointer pointing to the first node.
   Function: Checks if the linked list is empty.
   Returns:  True if the list is empty, and false otherwise.
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Input:    A linked list with the List pointer pointing to the first node, a data item Item, and a
             PredPtr pointer.
   Function: Inserts a node containing Item into the linked list after the node pointed to by PredPtr,
             or at the beginning of the list if PredPtr is NULL.
   Returns: The modified linked list with the first node pointed to List.
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
/* Input:    A linked list with the List pointer pointing to the first node, and a PredPtr pointer.
   Function: Deletes the node from the linked list that has its previous node pointed to by PredPtr,
             or deletes the first node if PredPtr is NULL, unless the list is empty.
   Returns:  The modified linked list with the first node pointed to by List.
   Output:   A message indicating an empty list if the linked list was empty.
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
/* Accepts:  A linked list with the List pointer pointing to the first node.
   Function: Traverses the linked list and processes each data element exactly once.
   Returns:  Depends on the type of processing performed
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
/* Input:    A linked list with the List pointer pointing to the first node.
   Function: Performs a linear search on the unordered linked list for a node containing the element Item.
   Returns:  If the search is successful, Found is true, CurrPtr points to the node containing the Item,
             and PredPtr points to its predecessor (or is nil if there is no predecessor). If the search is
             unsuccessful, Found is false.
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
/*Input:    An element Item and a sorted linked list, where the data elements are arranged in ascending
            order, and the List pointer points to the first node.
  Function: Performs a linear search on the sorted linked list for the first node that contains the element
            Item, or finds the position to insert a new node containing the Item.
  Returns:  If the search is successful, Found is true, CurrPtr points to the node containing Item, and
            PredPtr points to its predecessor (or nil if there is no predecessor). If the search is unsuccessful,
            Found is false.
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
