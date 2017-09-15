/*
CONTENU      : TD1 Q16
AUTEUR       : PIGNOL Maël
CEATION     : 07/09/2017
MODIFICATION : 07/09/2017
*/

// librairies
#include <stdio.h>
#include <stdlib.h>

int a,b50,b20,b10,b5,p2,p1 ;
int nb50,nb20,nb10,nb5,nb2,nb1 ;

// corps du programme principal
int main (void)
{
  printf("INITIALISATION DE LA CAISSE\n");

  printf("RENTREZ LE NOMBRE DE BILLETS DE 50 DISPONIBLES\n");
  scanf("%d",&nb50);

  printf("RENTREZ LE NOMBRE DE BILLETS DE 20 DISPONIBLES\n");
  scanf("%d",&nb20);

  printf("RENTREZ LE NOMBRE DE BILLETS DE 10 DISPONIBLES\n");
  scanf("%d",&nb10);

  printf("RENTREZ LE NOMBRE DE BILLETS DE 5 DISPONIBLES\n");
  scanf("%d",&nb5);

  printf("RENTREZ LE NOMBRE DE PIECES DE 2 DISPONIBLES\n");
  scanf("%d",&nb2);

  printf("RENTREZ LE NOMBRE DE PIECES DE 1 DISPONIBLES\n");
  scanf("%d",&nb1);

  printf("ENTREZ LE PRIX A RENDRE\n");
  scanf("%d",&a);

  b50 = a/50;
  nb50 = nb50-b50;
  a = a%50;

  b20 = a/20;
  nb20 = nb20-b20;
  a = a%20;

  b10 = a/10;
  nb10 = nb10-b10;
  a = a%10;

  b5 = a/5;
  nb5 = nb5-b5;
  a = a%5;

  p2 = a/2;
  nb2 = nb2-p2;
  a = a%2;

  p1 = a/1;
  nb1 = nb1-p1;

  while (nb50<0) {
    nb20 = nb20 - 2;
    b20 = b20 + 2;
    nb10 = nb10 - 1;
    b10 = b10 + 1;
    nb50 = nb50 + 1;
    b50 = b50 - 1;
  }
  while (nb20<0) {
    nb10 = nb10 - 2;
    b10 = b10 + 2;
    nb20 = nb20 + 1;
    b20 = b20 - 1;
  }
  while (nb10<0) {
    nb5 = nb5 - 2;
    b5 = b5 + 2;
    nb10 = nb10 + 1;
    b10 = b10 - 1;
  }
  while (nb5<0) {
    nb2 = nb2 - 2;
    p2 = p2 + 2;
    nb1 = nb1 - 1;
    p1 = p1 + 1;
    nb5 = nb5 + 1;
    b5 = b5 - 1;
  }
  while (nb2<0) {
    nb1 = nb1 - 2;
    p1 = p1 + 2;
    nb2 = nb2 + 1;
    p2 = p2 - 1;
  }

if (nb1<0) {
  printf("PAS ASSEZ DE SOUS DANS LA MACHINE\n");
} else {
  printf("%d billet(s) de 50\n",b50);
  printf("%d billet(s) de 20\n",b20);
  printf("%d billet(s) de 10\n",b10);
  printf("%d billet(s) de 5\n",b5);
  printf("%d piece(s) de 2\n",p2);
  printf("%d piece(s) de 1\n",p1);
}
    return 0;
}
