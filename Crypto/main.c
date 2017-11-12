#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

void quickSort( int[], char[], int, int);
int partition( int[], char[], int, int);
char dechiffrement( char, int);
bool ecriture(int);

int main()
{
    FILE* fichier = fopen("code.txt", "r");

    const float francais[26] = {0.00,0.00,0.07,0.19,0.21,0.54,0.64,0.80,1.06,1.10,1.27,1.34,2.72,3.24,3.32,3.60,5.34,5.89,6.05,6.81,7.23,7.30,7.61,7.68,8.23,17.76};
    const char alphabet[26] = {"WKZJYXHBFGVQMPCDOLURITNASE"};
    int caractereActuel = 0;
    int taille = 0;
    int compte[26];
    int nombreNonLettre = 0;
    int nombreLettre = 0;
    int lettrepresume1,lettrepresume2,lettrepresume3;
    int decalage1,decalage2,decalage3;
    int certitude = 90;
    float pourcent;
    char lettre[26];
    bool verifLettre;
    bool finish=false,bruteForceMod=false;

    // Initialisation du tableau des occurences
    for(int i = 0; i < 26 ; i++){
            compte[i]=0;
    }

    // Initialisation du tableau des lettres
    for(int i = 0; i<=25; i++){
            lettre[i]=i+65;
    }


    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère

            verifLettre=false; // On déclare le caractere comme n'étant pas une lettre

            // Compte du nombre d'occurence pour chaque lettre en ignorant la casse
            for(int j = 65 ; j <=90 ; j++){
                    if(caractereActuel==j || caractereActuel==j+32){
                    compte[j-65]=compte[j-65]+1;
                    verifLettre = true; // On déclare le caractère comme étant une lettre
                    }
            }

            // On remplace les caractère "éèê" par "e"
            if(caractereActuel==233 || caractereActuel==234 || caractereActuel==235){
                    compte[4]=compte[4]+1;
                    caractereActuel=101;

            }

            // Si le caractère n'est pas une lettre, on incrémente le compteur correspondant
            if(verifLettre==false){
                 nombreNonLettre++;
            }

            taille++; // On incrémente le compteur de la taille en caractère du document

        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)

        nombreLettre = taille - nombreNonLettre; // On calcule le nombre de lettre totale afin de pouvoir déduire un pourczntage

    }

    printf("\n");

    // Uniquement pour faire jolie
    printf("Analyse du texte en cours");
    for(int i =0; i<4 ; i++){
            printf(" .");
            Sleep(500);
    }
    printf("\n");

    // Affichage des résultat ( Version nombre d'occurences )
    for(int i = 0; i <26 ; i++){
            printf("%c : %d \n",i+65,compte[i]);
    }

    printf("\n\n");

    // On trie les pourcentage d'appariton dans l'ordre croissant
    quickSort( compte,lettre, 0, 25);

    // On affiche les pourcentages
    printf("POURCENTAGE DU TEXTE     POURCENTAGE LANGUE FRANCAISE\n\n");
    for(int i = 0; i <26 ; i++){
            pourcent = 100 * ( (float)compte[i] / (float)nombreLettre );
            printf("     %c = %0.2f\%    ========     %c = %0.2f\%\n",lettre[i],pourcent,alphabet[i],francais[i]);
    }

    // On calcul le décalage présumé à partir du pourcentage de "e"
    lettrepresume1 = (int)lettre[25]-64;
    decalage1 = lettrepresume1-5;

    lettrepresume2 = (int)lettre[24]-64;
    decalage2 = lettrepresume2-5;

    lettrepresume3 = (int)lettre[23]-64;
    decalage3 = lettrepresume3-5;

    if(decalage1==decalage2){
            certitude = 95;
    }

    if(decalage1==decalage3){
            certitude = 95;
    }

    if(decalage1==decalage2==decalage3){
            certitude = 99;
    }

    fclose(fichier);
    printf("\nLe decalage presume est de %d avec une certitude de %d\%\n\n",decalage1,certitude);

    // On propose de déchiffrer à partir des décalages les plus probables
    if(ecriture(decalage1)==false){
            if(ecriture(decalage2)==false){
                    if(ecriture(decalage3)==false){
                        bruteForceMod = true;
                    }
            }
    }

    // Si les essais précédents n'ont rien donné, on brute force le décalage
    if(bruteForceMod==true){

            for(int i = 1; i <= 26; i++){
                    printf("    [Brute Force Mode Active]\n\n");
                    if(ecriture(i)==true){
                       break;
                   }
            }
    }

    getch();

    return 0;
}

char dechiffrement( char lettre, int decalage){
    if(lettre==233 || lettre==234 || lettre==235){
                    lettre=101;
            }

            if(lettre>=65 && lettre<=90){
                    lettre = lettre - decalage;
                    if(lettre<65){
                        lettre=lettre+26;
                    }
            }
            if(lettre>=97 && lettre<=122){
                    lettre = lettre - decalage;
                    if(lettre<97){
                        lettre=lettre+26;
                    }
            }
            return lettre;
}

bool ecriture(int decalage){
    FILE* fichier = fopen("code.txt", "r");
    FILE* fichier2 = fopen("decode.txt", "w");

    char caractereActuel,reponse;

    printf("Voici le debut du texte dechiffre avec un decalage de %d :\n   \"",decalage);
    rewind(fichier);

    for(int i = 0 ; i<=50 ; i++){
            caractereActuel = fgetc(fichier);
            printf("%c",dechiffrement(caractereActuel,decalage));
    }

    rewind(fichier);
    printf("...\"\n\n");
    printf("   Le texte a t-il ete correctement dechiffrer ? o/n : ");

    scanf("%c",&reponse);
    getchar();
    printf("\n");
    if(reponse=='o'){
        while (caractereActuel != EOF){
            caractereActuel = fgetc(fichier);
            caractereActuel = dechiffrement(caractereActuel,decalage);
            fputc(caractereActuel, fichier2);
        }
        fclose(fichier);
        fclose(fichier2);
        printf("OK");
        system("decode.txt");
        return true;
    }
    fclose(fichier);
    fclose(fichier2);
    system("cls");
    return false;
}

void quickSort( int a[],char verif[], int l, int r)
{
        int j;

        if( l < r )
        {
                // divide and conquer
                j = partition( a,verif, l, r);
                quickSort( a,verif, l, j-1);
                quickSort( a,verif, j+1, r);
        }

}

int partition( int a[],char verif[], int l, int r) {
        int pivot, i, j, t;
        char tampon;
        pivot = a[l];
        i = l; j = r+1;

        while( 1)
        {
                do ++i; while( a[i] <= pivot && i <= r );
                do --j; while( a[j] > pivot );
                if( i >= j ) break;
                t = a[i]; a[i] = a[j]; a[j] = t;
                tampon = verif[i]; verif[i]=verif[j]; verif[j]=tampon;

        }

        t = a[l]; a[l] = a[j]; a[j] = t;
        tampon = verif[l]; verif[l]=verif[j]; verif[j]=tampon;
        return j;
}
