/*
CONTENU      : TP2 EX6
AUTEUR       : PIGNOL Maël
CEATION     : 15/09/2017
MODIFICATION : 15/09/2017
*/

// librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,a,b=10;

int main (void)
{
    int nombre = 0;
    const int MIN = 1, MAX = 100;
    srand(time(NULL));

    nombre = (rand() % (MAX + 1 - MIN)) + MIN;

    while ( a!=nombre && b != 0) {
      printf("Il vous reste %d essais\n\n",b);
      printf("Entrez un nombre : ");
      scanf("%d",&a);
      if (a>nombre) {
        printf("Plus petit !\n");
        b--;
      }
      else if (a<nombre){
        printf("Plus grand !\n");
        b--;
      }
      else {}
    }

if (b == 0) {
  printf("Perdu!\n");
}
else {
  printf("Gagné!\n");
}
    return 0;
}
