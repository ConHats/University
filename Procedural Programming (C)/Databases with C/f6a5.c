#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define HMax 9             /*     το μέγεθος του πίνακα HashTable
                                ενδεικτικά ίσο με 5 */
#define VMax 30             /*το μέγεθος της λίστας,
                                ενδεικτικά ίσο με 30 */
#define EndOfList -1        /* σημαία που σηματοδοτεί το τέλος της λίστας
                                και της κάθε υπολίστας συνωνύμων */

typedef struct{
        char username[9];
        char password[7];
}ListElementType;  /*τύπος δεδομένων για τα στοιχεία της λίστας
                               * ενδεικτικά τύπου int */
typedef int KeyType;

typedef struct {
	KeyType key;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // πίνακας δεικτών προς τις υπολίστες συνωνύμων
    int Size;                // πλήθος εγγραφών της λίστας List
	int SubListPtr;          // Dδείκτης σε μια υπολίστα συνωνύμων
    int StackPtr;           // δείκτης προς την πρώτη ελεύθερη θέση της λίστας List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
void PrintTables(HashListType HList);
void BuildHashList(HashListType *HList);
int foldKey(char s[]);

int main(){
char ch;
int Loc, Pred;
HashListType HList;
ListElm AnItem;

BuildHashList (&HList);
PrintTables(HList);
printf("\n");
do{     printf("USERNAME: ");
        scanf("%s", AnItem.Data.username);
        printf("PASSWORD: ");
        scanf("%s", AnItem.Data.password);
        AnItem.key = foldKey(AnItem.Data.username);
        SearchHashList(HList, AnItem.key, &Loc, &Pred);
        if(Loc!=-1)
        {
           if(strcmp(AnItem.Data.password, HList.List[Loc].Data.password)==0)
           {
               printf("You have logged in to the system");
           }else{
            printf("Access is forbidden: Wrong password");
           }
        }else{
           printf("Access is forbidden: Wrong user ID");
        }
        printf("\nContinue Y/N: ");
        do
          {
            scanf("%c", &ch);
          } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
        } while (toupper(ch)!='N');

system("Pause");
return 0;
}

void BuildHashList(HashListType *HList){
FILE *fp;
ListElm anItem;
CreateHashList(HList);
if ((fp=fopen("I5f6.txt", "r"))==NULL)
{
    printf("Error opening file...\n");
    exit(-1);
}
while(!feof(fp))
{ fscanf(fp, "%s", anItem.Data.username);
   fscanf(fp, "%s", anItem.Data.password);
   anItem.key = foldKey(anItem.Data.username);
   //anItem.key = foldKey(anItem.Data.password);
   AddRec(HList, anItem);
}
fclose(fp);
}

int foldKey(char s[])
{
return (s[0]+ s[strlen(s)-1])/2;
}

void PrintTables(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d)%3d\n",i,HList.HashTable[i]);

	printf("Hash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %d, %10s, %8s, %3d\n",i,HList.List[i].key, HList.List[i].Data.username, HList.List[i].Data.password, HList.List[i].Link);
	printf("\n");
}

int HashKey(KeyType key)
/* Input:    The key value of a key.
   Function: Finds the hash value HValue for the key Key.
   Returns:  The hash value HValue.
*/

{
 // If the KeyType is not an integer, the key should be converted to a number
	return key%HMax;
}

void CreateHashList(HashListType *HList)
/* Function: Creates a HList structure.
   Returns:  The HList structure.
*/
{
	int index;

	HList->Size=0;           //Creates an empty list
	HList->StackPtr=0;       //pointer to the top of the stack of free positions


    /*initializes the hashtable array of the hlist structure so that each element has
    the value endoflist (-1) */
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
/* Accepts:   A structure HList.
   Function:  Checks if the List of the HList structure is full.
   Returns:   TRUE if the List is full, FALSE otherwise.

*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Accepts:   A structure HList and a key value KeyArg.
   Function:  Searches for a record with key KeyArg in the synonym sublist.
   Returns:   The position Loc of the record and the position Pred of the
              previous record in the sublist.

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
/* Accepts:   A structure HList and a key value KeyArg.
   Function:  Searches for a record with key KeyArg in the structure HList.
   Returns:   The position Loc of the record and the position Pred of the
              previous record in the sublist it belongs to.
              If no record with key KeyArg exists, then Loc=Pred=-1.

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
/* Input:      A structure HList and a record InRec.
   Function:   Inserts the record InRec into the list List, if it is not full,
               and updates the structure HList.
   Returns:    The modified structure HList.
   Output:     A "list full" message if the List is full, otherwise, if a record with
               the same key already exists, displays a corresponding message.
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
			printf("There is already a record with that key \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* Input:    The structure (HList) and the key (DelKey) of the record
             that is to be deleted.
   Function: Deletes the record with the key (DelKey) from the
             list (List), if it exists, and updates the structure (HList).
   Returns:  The modified structure (HList).
   Output:   "NO RECORD WITH SUCH KEY" message if the record does not exist.
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
		printf("There is no record with the key %d \n",DelKey);
	}
}
