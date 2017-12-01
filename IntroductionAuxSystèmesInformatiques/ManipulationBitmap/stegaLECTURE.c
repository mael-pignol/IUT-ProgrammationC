#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputIMG = fopen("test.bmp", "r");
    FILE *outputTXT = fopen("decode.txt", "w");

    unsigned int c = 0;
    unsigned int a = 0;
    unsigned int offset;
    int codage[50000];
    int code[50000];
    char LESlettre[50000];
    int TailleMessage=0;
    int Lettre=0;
    char CARA;

    for (int i = 0; i < 2; i++)
    {
        fread(&c, 1, 1, inputIMG);
    }

    fread(&a, 4, 1, inputIMG);
    fread(&a, 4, 1, inputIMG);
    fread(&a, 4, 1, inputIMG);
    offset = a;

    rewind(inputIMG);

    for ( int j=0; j < offset ; j++)
    {
        fread(&c, 1, 1, inputIMG);
    }

    for (int j = 0; j <= 15; j++)
    {
      fread(&c, 1, 1, inputIMG);
      if(c%2==0){
          codage[j] = 0 ;
      } else {
          codage[j] = 1 ;
      }
      
    }

    for (int j = 15; j >= 0; j--)
    {
        TailleMessage = 2 * TailleMessage + codage[j];
    }


    for (int j = 0; j <= TailleMessage; j++)
    {
      fread(&c, 1, 1, inputIMG);
      if(c%2==0){
          code[j] = 0 ;
      } else {
          code[j] = 1 ;
      }
      
    }

    for (int j = 0; j < TailleMessage/7; j++)
    {
        for(int k = 6 + (j*7) ; k >= 0 + (j*7) ; k--){
            Lettre = 2 * Lettre + code[k];
        }
        LESlettre[j] = Lettre;
        Lettre = 0 ; 
    }

    for (int j = 0; j < TailleMessage/7; j++) {
        CARA = LESlettre[j];
        fwrite(&CARA, 1, 1, outputTXT);

    }

    fclose(inputIMG);
    fclose(outputTXT);

    return 0;
}
