/*
   CONTENU      : DEVOIR MAISON MATHS DISCRETES
   AUTEUR       : PIGNOL Maël
   DATE         : 04/10/2017
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long PUISSANCE(unsigned long x,unsigned long n,unsigned long mod) {
        if (n==1) {
                return x;
        } else if (fmod(n,2)==0) {
                return (PUISSANCE( fmod( pow(x,2),mod ),n/2,mod));
        } else {
                return (x * PUISSANCE( fmod( pow(x,2),mod ),(n-1)/2,mod) % mod);
        }
}


int main(void)
{
        unsigned long x,n,mod;
        unsigned long puiss;
        scanf("%lu",&x);
        scanf("%lu",&n);
        scanf("%lu",&mod);
        puiss = PUISSANCE(x,n,mod);
        printf("%lu\n",puiss);

        return 0;
}
