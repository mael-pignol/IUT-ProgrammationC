#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputIMG = fopen("graph.bmp", "r");
    FILE *inputTXT = fopen("stega.txt", "r");
    FILE *outputIMG = fopen("test.bmp", "w");

    unsigned int c;
    unsigned int copie = 0;
    unsigned int ecriture;
    unsigned int a = 0;
    unsigned int tailleEnOctect;
    unsigned int offset;
    unsigned int tailleDisponible;
    unsigned int lettre = 0;
    int codage[50000];
    int i = 0;
    int TEST;
    int l = 16;
    int nbDeChar = 0;
    int TailleMessage;
    int CaractereActuel;
    int TAILLEMESSAGE;

    for (int i = 0; i < 2; i++)
    {
        fread(&c, 1, 1, inputIMG);
    }
    // printf("\n");

    fread(&a, 4, 1, inputIMG);
    tailleEnOctect = a;
    //  printf("%d ", a);
    fread(&a, 4, 1, inputIMG);
    fread(&a, 4, 1, inputIMG);
    offset = a;
    //   printf("%d ", a);

    //   printf("%d\n%d\n", tailleEnOctect, offset);

    tailleDisponible = tailleEnOctect - offset;
    //   printf("%d\n", tailleDisponible);

    rewind(inputIMG);

    while (lettre != EOF)
    {
        lettre = fgetc(inputTXT);
        //  printf("%d\n", lettre);
        if (lettre != EOF)
        {
            for (int k = 0; k < 7; k++)
            {
                codage[l] = lettre % 2;
                lettre = lettre / 2;
                l++;
            }
            nbDeChar++;
        }
    }

    int TailleStop = TailleMessage*7;
    TailleMessage = nbDeChar * 7;
    printf("TAille stop %d\n",TailleStop);
    TAILLEMESSAGE = TailleMessage;
    printf("TailleMessage %d\n", TailleMessage);
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

    rewind(inputIMG);

    for (int j = 0; j < offset; j++)
    {
        fread(&copie, 1, 1, inputIMG);
        fwrite(&copie, 1, 1, outputIMG);
    }

    printf("Taille dispo %d\n", tailleDisponible);

    for (int j = 0; j < tailleDisponible; j++)
    {
        fread(&copie, 1, 1, inputIMG);
        /*
        printf("      %d          %d\n", j, copie);
        */
        ecriture = copie;

        
        if (j < TAILLEMESSAGE + 16)
        {
            CaractereActuel = codage[j];
            // printf("%d\n",CaractereActuel);

            if (copie % 2 == 0)
            {
                if (CaractereActuel == 0)
                {
                }
                else
                {
                    ecriture = copie + 1;
                }
            }
            else
            {
                if (CaractereActuel == 0)
                {
                    ecriture = copie - 1;
                }
                else
                {
                }
            }
            printf("%d\n",ecriture);
            printf("%d\n",codage[j]);

        }
        //   printf("%d\n",c);

        //  printf("%d\n",ecriture);
        fwrite(&ecriture, 1, 1, outputIMG);
    }

    return 0;
}
