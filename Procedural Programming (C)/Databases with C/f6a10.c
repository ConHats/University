#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define HMax 31             /* size of the HashTable array,
                               typically set to 5 */
#define VMax 30             /* size of the list,
                               typically set to 30 */
#define EndOfList -1        /* flag that indicates the end of the list
                               and each synonym sublist*/

typedef struct{
        char name[6];
        int value;
}ListElementType;           /* Data type for the elements of the list,
                               typically of type int. */
typedef int KeyType;

typedef struct {
	KeyType key;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // Array of pointers to the sublists of synonyms
    int Size;              // Number of entries in the List
	int SubListPtr;        // Pointer to a synonym sublist
    int StackPtr;          // Pointer to the first free position of the List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

//void PrintHeap(HeapType Heap);
void PrintTables(HashListType HList);

void Print_HashList(HashListType HList);

void CreateHashList(HashListType *HList);
int HashKey(KeyType key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);

int FoldKey(char s[]);

int main(){
    int i, c;
    int Loc1, Loc2, Prev;
    ListElm Item, Item1, Item2;
    HashListType Hlist;
    CreateHashList(&Hlist);
    printf("Declare variables\n");
    for(i=0; i<4; i++)
    {
        printf("Enter the variable name: ");
        scanf("%s", Item.Data.name);
        printf("Enter variable value: ");
        scanf("%d", &Item.Data.value);
        Item.key = FoldKey(Item.Data.name);
        AddRec(&Hlist, Item);
    }

    Print_HashList(Hlist);
    for (c=0; c<2; c++){

        if (c==0) printf("Multiply Variables\n");
        else printf("Add Variables\n");

        printf("Enter the first variable: ");
        scanf("%s", Item1.Data.name);
        Item1.key = FoldKey(Item1.Data.name);
        SearchHashList(Hlist, Item1.key, &Loc1, &Prev);

        printf("Enter the second variable: ");
        scanf("%s", Item2.Data.name);
        Item2.key = FoldKey(Item2.Data.name);
        SearchHashList(Hlist, Item2.key, &Loc2, &Prev);

        if(Loc1!=-1 && Loc2!=-1){
                if(strcmp(Hlist.List[Loc1].Data.name, Item1.Data.name)==0 && strcmp(Hlist.List[Loc2].Data.name, Item2.Data.name)==0)
                {
                    if (c==0) printf("%s * %s = %d\n", Hlist.List[Loc1].Data.name, Hlist.List[Loc2].Data.name, Hlist.List[Loc1].Data.value * Hlist.List[Loc2].Data.value);
                    else printf("%s + %s = %d\n", Hlist.List[Loc1].Data.name, Hlist.List[Loc2].Data.name, Hlist.List[Loc1].Data.value + Hlist.List[Loc2].Data.value);
            }else{
                if( strcmp(Hlist.List[Loc1].Data.name, Item1.Data.name) != 0 )
                {
                    printf("Undeclared variable %s",Item1.Data.name);
                }
                if( strcmp(Hlist.List[Loc2].Data.name, Item2.Data.name) != 0)
                {
                    printf("Undeclared variable %s", Item2.Data.name);
                }

            }
        }else{
            if(Loc1==-1){
                printf("Undeclared variable %s\n", Item1.Data.name);
            }
            if(Loc2==-1){
                printf("Undeclared variable %s\n", Item2.Data.name);
            }
        }
    }

    return 0;
}

int FoldKey(char s[])
{ int i, sum=0;
for(i=0; s[i]!='\0'; i++) {  //strlen(s) --> string.h
    sum+= (i+1)*(s[i]-65+1);
}
/*BCA -
1*2 * 2*3 * 3*1
*/
return sum;
}


void Print_HashList(HashListType HList)
{
   int i, SubIndex;


          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList)
              {
                   printf("[%d, %s %d, %d]",HList.List[SubIndex].key,HList.List[SubIndex].Data.name, HList.List[SubIndex].Data.value, HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
                   printf("End of %d's sublist \n", i);
               } //* while *)

          }
}

int HashKey(KeyType key)
/* Input:    The key value of a key.
   Function: Finds the hash value HValue for the key Key.
   Returns:  The hash value HValue.
*/
{
	/*In case the KeyType is not an integer, the key should be appropriately
	converted to a number*/
	return key%HMax;
}

void CreateHashList(HashListType *HList)
/* Function: Creates a HList structure.
   Returns:  The HList structure.
*/
{
	int index;

	HList->Size=0;           //Creates an empty list
	HList->StackPtr=0;       //Pointer to the top of the free space stack

    /*Initializes the HashTable array of the HList structure so that each of its
      elements has the value EndOfList (-1).*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //Creation of the stack of free positions in the HList.
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* Input:    A structure HList.
   Function: Checks if the List in the HList structure is full.
   Returns:  TRUE if the List is full, FALSE otherwise.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Input:    A structure HList and a key value KeyArg.
   Function: Searches for a record with the key KeyArg in the synonym sublist.
   Returns:  The position Loc of the record and the position Pred of the previous
             record in the sublist.
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].key==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Input:    A structure HList and a key value KeyArg.
   Function: Searches for a record with the key KeyArg in the HList structure.
   Returns:  The position Loc of the record and the position Pred of the previous
             record in the sublist it belongs to.If no record with the key KeyArg
             exists, then Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* Input:    A structure HList and a record InRec.
   Function: Inserts the record InRec into the List if it is not full, and updates the
             HList structure.
   Returns:  The modified HList structure.
   Output:   A message indicating the list is full if the List is full, otherwise, if
             a record with the same key already exists, a corresponding message is
             displayed.
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.key,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.key);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("There is already a record with this key \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* Input:    The structure (HList) and the key (DelKey) of the record to be deleted.
   Function: Deletes the record with key (DelKey) from the List (List) if it exists,
             and updates the HList structure.
   Returns:  The modified HList structure.
   Output:   "NO RECORD FOUND WITH KEY" message
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("There is no record with key %d \n",DelKey);
	}
}



/*void PrintHeap(HeapType Heap)
{
    int i,l,r,n;
    printf("Size=%d \n",Heap.Size);
     printf("N   L   R\n");
     n=Heap.Size/2;
     for (i=1; i<=n;i++)
     {
         l=2*i;
         r=2*i+1;
         printf("%d, ",Heap.Element[i].key);
         if (l<=Heap.Size)
            printf("%d, ",Heap.Element[l].key);
         else printf(",   ");
         if (r<=Heap.Size)
            printf("%d \n",Heap.Element[r].key);
         else printf("\n");
     }
     printf("Heap array\n");
     for (i=1; i<=Heap.Size;i++)
        printf("%d ",Heap.Element[i].key);
    printf(" \n");
}

void PrintTables(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d)%3d\n",i,HList.HashTable[i]);

	printf("Hash List\n");
    for (i=0;i<VMax;i++)
	   printf("%d) %d, %d\n",i,HList.List[i].key,HList.List[i].Link);
	printf("\n");
}*/
