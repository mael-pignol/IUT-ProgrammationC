/*
CONTENU      : TD1 Q14
AUTEUR       : PIGNOL Maël
CEATION     : 07/09/2017
MODIFICATION : 07/09/2017
*/

// librairies
#include <stdio.h>
#include <stdlib.h>

int a,b50,b20,b10,b5,p2,p1 ;

// corps du programme principal
int main (void)
{
  printf("ENTREZ LE PRIX A RENDRE\n");
  scanf("%d",&a);

  b50 = a/50;
  a = a%50;
  b20 = a/20;
  a = a%20;
  b10 = a/10;
  a = a%10;
  b5 = a/5;
  a = a%5;
  p2 = a/2;
  a = a%2;
  p1 = a/1;

  printf("%d billet(s) de 50\n",b50);
  printf("%d billet(s) de 20\n",b20);
  printf("%d billet(s) de 10\n",b10);
  printf("%d billet(s) de 5\n",b5);
  printf("%d piece(s) de 2\n",p2);
  printf("%d piece(s) de 1\n",p1);

    return 0;
}
