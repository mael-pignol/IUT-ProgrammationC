#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  FILE *inputFile = fopen("/mnt/Cours/SystemeInfo/TP3/graph.bmp", "r");
  FILE *outputFile = fopen("/mnt/Cours/SystemeInfo/TP3/test.bmp", "w");

  int tailleEnOctect=0;
  unsigned char c;
  unsigned char d;
  unsigned int a=0;

  for(int i = 0; i < 2; i++) {
  fread(&c, 1, 1, inputFile);
  printf("%c ",c);
  }

  for (int i = 0; i < 1; i++) {
    fread(&a, 8, 1, inputFile);
  }

  tailleEnOctect = a;

  printf("%d\n",tailleEnOctect);

  rewind(inputFile);

  for(int i = 0; i <= tailleEnOctect-1; i++) {
  fread(&d, 1, 1, inputFile);
  fwrite(&d, 1, 1, outputFile);
  }
  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
