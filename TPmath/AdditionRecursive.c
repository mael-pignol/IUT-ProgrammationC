/*
CONTENU      : TP MATH
AUTEUR       : PIGNOL Maël
CEATION     : 14/09/2017
MODIFICATION : 14/09/2017
*/

#include <stdio.h>

int add(int n, int x)
{
  if (n > 0){
    x = add(n-1, x) + 1;
  }
  else
    return x;
  }

int main(void)
{
  int n,x;
  printf("Rentrer a\n");
  scanf("%d",&n);
  printf("Rentrer b\n");
  scanf("%d",&x);

  printf("%d + %d = %d\n", n, x, add(n, x));
  return 0;
}
