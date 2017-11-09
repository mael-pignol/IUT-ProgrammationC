/*
CONTENU      : TP2 EX6
AUTEUR       : PIGNOL Maël
CEATION     : 15/09/2017
MODIFICATION : 15/09/2017
*/

// librairies
#include <stdio.h>
#include <stdlib.h>

int a,n,i,m;

int main (void)
{
  scanf("%d",&n);
  m = 1;
  i = 0;
  a = 0;

  while (n > i) {
    a = a + ( m * 2);
    m++;
    i = i + 2;
  }


printf("%d\n",a);
    return 0;
}
