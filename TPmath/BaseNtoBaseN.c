#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define couleur(param) printf("\033[%sm",param)

int taille (int a){
        // Sépare unité par unité les différents chiffre d'un nombre
        int n;
        if (a != 0) {
                n = log10(a);
                a = a/ (int)pow(10, n);
                return a;
        } else {
                return a;
        }
}

int longueur (int a){
        // Détermine la longueur d'un nombre
        int n;
        n = log10(a)+1;
        return n;
}

int BaseNtoDec (int baseB,int nombreB){
        // Convertit un nombre d'une base N vers la base 10
        int i=0,c=0,j=1,k=0,b=0,e=0,f=0,nbmax;

        nbmax = longueur(nombreB);

        while (k != nbmax) {

                b = nombreB % (int)pow(10, j) - e;
                f = taille(b);
                e = e + b;
                c = c + (f * (int)pow(baseB, i));
                i++; j++; k++;
        }
        return c;
}

int DectoBaseN (int baseA, int nombreA){
        // Convertit un nombre de la base 10 vers une base N
        int b,i=0,c=0;

        while (nombreA != 0) {

                b = nombreA % baseA;
                nombreA = nombreA / baseA;
                c = c + b * pow(10, i);
                i++;
        }
        return c;
}

int main (void){
        int nombreDeb,baseDeb,baseFin,nbDec;

        printf("Bienvenue dans un convertisseur de nombre de base X vers une base Y\n");
        printf("X et Y doivent être inférieur à 10\n\n");

        printf("Entrez votre nombre de départ : ");
        scanf("%d",&nombreDeb);
        printf("\nEntrez la base de votre nombre de départ : ");
        scanf("%d",&baseDeb);
        printf("\nEntrez la base dans laquelle vous souhaitez convertir votre nombre : ");
        scanf("%d",&baseFin);

        if (baseDeb == 10) {
                if (baseFin > 1 && baseFin < 10) {
                        couleur("32");
                        printf("%d en base 10 est égale à %d en base %d\n",nombreDeb,DectoBaseN(baseFin,nombreDeb),baseFin);
                        couleur("0");
                } else {
                        couleur("31");
                        printf("\nERROR : La base du nombre de fin n'est pas correcte\n");
                        couleur("0");
                }
        } else if (baseDeb > 1 && baseDeb < 10) {
                if (baseDeb != baseFin && baseFin > 1 && baseFin < 10) {
                        nbDec = BaseNtoDec(baseDeb,nombreDeb);
                        couleur("32");
                        printf("%d en base %d est égale à %d en base %d\n",nombreDeb,baseDeb,DectoBaseN(baseFin,nbDec),baseFin);
                        couleur("0");
                } else if ( baseFin == 10 ) {
                        couleur("32");
                        printf("%d en base %d est égale à %d en base 10\n",nombreDeb,baseDeb,BaseNtoDec(baseDeb,nombreDeb));
                        couleur("0");
                }
                else {
                        couleur("31");
                        printf("\nERROR : La base du nombre de fin n'est pas correcte\n");
                        couleur("0");
                }
        } else {
                couleur("31");
                printf("\nERROR : La base du nombre de départ n'est pas correcte\n");
                couleur("0");
        }
        return 0;
}
