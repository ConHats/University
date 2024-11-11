#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef int ListElementType;            /* � ����� ��� ��������� ��� ������������ ������
                                        ���������� ����� int */
typedef struct ListNode *ListPointer;   //� ����� ��� ������� ��� ���� �������
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

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d",&number);
    if (number==0) {

        system("Pause");
        return 0;
    }

   for(i=0;i<number;i++){
        PredPtr= NULL;
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: ");
        scanf("%d",&AnItem);
        LinkedInsert(&AList, AnItem, PredPtr);
   }
   /*
    do{
        printf("DWSE TI THESI GIA DIAGRAFI TOY STOIXEIOU: ");
        scanf("%d", &n);
    } while (!((n>0)&&(n<=number)));
    */

    boolean validpos=FALSE;

    do{
        printf("DWSE TI THESI GIA DIAGRAFI TOY STOIXEIOU: ");
        scanf("%d", &n);
        if ((n>0)&&(n<=number))  validpos=TRUE;
        else printf("MH EGKIRI THESI. DWSE THESI APO 1 EWS %d.\n", number);
        } while(!validpos);



    printf("Arxiki lista\n");
    LinkedTraverse(AList);
    delete_n_element(&AList, n);
    printf("\nTeliki lista\n");
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
/* ����������: ���������� ��� ���� ����������� �����.
  ����������:  ��� �������� ������ List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
  ����������: ������� �� � ����������� ����� ����� ����.
  ����������: TRUE �� � ����� ����� ���� ��� false �����������
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����,
                ��� �������� ��������� Item ��� ���� ������ PredPtr.
   ����������: ������� ���� �����, ��� �������� �� Item, ���� ����������� �����
                ���� ��� ��� ����� ��� �������������� ��� ��� PredPtr
                � ���� ����  ��� ������������ ������,
                �� � PredPtr ����� ���������(NULL).
  ����������:  ��� ������������� ����������� ����� �� ��� ����� ����� ���
                �� �������������� ��� ��� List.
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
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� ����� ���
                 ��� ���� ������ PredPtr.
   ����������: ��������� ��� �� ����������� ����� ��� ����� ��� ����
                ��� ����������� ��� ����� ���� ����� ������� � PredPtr
                � ��������� ��� ����� �����, �� � PredPtr ����� ���������,
                ����� ��� �� � ����� ����� ����.
   ����������: ��� ������������� ����������� ����� �� ��� ����� �����
                �� �������������� ��� ��� List.
   ������:     ��� ������ ����� ������ �� � ����������� ����� ���� ���� .
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
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
   ����������: ��������� �� ����������� ����� ���
                ������������� ���� �������� ������� ��� ����.
   ����������: ��������� ��� �� ����� ��� ������������.
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
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
  ����������: ������� ��� �������� ��������� ���� �� ������������ �����������
              ����� ��� ���� ����� ��� �� �������� �� �������� Item.
  ����������: �� � ��������� ����� �������� � Found ����� TRUE, � CurrPtr �������
                ���� ����� ��� �������� �� Item ��� � PredPtr ���� ����������� ���
                � ����� NULL �� ��� ������� ������������.
                �� � ��������� ��� ����� �������� � Found ����� false.
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
/* �������:    ��� �������� Item ��� ��� ������������ ����������� �����,
                ��� �������� �������� ��������� �� ������� ������� ��� ���� �����
                � ������� List ������� ���� �����  �����.
   ����������: ������� �������� ��������� ��� ������������ ������������� ������
                ��� ��� ����� ����� ��� �������� �� �������� Item � ��� ��� ����
                ��� �� ������� ��� ��� ����� ��� �� �������� �� �������� Item.
   ����������: �� � ��������� ����� �������� � Found ����� TRUE,
                � CurrPtr ������� ���� ����� ��� �������� �� Item ���
                � PredPtr ���� ����������� ��� � ����� Null �� ��� ������� ������������.
                �� � ��������� ��� ����� �������� � Found ����� false.
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
