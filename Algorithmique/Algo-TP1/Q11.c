/*
CONTENU      : TD1 Q11
AUTEUR       : PIGNOL Maël
CEATION     : 07/09/2017
MODIFICATION : 07/09/2017
*/

// librairies
#include <stdio.h>
#include <stdlib.h>

float m ;
float p ;

// corps du programme principal
int main (void)
{
    printf("Rentrez le prix\n");
    scanf("%f",&m);

    if (m > 300.0) {
      p = m - ( m * 0.05 );
    }
    else {
      p = m;
    }

    
    printf("%f\n",p);
    return 0;
}
