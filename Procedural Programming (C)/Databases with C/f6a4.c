#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HMax 9
#define VMax 30
#define EndOfList -1

typedef struct{
    char Name[10];
    char Surname[20];
    char PhoneNum[11];
    int Code;
} ListElementType;

typedef char KeyType[31];

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct {
    int HashTable[HMax];   // Array of pointers to synonym sublists
    int Size;              // The number of entries in the List
    int SubListPtr;        // Pointer to a synonym sublist
    int StackPtr;          // Pointer to the first free position in the List
    ListElm List[VMax];    // List array (elements of the list)
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
int findAverage(KeyType s);
void BuildHashList(HashListType *HList);
void Search_HashList_By_Subject(HashListType HList, int code);

int main()
{
    HashListType HList;
    ListElm AnItem;
    KeyType AKey;
    int Loc, Pred;
    char ch;
    int code;

    /*1*/
    printf("1. Create HashList\n");
    BuildHashList(&HList);
    PrintTables(HList);

    /*2*/
    printf("2. Insert new teacher\n");
    do{
        printf("Enter teacher's name: ");
        scanf("%s", AnItem.Data.Name);
        printf("Enter teacher's surname: ");
        scanf("%s", AnItem.Data.Surname);
        strcpy(AnItem.RecKey, strcat(strcat(AnItem.Data.Name, " "), AnItem.Data.Surname));
        printf("Enter teacher's phone: ");
        scanf("%s", AnItem.Data.PhoneNum);
        printf("Enter teacher code:  ");
        scanf("%d", &AnItem.Data.Code);
        AddRec(&HList, AnItem);
        printf("\nContinue Y/N: ");
        do{
             scanf(" %c", &ch);
        }while(toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    }while(toupper(ch)!='N');
    PrintTables(HList);

    /*3*/
    printf("3. Delete a teacher\n");
    printf("Enter teacher's name: ");
    scanf("%s", AnItem.Data.Name);
    printf("Enter teacher's surname: ");
    scanf("%s", AnItem.Data.Surname);
    strcpy(AnItem.RecKey, strcat(strcat(AnItem.Data.Name, " "), AnItem.Data.Surname));
    SearchHashList(HList, AnItem.RecKey, &Loc, &Pred);
    DeleteRec(&HList, AnItem.RecKey);
    PrintTables(HList);

    /*4*/
    printf("4. Search for a teacher\n");
    printf("Enter teacher's name: ");
    scanf("%s", AnItem.Data.Name);
    printf("Enter teacher's surname: ");
    scanf("%s", AnItem.Data.Surname);
    strcpy(AnItem.RecKey, strcat(strcat(AnItem.Data.Name, " "), AnItem.Data.Surname));
    SearchHashList(HList, AnItem.RecKey, &Loc, &Pred);
    if (Loc != -1)
        printf("[%s, %s, %d]\n", HList.List[Loc].RecKey,HList.List[Loc].Data.PhoneNum ,HList.List[Loc].Data.Code);
    else
       printf("There is no entry with key %s\n", AnItem.RecKey);

    /*5*/
    printf("5. Search by subject\n");
    printf("Enter code: ");
    scanf("%d", &code);
    Search_HashList_By_Subject(HList, code);

    return 0;
}

int findAverage(KeyType s)
{
    int first, last;
    first = (toupper(s[0]) - 64);
    last = (toupper(s[strlen(s)-1]) - 64);
    return (first + last)/2;
}

int HashKey(KeyType Key)
{
    int avg;
	avg=findAverage(Key);
	return avg%HMax;
}

void BuildHashList(HashListType *HList)
{
    int nscan;
    KeyType AKey;
    ListElm AnItem;
    FILE* fp;
    char termch;

    CreateHashList(HList);

    fp=fopen("i4f6.txt", "r");

    if (fp!=NULL) {
        while (TRUE){
            nscan=fscanf(fp,"%10[^,],%20[^,],%10[^,],%d%c", AnItem.Data.Name, AnItem.Data.Surname, AnItem.Data.PhoneNum, &AnItem.Data.Code, &termch);
            if (nscan==EOF)
                {
                    break;
                }
            if (nscan != 5 || termch != '\n')
                {
                    printf("Error\n");
                    exit(1);
                }
            else{
                    strcpy(AnItem.RecKey, strcat(strcat(AnItem.Data.Name, " "), AnItem.Data.Surname));
                    AddRec(HList, AnItem);
            }
        }
    }
    fclose(fp);
}

void Search_HashList_By_Subject(HashListType HList, int code)
{
    int i, SubIndex;

    printf("List of teachers with subject code %d:\n", code);
    for (i=0;i<HMax;i++)
    {
        SubIndex=HList.HashTable[i];
        while (SubIndex!=EndOfList){
            if (HList.List[SubIndex].Data.Code==code)
                printf("%d: [%s, %s, %d]\n", SubIndex, HList.List[SubIndex].RecKey, HList.List[SubIndex].Data.PhoneNum, HList.List[SubIndex].Data.Code);
            SubIndex=HList.List[SubIndex].Link;
        }
    }
}

void PrintTables(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0;i<HMax;i++)
        {
            printf("%d, ", HList.HashTable[i]);
        }
    printf("\n");
	printf("Hash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %s, %d\n", i, HList.List[i].RecKey, HList.List[i].Link);
	printf("\n");
}

void CreateHashList(HashListType *HList)
{
	int index;

	HList->Size=0;           //Creates an empty list
	HList->StackPtr=0;       //Pointer to the top of the stack of free positions

    //Initializes the HashTable array of the HList structure so that each of its elements has the value EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

    //Creation of the stack of free positions in the HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey, KeyArg) == 0)
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
{
	int Loc, Pred, New, HVal;

   // New= 0;
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
			printf("There is already an entry with the same key \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}

void DeleteRec(HashListType *HList,KeyType DelKey)
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
		printf("there is no entry with that key %s\n",DelKey);
	}
}
