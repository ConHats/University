#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    int boxes;
    float weight;
    char date[10];
} StackElementType;

typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

void TraverseStack(StackPointer Stack);
int IndexOfMin(StackPointer Warehouse1, StackPointer Warehouse2, StackPointer Warehouse3);
int StackSize(StackPointer Warehouse);

int main()
{
   StackPointer Warehouse1,Warehouse2,Warehouse3;
   int n,i,min;
   StackElementType AnItem;

   CreateStack(&Warehouse1);
   CreateStack(&Warehouse2);
   CreateStack(&Warehouse3);

   printf("Number of cargoes: ");
   scanf("%d",&n);

   for (i=1;i<=n;i++){
        printf("Number of boxes for the %dst cargo: ",i);
        scanf("%d",&AnItem.boxes);
        printf("Total weight of %dst cargo: ",i);
        scanf("%f",&AnItem.weight);
        printf("Expiration date for the %dst cargo: ",i);
        scanf("%s",&AnItem.date);

        min=IndexOfMin(Warehouse1,Warehouse2,Warehouse3);
        if (min==1){
            Push(&Warehouse1,AnItem);
        }
        else if(min==2){
            Push(&Warehouse2,AnItem);
        }
        else {
            Push(&Warehouse3,AnItem);
        }
   }

   printf("WAREHOUSE 1\n");
   TraverseStack(Warehouse1);
   printf("WAREHOUSE 2\n");
   TraverseStack(Warehouse2);
   printf("WAREHOUSE 3\n");
   TraverseStack(Warehouse3);

	return 0;
}

int IndexOfMin(StackPointer Warehouse1, StackPointer Warehouse2, StackPointer Warehouse3){
    if ( ( StackSize(Warehouse1)<StackSize(Warehouse2) ) && ( StackSize(Warehouse1)<StackSize(Warehouse3))){
        return 1;
    }
    else if (  (StackSize(Warehouse2)<=StackSize(Warehouse1)) && (StackSize(Warehouse2)<StackSize(Warehouse3))){
        return 2;
    }
    else {
        return 3;
    }
}

int StackSize(StackPointer Warehouse){
    StackPointer CurrPtr;
    int count=0;

    CurrPtr=Warehouse;
    while (CurrPtr!=NULL){
        count=count+CurrPtr->Data.boxes;
        CurrPtr=CurrPtr->Next;
    }
    return count;

}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %.2f %s \n", CurrPtr->Data.boxes, CurrPtr->Data.weight, CurrPtr->Data.date);
             CurrPtr = CurrPtr->Next;
        }
   }
}


void CreateStack(StackPointer *Stack)
/* Function: Creates an empty linked stack.
   Returns:  An empty linked stack, Stack.
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Input:      A linked stack, Stack.
   Function:   Checks if the Stack is empty.
   Returns:    TRUE if the stack is empty, FALSE otherwise.
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Input:      A linked stack, with its top pointed to by the Stack pointer, and an
               element Item.
   Function:   Inserts the element Item at the top of the linked stack.
   Returns:    The modified linked stack.

*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Input:      A linked stack, with its top pointed to by the Stack pointer.
   Function:   Removes the element Item from the top of the linked stack, if the stack
               is not empty.
   Returns:    The modified linked stack and the element Item.
   Output:     A message indicating that the stack is empty, if the linked stack is
               empty.
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}


