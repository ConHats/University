#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    int kivwtia;
    float varos;
    char hmerominia[10];
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

   printf("Plithos fortiwn: ");
   scanf("%d",&n);

   for (i=1;i<=n;i++){
        printf("Arithmos kivwtiwn gia to %do fortio: ",i);
        scanf("%d",&AnItem.kivwtia);
        printf("Synoliko baros gia to %do fortio: ",i);
        scanf("%f",&AnItem.varos);
        printf("Imeromhnia liksis gia to %do fortio: ",i);
        scanf("%s",&AnItem.hmerominia);

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
        count=count+CurrPtr->Data.kivwtia;
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
      	     printf("%d %.2f %s \n", CurrPtr->Data.kivwtia, CurrPtr->Data.varos, CurrPtr->Data.hmerominia);
             CurrPtr = CurrPtr->Next;
        }
   }
}


void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
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


