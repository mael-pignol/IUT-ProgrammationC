#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a,b,i,c,j,k,e,f,nbmax;

int taille (int a){
        int n;
        if (a != 0) {
                n = log10(a);
                a = a/ (int)pow(10, n);
                return a;
        } else {
                return a;
        }
}

int taillemax (int a){
        int n;
        n = log10(a)+1;
        return n;

}
// corps du programme principal
int main (void)
{
        i = 0;
        c = 0;
        j = 1;
        k = 0;
        b = 0;
        e = 0;
        f = 0;

        printf("BASE 2 TO DECMAL\n");


        printf("Entrer votre nombre\n");
        scanf("%d",&a);
        nbmax = taillemax(a);
        printf("%d",nbmax);




        while (k != nbmax) {

                b = a % (int)pow(10, j) - e;
                f = taille(b);

                e = e + b;
                printf("\n%d",f);

                c = c + b * (int)pow(2, i);
                // printf("\n%d",c);
                i++;
                j++;
                k++;
        }
        printf("\n%d",c);
        return 0;
}
