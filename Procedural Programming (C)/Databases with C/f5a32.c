#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char BinTreeElementType;          // The type of the elements in the B-tree,
                                          // indicatively of type int.
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

int LeftNodeCount(BinTreePointer Root);

int main(){
    BinTreePointer root1, root2;
    char word1[] = "ALGORITHM";
    char word2[] = "MHTIROGLA";
    int i;
    CreateBST(&root1);
    CreateBST(&root2);
    for(i=0; word1[i]!='\0'; i++)
    {
        RecBSTInsert(&root1, word1[i]);
    }
    for(i=0; word2[i]!='\0'; i++)
    {
        RecBSTInsert(&root2, word2[i]);
    }
    printf("First tree with inorder traverse\n");
    RecBSTInorder(root1);
    printf("\n");
    printf("Second tree with inorder traverse\n");
    RecBSTInorder(root2);
    printf("\n");
    printf("First tree LeftNodeCount = %d\n", LeftNodeCount(root1));
    printf("Second tree LeftNodeCount =  %d\n", LeftNodeCount(root2));
system("pause");
return 0;
}

int LeftNodeCount(BinTreePointer Root)
{ int lcounter =0, rcounter=0;
    if(BSTEmpty(Root))
    {
        return 0;
    }else{
    if(Root->LChild!=NULL)
    {
        lcounter = 1+LeftNodeCount((Root->LChild));
    }
    if(Root->RChild!=NULL)
    {
        rcounter = LeftNodeCount((Root->RChild));
    }
    return lcounter+rcounter;
  }
}

void CreateBST(BinTreePointer *Root)
/* Function: Creates an empty B-tree.
   Returns:  The null pointer (NULL) Root.
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Input:    A B-tree with the pointer Root pointing to its root.
   Function: Checks if the B-tree is empty.
   Returns:  TRUE if the B-tree is empty, and FALSE otherwise.
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Input:    A B-tree with the pointer Root pointing to its root and an element Item.
   Function: Inserts the element Item into the B-tree.
   Returns:  The modified B-tree with the pointer Root pointing to its root.
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
/* Input:    A B-tree with the pointer Root pointing to its root and a KeyValue.
   Function: Searches in the B-tree for a node with the value KeyValue in its key field.
   Output:   If the search is successful, Found is set to TRUE, and the pointer LocPtr
             points to the node that contains the KeyValue. Otherwise, Found is set to
             FALSE.
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
/* Input:    A B-tree with the Root pointer pointing to its root and a KeyValue.
   Function: It attempts to find a node in the B-tree that contains the value KeyValue
             in the key field of its data section, and if it finds it, deletes the node
             from the B-tree.
   Returns:  The modified B-tree with the Root pointer still pointing to its root
*/
{

   BinTreePointer TempPtr;        // true if the KeyValue is element of the BST *)

    if (BSTEmpty(*Root))          // Empty tree,the KeyValue can't be found *)
        printf("Can't found the element in the BST\n");
     else
    // Recursively search for the node that contains the value KeyValue and delete it
          if (KeyValue < (*Root)->Data)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       // Left subtree
          else
            if (KeyValue > (*Root)->Data)
                  RecBSTDelete(&((*Root)->RChild), KeyValue); // Right subtree
            else                                 // KeyValue was found. delete the node
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      // No left child
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;  // Has left child, but no right child
                        free(TempPtr);
                   }
                   else                          // Has 2 children
                   {
                        // Finding its inorder successor.
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* Move the descendant of the root of the subtree under
                        examination and delete the descendant node.*/
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* Input:    A binary tree with the pointer Root pointing to its root.
   Function: Performs an in-order traversal of the binary tree and processes each node
             exactly once.
   Output:   The content of the node, and it depends on the type of processing.
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
/* Input:    A binary tree with the pointer Root pointing to its root.
   Function: Performs a pre-order traversal of the binary tree and processes each node
             exactly once.
   Output:   The content of the node, and it depends on the type of processing.
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
/* Input:    A binary tree with the pointer Root pointing to its root.
   Function: Performs a post-order traversal of the binary tree and processes each
             node exactly once.
   Output:   The content of the node, and it depends on the type of processing.
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
