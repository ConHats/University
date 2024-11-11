#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define megisto_plithos 10


typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[10];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Katholiko(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean KenoSynolo(typos_synolou synolo);
boolean IsaSynola(typos_synolou s1, typos_synolou s2);
boolean Yposynolo(typos_synolou s1, typos_synolou s2);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);
boolean isValidInteger(char str[],typos_synolou Digits, typos_synolou Characters);
boolean isValidIdentifier(char str[],typos_synolou Letters, typos_synolou digits);


int main(){

    int i,type=1;
    char str[megisto_plithos], answer1='y', answer2='y';

    typos_synolou Letters, Digits, Characters;
    stoixeio_synolou plus, minus ,index;
    Dimiourgia(Letters);
    for (index=65; index<=90; index++)
    {
        Eisagogi(index, Letters);
    }
    for (index=97; index<=122; index++)
    {
        Eisagogi(index, Letters);
    }


    Dimiourgia(Characters);
    plus = 43;
    minus = 45;
    Eisagogi(plus, Characters);
    Eisagogi(minus, Characters);

    Dimiourgia(Digits);
    for (index=48; index<57; index++)
    {
        Eisagogi(index, Digits);
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

boolean isValidInteger(char str[], typos_synolou Digits, typos_synolou Characters)
{
    int i;
    if (Melos(str[0], Characters)|| Melos(str[0], Digits))
    {
        for (i=0; str[i] != '\0'; i++)
        {
            if (Melos(str[i], Digits))
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


boolean isValidIdentifier(char str[], typos_synolou Digits, typos_synolou Letters)
{
    int i;
    if (Melos(str[0], Letters))
    {
        for (i=0; str[i] != '\0'; i++)
        {
            if ((Melos(str[i], Digits)||Melos(str[i], Letters)||str[i]=='_')&&str[i]!=' ')
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
void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}



