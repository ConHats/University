#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char id[8];
    char name[10];
    char lastname[10];
} BinTreeElementType;       // Type of elements in the BST (struct)

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr, int *nodes);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);
void BuildBST(BinTreePointer *Root);

int main(){
BinTreePointer ARoot, LocPtr;
int num, i;
BinTreeElementType student,AnID;
boolean found;

printf("oook");
BuildBST(&ARoot);
printf("oook");

for(i=0; i<=3 ; i++)
{
    printf("Give ID: ");
    scanf("%s",AnID.id);
    BSTSearch(ARoot,AnID,&found,LocPtr,&num);
    if(found){
        printf("nodes=%d ID=%s FirstName=%s LastName=%s",num,student.id, student.name,student.lastname);
    }
    else{
        printf("nodes=%d the student wasnt in the BST",num);
    }

}
return 0;
}

void BuildBST(BinTreePointer *Root)
{
BinTreeElementType student;
FILE *fp;
CreateBST(&fp);
fp = fopen("i31f5.txt", "r");
if(fp==NULL)
    printf("Problem opening file");
else {
    while (!feof(fp))
    { fscanf(fp, "%s %s %s ", &student.id,&student.name,&student.lastname);
      BSTInsert(&(*Root),student);
    }
}
fclose(fp);
}


void CreateBST(BinTreePointer *Root)
/* Function: Creates an empty binary search tree (BST).
   Returns:  The null pointer (NULL) Root.
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Input:    A binary search tree (BST) with the Root pointing to its root.
   Function: Checks if the BST is empty.
   Returns:  TRUE if the BST is empty, and FALSE otherwise.
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Input:    A binary search tree (BST) with the Root pointer pointing to its root
             and an element Item.
   Function: Inserts the element Item into the BST.
   Returns:  The modified BST with the Root pointer still pointing to its root
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.id < LocPtr ->Data.id)
            LocPtr = LocPtr ->LChild;
        else if (Item.id > LocPtr ->Data.id)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("The element is already in the BST\n");
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
//        LocPtr ->Data.id = Item.id;
//        strcpy(LocPtr ->Data.password,Item.password);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.id < Parent ->Data.id)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr,int *nodes)
/* Input:    A binary search tree (BST) with the Root pointer pointing to its root and
             a KeyValue.
   Function: Searches the BST for a node with the KeyValue in its key field.
   Returns:  Found is TRUE, and the LocPtr points to the node containing the KeyValue
             if the search is successful. Otherwise, Found is FALSE
*/
{
    boolean stop;
    *nodes=0;

    *LocPtr = Root;
    stop = FALSE;
    while (!stop && *LocPtr != NULL)
    {
        if (KeyValue.id < (*LocPtr)->Data.id){
            *LocPtr = (*LocPtr)->LChild;
            *nodes++;
        }

        else{
            if (KeyValue.id > (*LocPtr)->Data.id){
                *LocPtr = (*LocPtr)->RChild;
                nodes++;
            }

            else{
                stop = TRUE;
                nodes++;
            }


        }

    }
   *Found=stop;
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Input:    A binary search tree (BST) with the Root pointer pointing to its root and
             a KeyValue.
   Function: Searches the BST for a node with the KeyValue in its key field and its
             parent.
   Returns:  Found is TRUE, LocPtr points to the node containing the KeyValue, and
             Parent points to the parent of this node if the search is successful.
             Otherwise, Found is FALSE.
*/
{
    boolean stop;
    BinTreePointer TempParent;

    *LocPtr = Root;
    TempParent=NULL;
    stop = FALSE;
    while (!stop && *LocPtr != NULL)
    {
        if (KeyValue.id < (*LocPtr)->Data.id) {
            TempParent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue.id > (*LocPtr)->Data.id) {
                TempParent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else stop = TRUE;
    }
   *Found=stop;
   *Parent=TempParent;
}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Input:    A binary search tree (BST) with the Root pointer pointing to its root and
             a KeyValue.
   Function: Tries to find a node in the BST that contains the KeyValue in its key
             field and, if found, deletes it from the tree.
   Returns:  The modified BST with the Root pointer pointing to its root
*/
{

   BinTreePointer
   R,
   n,                   // points to the node that contains the KeyValue
   Parent,              // nNext's or n's parent
   nNext,               // Next of n in-order
   SubTree;             // pointer to teh subtree of n
   boolean Found;       // TRUE if the KeyValue is an element of the BST

     R=*Root;
     BSTSearch2(R, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("The element is not in the BST\n");
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // node to be deleted with 2 children
                 // Find the next in-order node and it's parent
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //Traversal to the Left
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                // Copy the contents of nNext to n and change n to point to the next.
                n->Data = nNext->Data;
                n = nNext;
          } //Continuing with the case where the node has at most 1 child
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* The root will be deleted *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* Input:    A binary tree with the pointer Root pointing to its root.
   Function: Performs an in-order traversal of the binary tree and processes each
             node exactly once.
   Output:   The content of the node, and it depends on the type of processing.
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        //printf("%d, %s\n",Root->Data.id,Root->Data.password);
        InorderTraversal(Root->RChild);
    }
}
