/*
CONTENU      : TP2 EX3
AUTEUR       : PIGNOL Maël
CEATION     : 15/09/2017
MODIFICATION : 15/09/2017
*/

// librairies
#include <stdio.h>
#include <stdlib.h>

char a;

int main (void)
{

do
{
    printf("Pour sortir du programme entrer 'q'\n");
    scanf("%c",&a);
    getchar();
    printf("%c",a);
    printf("\n");
} while (a != 'q');

    return 0;
}
