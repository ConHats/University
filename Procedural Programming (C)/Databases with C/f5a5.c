#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char BinTreeElementType;        /*The type of the elements of the BST
                                          For example, of type int. */
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
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

int BSTLevel(BinTreePointer Root, BinTreeElementType Item);

int main(){
BinTreePointer ARoot;
char word[] = "PROGRAMS";
int i;
CreateBST(&ARoot);
for(i=0; word[i]!='\0'; i++)
{
    BSTInsert(&ARoot, word[i]);
}
for(i=0; word[i]!='\0'; i++)
{  if(i!=4)
    printf("Level of %c: %d\n", word[i], BSTLevel(ARoot, word[i]));
}
system("pause");
return 0;
}

int BSTLevel(BinTreePointer Root, BinTreeElementType Item)
{ BinTreePointer LocPtr;  //pointer of the current node
int level;                //level of the current node
LocPtr = Root;
level = 1;
while(LocPtr != NULL)
 {  if(Item < LocPtr->Data)
    { level++;
     LocPtr = LocPtr -> LChild;
    }else if(Item > LocPtr->Data)
        { level++;
          LocPtr = LocPtr -> RChild;
        }else{
              return level;
             }
 }
return -1;
}


void CreateBST(BinTreePointer *Root)
/* Function: Creates an empty BST.
   Returns:  The null pointer (NULL) Root.
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Input:    An BST with Root pointing to its root.
   Function: Checks if the BST is empty.
   Returns:  TRUE if the BST is empty, FALSE otherwise.
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Input:    An BST with the Root pointer pointing to its root and an element Item.
   Function: Inserts the element Item into the BST.
   Returns:  The modified BST with the Root pointer still pointing to its root.
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("The element is already on the BST\n");
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent ->Data)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* Input:    An BST with the Root pointer pointing to its root and a KeyValue.
   Function: Searches the BST for a node with the KeyValue in its key field.
   Returns:  If the search is successful, Found is set to TRUE and the LocPtr points
             to the node containing the KeyValue. Otherwise, Found is set to FALSE.
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue < (*LocPtr)->Data)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue > (*LocPtr)->Data)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Input:    An BST with the Root pointer pointing to its root and a KeyValue.
   Function: Searches the BST for a node with the KeyValue in its key field and
             retrieves the parent of that node.
   Returns:  If the search is successful, Found is set to TRUE, the LocPtr points to
             the node containing the KeyValue, and the Parent pointer points to the
             parent of that node. Otherwise, Found is set to FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue < (*LocPtr)->Data) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue > (*LocPtr)->Data) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Input:    An BST with the Root pointer pointing to its root and a KeyValue.
   Function: Attempts to find a node in the BST that contains the KeyValue in its
             data field's key, and if found, deletes it from the BST.
   Returns:  The modified BST with the Root pointer pointing to its root.
*/
{

   BinTreePointer
   n,                   // points to the node containing the KeyValue item
   Parent,              // parent of n or nNext
   nNext,               // in-order successor of n
   SubTree;             // pointer to the subtree of n
   boolean Found;       // TRUE if the KeyValue item is found in the B-Tree
                        // (or other tree structure)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("The element is not in the BST\n");
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // node to be deleted with two children
                 //Find the next in-order and it's parent
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* Traversal to the Left *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Copy the contents of nNext into n and change n to point to the next
                   one. */
                n->Data = nNext->Data;
                n = nNext;
          } //Case of the node having only 1 child
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
/* Receives: A binary tree with the Root pointer pointing to its root.
   Function: Performs an in-order traversal of the binary tree and processes each node
             exactly once.
   Displays: The contents of the node, and depends on the type of processing.
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%d ",Root->Data);
        InorderTraversal(Root->RChild);
    }
}


