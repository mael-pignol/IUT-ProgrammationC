#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputIMG = fopen("graph.bmp", "r");
    FILE *inputTXT = fopen("stega.txt", "r");
    FILE *outputIMG = fopen("test.bmp", "w");

    unsigned int copie = 0;
    unsigned int ecriture;
    unsigned int a = 0;
    unsigned int tailleEnOctect;
    unsigned int offset;
    unsigned int tailleDisponible;
    unsigned int lettre = 0;
    int codage[50000];
    int l = 16;
    int nbDeChar = 0;
    int TailleMessage;
    int CaractereActuel;
    int TAILLEMESSAGE;

    for (int i = 0; i < 2; i++)
    {
        fread(&a, 1, 1, inputIMG);
    }

    fread(&a, 4, 1, inputIMG);
    tailleEnOctect = a;
    fread(&a, 4, 1, inputIMG);
    fread(&a, 4, 1, inputIMG);
    offset = a;
    tailleDisponible = tailleEnOctect - offset;

    rewind(inputIMG);

    while (lettre != EOF)
    {
        lettre = fgetc(inputTXT);
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

    TailleMessage = nbDeChar * 7;
    
    TAILLEMESSAGE = TailleMessage;

    for (int j = 0; j <= 15; j++)
    {
        codage[j] = TailleMessage % 2;
        TailleMessage = TailleMessage / 2;
    }

    rewind(inputIMG);

    for (int j = 0; j < offset; j++)
    {
        fread(&copie, 1, 1, inputIMG);
        fwrite(&copie, 1, 1, outputIMG);
    }

    for (int j = 0; j < tailleDisponible; j++)
    {
        fread(&copie, 1, 1, inputIMG);
        ecriture = copie;

        
        if (j < TAILLEMESSAGE + 16)
        {
            CaractereActuel = codage[j];

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

        }

        fwrite(&ecriture, 1, 1, outputIMG);
    }

    fclose(inputIMG);
    fclose(inputTXT);
    fclose(outputIMG);

    return 0;
}
