#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "math.h"

int main()
{
    int atoma=0, kwdikos, flag=1;
    long kostos=0, kerdos=0;
    #define telikh 20000
    while(flag==1)
    {
        printf("Dwse kwdiko: ");
        kwdikos=GetInteger();
        switch (kwdikos)
        {
            case 1:
                printf("Dwse arithmo atomwn: ");
                atoma=GetInteger();
                if (atoma>10){
                    kostos=ceil(atoma*350*0.9);
                }
                else{
                    kostos=atoma*350;
                }
                printf("Kostos:%ld\n", kostos);
                kerdos += kostos;
            break;

            case 2:
                if(kerdos<telikh)
                {
                    printf("Kerdos: -%ld", telikh-kerdos);

                }
                else
                {
                    printf("Kerdos: %ld", telikh-kerdos);
                }
                flag=0;
            break;

            default:
                printf("Lathos!\n");
        }
    }
    return 0;
}
