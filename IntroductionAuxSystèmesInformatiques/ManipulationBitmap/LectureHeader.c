#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *inputFile = fopen("/mnt/Cours/SystemeInfo/TP3/graph.bmp", "r");

  unsigned char c;
  unsigned int a=0;
  unsigned int o=0;
  unsigned int JUL=0;

  for(int i = 0; i < 2; i++) {
  fread(&c, 1, 1, inputFile);
  printf("%c ",c);
  }
printf("\n");
  for (int i = 0; i < 1; i++) {
    fread(&a, 4, 1, inputFile);
    printf("%d ",a);
  }
printf("\n");
  for (int i = 0; i < 12; i++) {
    fread(&JUL, 2, 1, inputFile);
    printf("%d ",JUL);
  }

printf("\n");

  for (int i = 0; i < 25 ; i++) {
    fread(&o, 1, 1, inputFile);
    printf("%d ",o);
  }


  fclose(inputFile);

  return 0;
}
