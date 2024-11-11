#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NumberOfNodes 10    /*όριο μεγέθους της συνδεδεμένης λίστας,
                            ενδεικτικά τέθηκε ίσο με 50*/
#define NilValue -1          // ειδική μεδενικη τιμη δείχνει το τέλος της Συνδ.λίστας

//typedef int ListElementType2; /*τύπος δεδομένων για τα στοιχεία της συνδεδεμένης λίστας,
                                //ενδεικτικά επιλέχθηκε ο τύπος int */
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

    printf("Lista A\n");
    TraverseLinked(AList,Node);


    for(i=0;i<4;i++){
        do{
            printf("Dwse thn thesh toy ma8hth poy klhrw8hke:");
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
    printf("Lista A\n");
    TraverseLinked(AList,Node);

    printAll(BList,FreePtrB,Node2);
    printf("Lista B\n");
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
    printf("Lista A\n");
    TraverseLinked(AList,Node);

    printAll(BList,FreePtrB,Node2);
    printf("Lista B\n");
    TraverseLinked(BList,Node2);


system("Pause");
return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr που δείχνει στον
                πρώτο διαθέσιμο κόμβο.
  Λειτουργία: Αρχικοποιεί τον πίνακα Node ως συνδεδεμένη λίστα συνδέοντας μεταξύ
                τους διαδοχικές εγγραφές του πίνακα,
                και αρχικοποιεί τον δείκτη FreePtr .
  Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον
                δείκτη FreePtr του πρώτου διαθέσιμου κόμβου
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        //Node[i].Data=-1;    /* δεν είναι αναγκαίο η απόδοση αρχικής τιμής στο πεδίο των δεδομένων, βοηθάει στην εκτύπωση */
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
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
   Επιστρέφει: Έναν (μηδενικό) δείκτη που δείχνει σε κενή λίστα
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:    Έναν δείκτη List που δείχνει σε μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
   Επιστρέφει: True αν η συνδεδεμένη λίστα είναι κενή και false διαφορετικά
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι γεμάτη.
   Επιστρέφει: True αν η συνδεδεμένηλίστα είναι γεμάτη, false διαφορετικά
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr.
  Λειτουργία: Αποκτά έναν "ελεύθερο" κόμβο που τον δείχνει ο δείκτης P.
  Επιστρέφει: Τον δείκτη P και τον τροποποιημένο  δείκτη FreePtr
                που δεικτοδοτεί στο πρώτο διαθέσιμο κόμβο
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Δέχεται:    Τον πίνακα Node, που αναπαριστά τη δεξαμενή των διαθέσιμων κόμβων,
                έναν δείκτη TempPtr και τον δείκτη FreePtr.
   Λειτουργία: Επιστρέφει στη δεξαμενή τον κόμβο στον οποίο δείχνει ο TempPtr.
   Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον δείκτη FreePtr
*/
{
  Node[P].Next =*FreePtr;
  strcpy(Node[P].Data.name, " ");
    Node[P].Data.school=-1;

  //Node[P].Data = -1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην
  //                      εκτύπωση οι διαγραμμένοι κόμβοι */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Δέχεται:    Μια συνδεδεμένη λίστα, τον πίνακα Node, τον δείκτη PredPtr και
                ένα στοιχείο Item.
  Λειτουργία: Εισάγει στη συνδεδεμένη λίστα, αν δεν είναι γεμάτη, το στοιχείο
                Item μετά από τον κόμβο στον οποίο δείχνει ο δείκτης PredPtr.
  Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα, τον τροποποιημένο πίνακα Node
                και τον δείκτη FreePtr.
  Εξοδος:     Μήνυμα γεμάτης λίστας, αν η συνδεδεμένη λίστα είναι γεμάτη
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
/* Δέχεται:   Μια συνδεδεμένη λίστα και τον δείκτη PredPtr που δείχνει
                στον προηγούμενο κόμβο από αυτόν που θα διαγραφεί.
  Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα, αν δεν είναι κενή,
                τον προηγούμενο κόμβο από αυτόν στον οποίο δείχνει ο PredPtr.
  Επιστρέφει: Την τροποποιημένη λίστα και το δείκτη FreePtr.
  Έξοδος:     Μήνυμα κενής λίστας, αν η συνδεδεμένη λίστα είναι κενή
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
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Κάνει διάσχιση της συνδεδεμένης λίστας, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
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
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:< %s, %d> ->%d) ", i, Node[i].Data.name, Node[i].Data.school, Node[i].Next);
    printf("\n");
}
