#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

  FILE *inputFile = fopen("/mnt/Cours/SystemeInfo/TP3/graph.bmp", "r");
  FILE *outputFile = fopen("/mnt/Cours/SystemeInfo/TP3/test.bmp", "w");

  unsigned int c=0;



  for(int i = 0; i < 56; i++) {
    fread(&c, 1, 1, inputFile);
    fwrite(&c, 1, 1, outputFile);
  }

  for(int i = 3; i < 419523; i++) {
    fread(&c, 1, 1, inputFile);
    if (i%3==0) {
        c = 255;
    }
    fwrite(&c, 1, 1, outputFile);
  }


fclose(inputFile);
fclose(outputFile);

return 0;
}
