#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define HMax 5              /*  the size of the HashTable array
                                indicative value of 5 */

#define VMax 30             /*  the size of the list,
                                indicative value of 30 */

#define EndOfList -1        /*  flag that marks the end of the list
                                and each synonym sublist */

typedef struct{
char name[20];
int amount;
} ListElementType;

typedef int KeyType;

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
    int HashTable[HMax];    // array of pointers to synonym sublists
    int Size;               // number of entries in the List
    int SubListPtr;         // pointer to a synonym sublist
    int StackPtr;           // pointer to the first available position in the List
    ListElm List[VMax];     // list of elements (ListElm type)
} HashListType;


typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
void PrintTables(HashListType HList);
void Print_HashList(HashListType HList);
void PrintListOfSynonyms(HashListType HList, KeyType key);


int main()
{
    char ch;
    HashListType HList;
    ListElm AnItem;
    KeyType AKey;
    int Loc, Pred;
    int new_amount;

    //1
    printf("1. Create HashList \n");
    CreateHashList(&HList);
    Print_HashList(HList);

    //2
    printf("2. Insert new member \n");
    do {
            printf("Give code: ");
            scanf("%d",&AnItem.RecKey );
            printf("Give name: ");
            scanf("%s",&AnItem.Data.name);
            printf("Give amount: ");
            scanf("%d",&AnItem.Data.amount);
            AddRec(&HList,AnItem);

            printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while(toupper(ch)!= 'N' && toupper(ch)!= 'Y');

    } while(toupper(ch)!='N');

    //3
    printf("3. Search for a member \n");
    do
    {
        printf("Give code: ");
        scanf("%d",&AKey);
        SearchHashList(HList,AKey,&Loc,&Pred);
        if (Loc != -1)
            printf("[%d, %s, %d, %d]\n",HList.List[Loc].RecKey,HList.List[Loc].Data.name,HList.List[Loc].Data.amount,HList.List[Loc].Link);
        else
           printf("There is no entry with the key %d",AKey);
        printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while(toupper(ch)!= 'N' && toupper(ch)!= 'Y');

    } while(toupper(ch)!='N');

   //4
   printf("4. Update member amount \n");
   do {
        printf("Give code: ");
        scanf("%d",&AKey);
        SearchHashList(HList,AKey,&Loc,&Pred);
        if (Loc != -1)
        {
            printf("[%d, %s, %d,%d]\n",HList.List[Loc].RecKey,HList.List[Loc].Data.name,HList.List[Loc].Data.amount,HList.List[Loc].Link);
            printf("Give amount: ");
            scanf("%d",&new_amount);
            if(HList.List[Loc].Data.amount>=new_amount)
                HList.List[Loc].Data.amount=HList.List[Loc].Data.amount-new_amount;

        }
        else
            printf("There is no entry with the key %d",AKey);
         printf("\nContinue Y/N: ");
         do {
            scanf("%c", &ch);
        } while(toupper(ch)!= 'N' && toupper(ch)!= 'Y');

   } while (toupper(ch)!='N');
   Print_HashList(HList);
   PrintTables(HList);

   //5
   printf("5. Delete a member \n");
   do{
        printf("Give code: ");
        scanf("%d",&AKey);
        SearchHashList(HList,AKey,&Loc,&Pred);
        if (Loc != -1)
        {
            if (HList.List[Loc].Data.amount==0)
                DeleteRec(&HList,AKey);
            else
                printf("Not deleted arrange amount");


        }
        else
            printf("There is no entry with the key %d",AKey);
         printf("\nContinue Y/N: ");
         do {
            scanf("%c", &ch);
        } while(toupper(ch)!= 'N' && toupper(ch)!= 'Y');

   }while (toupper(ch)!='N');
   Print_HashList(HList);
   PrintTables(HList);

   //6
    printf("6. Print list of synonyms \n");
   do{
        printf("Give code: ");
        scanf("%d",&AKey);
        SearchHashList(HList,AKey,&Loc,&Pred);
        if (Loc != -1)
        {
            printf("[%d, %s, %d, %d]\n",HList.List[Loc].RecKey,HList.List[Loc].Data.name,HList.List[Loc].Data.amount,HList.List[Loc].Link);
            PrintListOfSynonyms(HList,AKey);
        }
        else
            printf("DThere is no entry with the key %d",AKey);
         printf("\nContinue Y/N: ");
         do {
            scanf("%c", &ch);
        } while(toupper(ch)!= 'N' && toupper(ch)!= 'Y');

   }while (toupper(ch)!='N');

 return 0;
}

void PrintListOfSynonyms(HashListType HList, KeyType key)
{
 int Hval, SubIndex;

 Hval=HashKey(key);
 SubIndex=HList.HashTable[Hval];
 while ( SubIndex != EndOfList ){
    printf("%d:[%d, %s, %d] \n",SubIndex,HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.name,HList.List[SubIndex].Data.amount);
    SubIndex = HList.List[SubIndex].Link;
    }
 }









int HashKey(KeyType Key)
/*
   Input:    The Key value of a key.
   Function: Finds the hash value HValue for the Key.
   Returns:  The hash value HValue
*/
{
    /* In case the KeyType is not an integer,
       the key should be appropriately converted to a number */
	return Key%HMax;
}

void CreateHashList(HashListType *HList)
/*
   Function: Creates a HList structure.
   Returns:  The HList structure
*/
{
	int index;

	HList->Size=0;           //Creates empty List
	HList->StackPtr=0;       //Pointer to the top of the stack of free positions

    /* Initializes the HashTable array of the HList structure so that each element
    has the value EndOfList (-1) */

    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

    // Creation of the stack of free positions in the HList

    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/*
   Input:    A structure HList.
   Function: Checks if the List of the HList structure is full.
   Returns:  TRUE if the List is full, FALSE otherwise.
*/

{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/*
   Input:     A structure HList and a key value KeyArg.
   Function:  Searches for a record with the key KeyArg in the synonym sublist.
   Returns:   The position Loc of the record and the position Pred of the previous
                 record in the sublist.
*/

{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
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
/*
   Input:     A structure HList and a key value KeyArg.
   Function:  Searches for a record with the key KeyArg in the HList structure.
   Returns:   The position Loc of the record and the position Pred of the previous
              record in the sublist to which it belongs.If no record with the key
              KeyArg exists, then Loc=Pred=-1.
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
/*
   Input:     A structure HList and a record InRec.
   Function:  Inserts the record InRec into the List if it is not full,and updates
              the HList structure.
   Returns:   The modified HList structure.
   Output:    A "list full" message if the List is full, otherwise, if a record with
              the same key already exists, displays the corresponding message.
*/

{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
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
			printf("There is already an entry with the same key\n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/*
   Input:     The structure (HList) and the key (DelKey) of the record to be deleted.
   Function:  Deletes the record with key (DelKey) from the List (List), if it exists,
              and updates the HList structure.
   Returns:   The modified HList structure.
   Output:    "RECORD DOES NOT EXIST" message.
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
		printf("There is no entry with the key %d \n",DelKey);
	}
}

void PrintTables(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

	printf("Hash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %d, %s, %d, %d\n",i,HList.List[i].RecKey,HList.List[i].Data.name,HList.List[i].Data.amount,HList.List[i].Link);
	printf("\n");
}

void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("ARRAY OF POINTERS TO SUB-LISTS OF SYNONYMOUS RECORDS:\n");
            for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

          printf("THE SUB-LISTS OF SYNONYMOUS RECORDS:\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("[%d, %s, %d, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.name,HList.List[SubIndex].Data.amount,HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
              printf("End of %dst Sub-List\n", i);
          }

          printf("Size of List = %d\n", HList.Size);
          printf("========================================\n");
}
