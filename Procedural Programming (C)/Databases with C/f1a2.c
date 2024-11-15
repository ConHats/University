#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define max_count 10


typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean type_of_set[10];
typedef int element_of_set;

void Create(type_of_set set);
void Insert(element_of_set element, type_of_set set);
void Delete(element_of_set element, type_of_set set);
boolean Element(element_of_set element, type_of_set set);
boolean Empty_Set(type_of_set set);
boolean Equal_Sets(type_of_set s1, type_of_set s2);
boolean Subset(type_of_set s1, type_of_set s2);
void Union_of_Sets(type_of_set s1, type_of_set s2, type_of_set Union);
void Intersection_of_Sets(type_of_set s1, type_of_set s2, type_of_set Intersection);
void Difference_of_Sets(type_of_set s1, type_of_set s2, type_of_set Difference);
boolean isValidInteger(char str[],type_of_set Digits, type_of_set Characters);
boolean isValidIdentifier(char str[],type_of_set Letters, type_of_set digits);


int main(){

    int i,type=1;
    char str[max_count], answer1='y', answer2='y';

    type_of_set Letters, Digits, Characters;
    element_of_set plus, minus ,index;
    Create(Letters);
    for (index=65; index<=90; index++)
    {
        Insert(index, Letters);
    }
    for (index=97; index<=122; index++)
    {
        Insert(index, Letters);
    }


    Create(Characters);
    plus = 43;
    minus = 45;
    Insert(plus, Characters);
    Insert(minus, Characters);

    Create(Digits);
    for (index=48; index<57; index++)
    {
        Insert(index, Digits);
    }

    while ((answer1 == 'y') || (answer1 == 'Y'))
    {
         printf("Give an integer: ");
         scanf("%s",&str);
         if(isValidInteger(str,Digits,Characters))
        {
            printf("Correct integer");
        }
            else
        {
            printf("Wrong integer");
        }
        printf("\nContinue with more integers (Y or N): ");
        scanf(" %c",&answer1);

    }



    while ((answer2 == 'y') || (answer2 == 'Y'))
    {
         printf("Give an identifier: ");
         scanf("%s",&str);
        if(isValidIdentifier(str,Letters,Digits))
                {
                    printf("Correct identifier");
                }
                else
                {
                    printf("Wrong identifier");
                }

                printf("\nContinue with more identifiers (Y or N): ");
                scanf(" %c",&answer2);
    }

    return 0;
}

boolean isValidInteger(char str[], type_of_set Digits, type_of_set Characters)
{
    int i;
    if (Element(str[0], Characters)|| Element(str[0], Digits))
    {
        for (i=0; str[i] != '\0'; i++)
        {
            if (Element(str[i], Digits))
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    else
    {
        return FALSE;
    }

}


boolean isValidIdentifier(char str[], type_of_set Digits, type_of_set Letters)
{
    int i;
    if (Element(str[0], Letters))
    {
        for (i=0; str[i] != '\0'; i++)
        {
            if ((Element(str[i], Digits)||Element(str[i], Letters)||str[i]=='_')&&str[i]!=' ')
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    else
    {
        return FALSE;
    }

}
void Create(type_of_set set)
/* Operation: Creates a set with no elements(empty set).
   Returns:   The empty set.
*/
{
    element_of_set i;

    for (i = 0; i < max_count; i++)
        set[i] = FALSE;
}

void Insert(element_of_set element, type_of_set set)
/* Input:     A set and an element.
   Operation: Inserts the element into the set.
   Returns:   The modified set
*/
{
    set[element] = TRUE;
}

boolean Element(element_of_set element, type_of_set set)
/* Input:     A set and an element.
   Operation: Checks if the element is a member of the set.
   Returns:   TRUE if the element is a member, and FALSE otherwise.
*/
{
    return set[element];
}



