/*
CONTENU      : TD1 Q12
AUTEUR       : PIGNOL Maël
CEATION     : 07/09/2017
MODIFICATION : 07/09/2017
*/

// librairies
#include <stdio.h>
#include <stdlib.h>

int a,b,c ;

// corps du programme principal
int main (void)
{
  scanf("%d",&c);
  scanf("%d",&a);
  scanf("%d",&b);
  switch (c) {
    case 0: if (a%2 == 0) {
      printf("%d est un nombre pair",a);
    } else {
      printf("%d est un nombre impair",a);    }
    break;

   case 1: if (b%2 == 0) {
     printf("%d est un nombre pair",b);
   } else {
     printf("%d est un nombre impair",b);    }
   break;

   case 2: if ( (a+b)%2 == 0) {
    printf("%d + %d est un nombre pair",a,b);
  } else {
    printf("%d + %d est un nombre impair",a,b);    }
   break;

   case 3: if ( (a*b)%2 == 0) {
    printf("%d * %d est un nombre pair",a,b);
   } else {
    printf("%d * %d est un nombre impair",a,b);    }
   break;

    }
    return 0;
}
