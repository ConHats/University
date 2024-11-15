#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int ListElementType;            //type of elements in linked list (int)
typedef struct ListNode *ListPointer;   //type of node pointers
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
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void list_insertion(ListPointer *List, int choice1);

void delete_n_element(ListPointer *List, int n);

int main()
{  ListPointer AList, PredPtr;
   int i, n, number;
   ListElementType AnItem;

    CreateList(&AList);

    printf("Give the number of list's elements: ");
    scanf("%d",&number);
    if (number==0) {

        system("Pause");
        return 0;
    }

   for(i=0;i<number;i++){
        PredPtr= NULL;
        printf("Enter the number to insert at the beginning of the list: ");
        scanf("%d",&AnItem);
        LinkedInsert(&AList, AnItem, PredPtr);
   }
   /*
    do{
        printf("Give the element's position to delete: ");
        scanf("%d", &n);
    } while (!((n>0)&&(n<=number)));
    */

    boolean validpos=FALSE;

    do{
        printf("Give the element's position to delete: ");
        scanf("%d", &n);
        if ((n>0)&&(n<=number))  validpos=TRUE;
        else printf("Not valid number. Give a position from 1 to %d.\n", number);
        } while(!validpos);



    printf("Initial list\n");
    LinkedTraverse(AList);
    delete_n_element(&AList, n);
    printf("\nFinal list\n");
    LinkedTraverse(AList);
    printf("\n");

system("Pause");
return 0;
}

void delete_n_element(ListPointer *List, int n)
{ ListPointer TempPtr, PrevPtr;
int i;
    if(!EmptyList(*List))
    {   if(n==1) {
           TempPtr = *List;
           *List = TempPtr->Next;
    } else{
        i=2;
        PrevPtr=*List;
        TempPtr=PrevPtr->Next;
        while(i<n)
        { PrevPtr=TempPtr;
            TempPtr=TempPtr->Next;
            i++;
        }
        PrevPtr->Next = TempPtr->Next;
    }
     free(TempPtr);
    } else{
        printf("Empty list\n");
    }
}

void list_insertion(ListPointer *List,int choice1)
{
 	ListElementType Item;
    char ch;
    ListPointer PredPtr;
    boolean Found;

	do
    {
   	    printf("Enter a number for insertion in the list: "); scanf("%d", &Item);
   	    if (choice1==1)
   	        OrderedLinearSearch(*List, Item, &PredPtr, &Found);
   	    else
            PredPtr= NULL;
        LinkedInsert(List, Item, PredPtr);
        printf("\nContinue Y/N: ");
        do
        {
      	     scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');
}

void CreateList(ListPointer *List)
/* Function: Creates an empty linked list.
   Returns:  The null pointer List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* Input:    A linked list with List pointing to the first node.
   Function: Checks if the linked list is empty.
   Returns:  TRUE if the list is empty, and FALSE otherwise.
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Input:    A linked list with List pointing to the first node, an item Item, and a pointer PredPtr.
   Function: Inserts a node containing Item into the linked list after the node pointed to by PredPtr,
             or at the beginning of the linked list if PredPtr is null.
   Returns:  The modified linked list with List pointing to the first node.
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
/* Input:    A linked list with List pointing to the first node and a pointer PredPtr.
   Function: Deletes the node from the linked list that has the node pointed to by PredPtr as
             its previous node, or deletes the first node if PredPtr is null, unless the list is empty.
   Returns:  The modified linked list with List pointing to the first node.
   Output:   A message indicating an empty list if the linked list was empty.
*/
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr==NULL)
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
   Function: Traverses the linked list and processes each data element exactly once.
   Returns:  Depends on the type of processing
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
         while ( CurrPtr!=NULL )
        {
      	     //printf("%c", CurrPtr->Data);
      	     printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* Input:    A linked list with List pointing to the first node.
   Function: Performs a linear search on the unsorted linked list for a node containing the element Item.
   Returns:  If the search is successful, Found is TRUE, CurrPtr points to the node containing the Item,
             and PredPtr points to the previous node or is NULL if there is no previous node. If the search
             is unsuccessful, Found is FALSE.
*/
{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
   *PredPtr = NULL;
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
/* Input:    An element Item and a sorted linked list that contains data elements in ascending order, where
             the pointer List points to the first node.
   Function: Performs a linear search on the sorted linked list for the first node that contains the element
             Item, or finds a position to insert a new node with the Item element.
   Returns:  If the search is successful, Found is TRUE, CurrPtr points to the node containing the Item, and
             PredPtr points to the previous node, or is NULL if there is no previous node. If the search is
             unsuccessful, Found is FALSE.
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
