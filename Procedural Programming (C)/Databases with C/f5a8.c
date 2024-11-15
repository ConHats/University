#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char BinTreeElementType;             /* Type of elements in the BST
                                                for example int */
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

boolean IdenticalBSTs(BinTreePointer Root1, BinTreePointer Root2);

int main(){
BinTreePointer ARoot, BRoot, CRoot;
int len, i;
char word1[] = "IDENTICAL";
char word2[] = "DIFFERENT";
CreateBST(&ARoot);
CreateBST(&BRoot);
CreateBST(&CRoot);

len = strlen(word1);
for (int i = 0; i < len; i++)
{
    RecBSTInsert(&ARoot, word1[i]);
    RecBSTInsert(&BRoot, word1[i]);
}

len = strlen(word2);
for (int i = 0; i < len; i++)
    RecBSTInsert(&CRoot, word2[i]);


if(IdenticalBSTs(ARoot, BRoot))
    printf("The binary trees A and B are identical\n");
else printf("The binary trees A and B are different\n");
if(IdenticalBSTs(BRoot, CRoot))
    printf("The binary trees B and C are identical\n");
else printf("The binary trees B and C are different\n");

system("Pause");
return 0;
}

boolean IdenticalBSTs(BinTreePointer Root1, BinTreePointer Root2)
{
    if(BSTEmpty(Root1) && BSTEmpty(Root2))
    {
        //printf("%d\n", 1);
        return TRUE;
    }else{
        if(Root1!=NULL && Root2!=NULL)
        {
            //printf("%d\n", 2);
            return( (Root1->Data == Root2->Data) && (IdenticalBSTs(Root1->LChild, Root2->LChild)) && (IdenticalBSTs(Root1->RChild, Root2->RChild)) );
        }
        else {
            //printf("%d\n", 3);
            return FALSE;
        }
    }
}


void CreateBST(BinTreePointer *Root)
/* Function: Creates an empty BST.
   Returns:  The null pointer (NULL) Root.
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Input:    A data structure (BST) with the Root pointing to its root.
   Function: Checks if the BST is empty.
   Returns:  TRUE if the BST is empty, and FALSE otherwise.
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Input :   An BST with the Root pointer pointing to its root and an element Item.
   Function: Inserts the element Item into the BST.
   Returns:  The modified BST with the Root pointer pointing to its root.
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("The element is already in the BST\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Input:    An BST with the Root pointer pointing to its root and a KeyValue.
   Function: Searches for a node in the BST with a KeyValue in its key field.
   Returns:  Found is TRUE, and the LocPtr points to the node containing the KeyValue
             if the search is successful. Otherwise, Found is FALSE.
*/
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue < Root->Data)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue > Root->Data)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Input:    An BST with the Root pointer pointing to its root and a KeyValue.
   Function: Attempts to find a node in the BST that contains the KeyValue in the key
             field of its data section and, if found, deletes it from the BST.
   Returns:  The modified BST with the Root pointer pointing to its root.
*/
{

   BinTreePointer TempPtr;    // true if the element KeyValue is in the BST

    if (BSTEmpty(*Root))      // in case of an Empty treethe KeyValue will not be found
        printf("the element was not found in the BST\n");
     else
         // Recursively search for the node that contains the KeyValue and delete it
          if (KeyValue < (*Root)->Data)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       // Left subtree
          else
            if (KeyValue > (*Root)->Data)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   // Right subtree
            else                            // KeyValue was found, node will be deleted
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;  //Doesn't have a left child
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild; //Has a left child but not a right one
                        free(TempPtr);
                   }
                   else                         //Has 2 children
                   {
                        // Finding it's in-order descendant
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* Moving the descendant of the root of the subtree being
                           examined and deleting the descendant node */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* Input:    A binary tree with the Root pointer pointing to its root.
   Function: Performs an inorder traversal of the binary tree and processes each node
             exactly once.
   Output:   The content of the node, depending on the type of processing.
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("%c ",Root->Data);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
/* Input:    A binary tree with the Root pointer pointing to its root.
   Function: Performs a pre-order traversal of the binary tree and processes each
             node exactly once.
   Output:   The content of the node, depending on the type of processing.
*/
{
    if (Root!=NULL) {
        printf("%d ",Root->Data);
       // printf("L");
        RecBSTPreorder(Root->LChild);
      //  printf("R");
        RecBSTPreorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
/* Input:    A binary tree with the Root pointer pointing to its root.
   Function: Performs a post-order traversal of the binary tree and processes each
             node exactly once.
   Output:   The content of the node, depending on the type of processing.
*/
{
    if (Root!=NULL) {
      //  printf("L");
        RecBSTPostorder(Root->LChild);
     //   printf("R");
        RecBSTPostorder(Root->RChild);
        printf("%d ",Root->Data);
    }
   // printf("U");
}
