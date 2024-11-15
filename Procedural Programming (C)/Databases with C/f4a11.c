#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MaxWord 15

typedef int StackElementType;           //type of stack's elements (int)
typedef struct StackNode *StackPointer;

typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef struct{
 char userid[9];
} QueueElementType;                     //type of Queue's elements (int)
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef char ListElementType[MaxWord];  //type of Linked List's elements (string)
typedef struct ListNode *ListPointer;   //type of node's pointers
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);


void GetAWord(FILE* TextFile, ListElementType Word, boolean *MoreWords);
void TraverseStack(StackPointer Stack);
void TraverseQ(QueueType Queue);

boolean search_for_userid(QueueElementType item);

int main(){

StackPointer AStack;
int choice;
StackElementType AnItem;
QueueType AQueue, BQueue;
QueueElementType item;
QueueType admQ;
QueueType usrQ;
QueuePointer currPtr;
boolean flag;
char myinput;
int user;

CreateQ(&usrQ);
CreateQ(&admQ);
do{
    printf("USERNAME: ");
    scanf("%s", item.userid);
    getchar();
    if(search_for_userid(item)==FALSE)
    {
        printf("Wrong user ID\n");
    }else{
        if(strncmp(item.userid,"USR",3)==0) //Simple user
        { currPtr = usrQ.Front;
            user=1;
        }else{
            currPtr = admQ.Front;
            user=2;
        }
        flag= FALSE;
        while(currPtr!=NULL && flag==FALSE)
        {
            if(strcmp(item.userid, currPtr->Data.userid)==0)
            {printf("You have logged in to the system from another terminal. New access is forbidden.\n");
                flag = TRUE;
        }else{
            currPtr = currPtr->Next;
        }
    }
    //////////
    if(flag==FALSE){
        if(user==1){
            AddQ(&usrQ, item);
        }else{
            AddQ(&admQ, item);
        }
    }


    }
   //////

    do{
        printf("New insertion Y/N (Y=yes, N=No)");
        scanf("%c", &myinput);
        getchar();
    }while(toupper(myinput)!='Y' && toupper(myinput)!='N');

}while(toupper(myinput!='N'));

printf("Queue of Admins\n");
TraverseQ(admQ);
printf("Queue of users\n");
TraverseQ(usrQ);
system("Pause");
return (0);
}

boolean search_for_userid(QueueElementType item){
 FILE *fp;
QueueElementType str;
 if((fp = fopen("I11F4.dat", "r")) == NULL)
 printf("PROBLEM OPENING FILE\n");
 else {
    while(!feof(fp)){
        fscanf(fp, "%s", str.userid);
        if(strcmp(str.userid, item.userid) == 0){
            fclose(fp);
            return TRUE;
            }
        }
    }
 fclose(fp);
 return FALSE;
}

void GetAWord(FILE* TextFile, ListElementType Word, boolean *MoreWords)
/* Input:      A file TextFile.
   Function:   Detects the next word Word in the TextFile.
   Returns:    The word Word (string) and MoreWords, which is TRUE if there
               are more words in the file,and FALSE if there are no more words.
*/

{
  int i;
  char Ch;
  boolean more;

  more=FALSE; /* Helper, to avoid working with a pointer,
              instead of the pointer *MoreWords*. */

  //Identifies the first character of a new word.
  while ((!more) && (!feof(TextFile)))
  {
      Ch=fgetc(TextFile);
      Ch=toupper(Ch);
      if (Ch>='A' && Ch<='Z') more=TRUE;
  }
   /* If a word is found, it copies the first character into the string Word,
   and for the remaining characters, it places the null character '\0'.*/
   if (more)
   {
      Word[0]=Ch;
      for (i=1; i<MaxWord;i++)
        Word[i]='\0';
      i=0;

      if (!feof(TextFile))
      {
          Ch=getc(TextFile);
          Ch=toupper(Ch);
      }

      /* Reads the remaining characters of the word from the file
      and copies them into the string Word.*/
      while ((Ch>='A' && Ch<='Z') && (!feof(TextFile)))
      {
          i=i+1;
          Word[i]=Ch;
          Ch=getc(TextFile);
          Ch=toupper(Ch);
      }
    }
   *MoreWords=more;
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
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
        while ( CurrPtr!=NULL )
        {
      	     printf("%s \n", CurrPtr->Data.userid);
             CurrPtr = CurrPtr->Next;
        }
   }
}


void CreateStack(StackPointer *Stack)
/* Function:   Creates an empty linked stack.
   Returns:    An empty linked stack, Stack.
*/

{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Input:      A linked queue.
   Function:   Checks if the linked queue is empty.
   Returns:    True if the queue is empty, false otherwise.
*/


{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Input:      A linked stack with its top pointed to by the Stack pointer and an element Item.
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
/* Input:      A linked stack with its top pointed to by the Stack pointer.
   Function:   Removes the element Item from the top of the linked stack,
               if the stack is not empty.
   Returns:    The modified linked stack and the element Item.
   Output:     A message indicating that the stack is empty,
               if the linked stack is empty.
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


void CreateQ(QueueType *Queue)
/* Function:   Creates an empty linked queue.
   Returns:    An empty linked queue.
*/
{
	(*Queue).Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Input:      A linked queue.
   Function:   Checks if the linked queue is empty.
   Returns:    True if the queue is empty, false otherwise.
*/

{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Input:      A linked queue Queue and an element Item.
   Function:   Adds the element Item to the end of the linked queue Queue.
   Returns:    The modified queue.
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Input:      A linked queue.
   Function:   Removes the element Item from the front of the linked queue,
               if it is not empty.
   Returns:    The element Item and the modified linked queue.
   Output:     A message indicating that the queue is empty if the queue is empty.
*/

{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}


void CreateList(ListPointer *List)
/* Function:   Creates an empty linked list.
   Returns:    The null pointer List.
*/

{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* Input:      A linked list with List pointing to the first node.
   Function:   Checks if the linked list is empty.
   Returns:    True if the list is empty, and false otherwise.

*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Input:    A linked list with List pointing to the first node, an element Item,
             and a pointer PredPtr.
   Function: Inserts a node containing Item into the linked list after the node
             pointed to by PredPtr, or at the beginning of the linked list if
             PredPtr is NULL.
   Returns:  The modified linked list with List pointing to the first node.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   //TempPtr->Data = Item;
   strcpy(TempPtr->Data,Item);
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
/*Input:      A linked list with List pointing to the first node, and a pointer PredPtr.
  Function:   Deletes the node from the linked list that has the node pointed to by
              PredPtr as its previous node,or deletes the first node if PredPtr is
              NULL, unless the list is empty.
  Returns:    The modified linked list with List pointing to the first node.
  Output:     A message indicating an empty list if the linked list was empty.
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
/* Input:      A linked list with List pointing to the first node.
   Function:   Traverses the linked list and processes each data element exactly once.
   Returns:    Depends on the type of processing.
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
      	     printf("%s ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
        printf("\n");
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* Input:      A linked list with List pointing to the first node.
   Function:   Performs a linear search on the unsorted linked list for a node that
               contains the element Item.
   Returns:    If the search is successful, Found is true, CurrPtr points to the node
               containing the Item, and PredPtr points to the previous node, or is nil
               if there is no previous node. If the search is unsuccessful, Found is false.
*/

{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
   *PredPtr = NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (strcmp(CurrPtr->Data,Item)==0 )
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
/* Input:      An element Item and a sorted linked list, which contains data elements
               in ascending order and where the pointer List points to the first node.
   Function:   Performs a linear search on the sorted linked list for the first node
               that contains the element Item or for a position to insert a new node
               that contains the element Item.
   Returns:    If the search is successful, Found is true, CurrPtr points to the node
               containing the Item, and PredPtr points to the previous node, or is nil
               if there is no previous node.If the search is unsuccessful, Found is false.
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
         if (strcmp(CurrPtr->Data,Item)>=0 )
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
