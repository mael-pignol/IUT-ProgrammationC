#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a,b,i,c,base;

// corps du programme principal
int main (void)
{
        i = 0;
        c = 0;
        printf("DECIMAL TO BASE N\n");
        printf("En quelle base souhaitez vous convertir ? : ");
        scanf("%d",&base);
        printf("\n");
        scanf("%d",&a);


        while (a != 0) {

                b = a % base;
                printf("\n%d",b);
                a = a / base;
                printf("\n%d",a);
                c = c + b * pow(10, i);
                printf("\n%d",c);
                i++;
        }
        printf("\n%d",c);
        return 0;
}
