/*
CONTENU      : TD1 Q13
AUTEUR       : PIGNOL Maël
CEATION     : 07/09/2017
MODIFICATION : 07/09/2017
*/

// librairies
#include <stdio.h>
#include <stdlib.h>

int a ;

// corps du programme principal
int main (void)
{
  printf("ENTREZ L'ANNE A TESTER LE PROGRAMME VOUS DIRA SI ELLE EST BISSEXTILE OU NON\n");
  scanf("%d",&a);

if ((a%400==0) || ((a%4==0)&&(a%100!=0))) {
    printf(" L'année %d est bissextile\n",a);
} else {
    printf(" L'année %d n'est pas bissextile\n",a);
}

    return 0;
}
