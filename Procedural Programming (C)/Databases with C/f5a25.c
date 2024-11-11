#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>

typedef int BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);
int CountLeaves(BinTreePointer Root);

int main(){
    BinTreeElementType AnItem;
    char ch;
    int count;
    BinTreePointer ARoot;

    CreateBST(&ARoot);

    do{
        printf("Enter a number for insertion in the Tree: ");
        scanf("%d", &AnItem);
        RecBSTInsert(&ARoot, AnItem);

        printf("Continue Y/N: ");
        do {
            scanf("%c", &ch);
        }while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    }while (toupper(ch)!='N');

    printf("Elements of BST\n");
    InorderTraversal(ARoot);

    printf("\nNumber of leaves %d\n", count = CountLeaves(ARoot));
    return 0;
}

int CountLeaves(BinTreePointer Root)
{
    int count;
    if (Root==NULL)
        return 0;
    if(Root->LChild==NULL && Root->RChild==NULL){
        return 1;
    }

    count = CountLeaves(Root->LChild) + CountLeaves(Root->RChild);
    return  count;
}

void CreateBST(BinTreePointer *Root)
/* Operation: Creates an empty binary search tree (BST).
   Output:    Returns the null pointer (NULL) for the Root.
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Input:     A binary search tree (BST) with the Root pointer pointing to its root.
   Operation: Checks if the BST is empty.
   Output:    Returns TRUE if the BST is empty, and FALSE otherwise.
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Input:     A binary search tree (BST) with the Root pointer pointing to its root and an element Item.
   Operation: Inserts the element Item into the BST.
   Output:    The modified BST with the Root pointer still pointing to its root.
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
        printf("The %d is already in the BST\n", Item);
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
/* Input:      A binary search tree (BST) with the Root pointer pointing to its root and a KeyValue.
   Operation:  Searches the BST for a node with the KeyValue in its key field.
   Returns:    Found is set to TRUE, and the LocPtr pointer points to the node containing the KeyValue,
               if the search is successful.
               Otherwise, Found is set to FALSE.
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
/* Input:      A binary search tree (BST) with the Root pointer pointing to its root and a KeyValue.
   Operation:  Searches the BST for a node with the KeyValue in its key field and the parent of that node.
   Output:     Found is set to TRUE, the LocPtr pointer points to the node containing the KeyValue,
               and the Parent pointer points to the parent of that node,
               if the search is successful.
               Otherwise, Found is set to FALSE.
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
/* Input:     A binary search tree (BST) with the Root pointer pointing to its root and a KeyValue.
   Operation: Attempts to find a node in the BST that contains the KeyValue in the data field's key,
              and if found, deletes that node from the BST.
   Output:   The modified BST with the Root pointer pointing to its root.
{
    BinTreePointer
    n,                   // points to the node containing the KeyValue *)
    Parent,              // parent of n or nNext
    nNext,               // in-order successor of n
    SubTree;             // pointer to the subtree of n
    boolean Found;       // TRUE IF KeyValue is found in the BST *)

    BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
    if (!Found)
        printf("THE ELEMENT %d IS NOT IN THE BST\n", KeyValue);
    else {
        if (n->LChild != NULL && n->RChild != NULL)
        {  // node to be deleted has two children
            // Find the in-order successor and its parent
            nNext = n->RChild;
            Parent = n;
            while (nNext->LChild != NULL)  //* TRAVERSAL TO THE LEFT *)
            {
                Parent = nNext;
                nNext = nNext->LChild;
            }
            /* Copy the contents of nNext to n and
            change n to point to the successor */
            n->Data = nNext->Data;
            n = nNext;
        }

          //In case the node has at most 1 child
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* THE ROOT WILL BE DELETED *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* Input:     A binary tree with the Root pointer pointing to its root.
   Operation: Performs an in-order traversal of the binary tree and processes each node exactly once.
   Output:    Displays the content of each node, with the processing depending on the type of operation.
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%d ",Root->Data);
        InorderTraversal(Root->RChild);
    }
}
