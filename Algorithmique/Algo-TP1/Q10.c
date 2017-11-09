/*
CONTENU      : TD1 Q10
AUTEUR       : PIGNOL Maël
CEATION     : 07/09/2017
MODIFICATION : 07/09/2017
*/

// librairies
#include <stdio.h>
#include <stdlib.h>

float r ;
const float PI = 3.14;
float p ;
// corps du programme principal
int main (void)
{
    printf("Entrez le rayon d'un cercle et le programme calculera son périmètre\n");
    scanf("%f",&r);
    p = 2.0 * PI * r;
    printf("Périmètre = %f\n",p);
    return 0;
}
