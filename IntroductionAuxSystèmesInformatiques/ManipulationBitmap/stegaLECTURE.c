#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputIMG = fopen("test.bmp", "r");
    FILE *outputTXT = fopen("decode.txt", "w");
    

    unsigned int c = 0;
    unsigned int a = 0;
    unsigned int tailleEnOctect;
    unsigned int offset;
    unsigned int tailleDisponible;
    unsigned int lettre = 0;
    int codage[50000];
    int code[50000];
    char LESlettre[50000];
    int i = 0;
    int TEST;
    int l = 16;
    int nbDeChar = 0;
    int TailleMessage=0;
    int Lettre=0;
    int CaractereActuel;
    char CARA;

    for (int i = 0; i < 2; i++)
    {
        fread(&c, 1, 1, inputIMG);
    }
  //  printf("\n");

    fread(&a, 4, 1, inputIMG);
    tailleEnOctect = a;
 //   printf("%d ", a);
    fread(&a, 4, 1, inputIMG);
    fread(&a, 4, 1, inputIMG);
    offset = a;
  //  printf("%d ", a);

    printf("%d\n%d\n", tailleEnOctect, offset);

    tailleDisponible = tailleEnOctect - offset;
  //  printf("%d\n", tailleDisponible);

    rewind(inputIMG);


    for ( int j=0; j < offset ; j++)
    {
        fread(&c, 1, 1, inputIMG);
        printf("%d\n",c);
    }

    for (int j = 0; j <= 15; j++)
    {
      fread(&c, 1, 1, inputIMG);
      printf("%d\n",c);
      if(c%2==0){
          codage[j] = 0 ;
      } else {
          codage[j] = 1 ;
      }
      
    }

    for (int j = 15; j >= 0; j--)
    {
        printf("%d\n",codage[j]);
        TailleMessage = 2 * TailleMessage + codage[j];
    }


    printf("\n\n%d\n\n",TailleMessage);

    for (int j = 0; j <= TailleMessage; j++)
    {
      fread(&c, 1, 1, inputIMG);
      printf("%d\n",c);
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
        printf("CODe : %c\n",LESlettre[j]);
        CARA = LESlettre[j];
        fwrite(&CARA, 1, 1, outputTXT);

    }


/*


    for (int j = 0; j <= 15; j++)
    {
        codage[j] = TailleMessage % 2;
        TailleMessage = TailleMessage / 2;
    }

    for (int j = 0; j < nbDeChar * 7 + 16; j++)
    {
        TEST = codage[j];
        printf("%d\n", TEST);
    }



    for (int j = 0; j <= offset; j++)
    {
        fread(&c, 1, 1, inputIMG);
        fwrite(&c, 1, 1, outputIMG);
    }

    for (int j = 0; j < tailleDisponible; j++)
    {
        fread(&c, 1, 1, inputIMG);
        if(j<TailleMessage){
            CaractereActuel = codage[j];

            if(c%2==0){
                if(CaractereActuel==0){
                    c = c;
                } else {
                    c = c + 1;
                }

            } else {
                if (CaractereActuel==0){
                    c = c +1;
                } else {
                    c = c;
                }
            }

        }
       
        fwrite(&c, 1, 1, outputIMG);
    }

*/
    return 0;
}
