/*
CONTENU      : TP2 EX4
AUTEUR       : PIGNOL Maël
CEATION     : 15/09/2017
MODIFICATION : 15/09/2017
*/

// librairies
#include <stdio.h>
#include <stdlib.h>

int a,n;

int main (void)
{
  a = 1;
  scanf("%d",&n);
do
{
    printf("%d\n",a);
    a++;
} while (a < n);

printf("%d\n",n);
    return 0;
}
