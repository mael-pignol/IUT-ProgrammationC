#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void helpMe(){
        printf("ALED\n");
}

int main(int argc, char *argv[])

{

        int i;
        int aide = 0;

        char help[] = "-h";
        char optionA[] = "-a";
        char optionB[] = "-b";
        char optionC[] = "-c";
        char optionD[] = "-d";

        bool testA = false,testB = false,testC = false,testD = false;

        if (argc == 1) {
                // Si pas d'argument : Retourner l'aide
                helpMe();
        }

        for (i=1; i < argc; i++) {
                // Si argument "-h" : Retourner l'aide en ignorant les autres arguemnts
                if (help[0] == argv[i][0] && help[1] == argv[i][1]) {
                        helpMe();
                        aide = 1;
                }
        }

        if (aide == 0) {
                // Vérification de l'exactitude des arguments : Si exact -> Ne rien faire | Sinon -> Afficher l'aide
                for (i=1; i < argc; i++) {
                        if (optionA[0] == argv[i][0] && optionA[1] == argv[i][1]) {
                                testA = true;
                        }
                        if (optionB[0] == argv[i][0] && optionB[1] == argv[i][1]) {
                                testB = true;
                        }
                        if (optionC[0] == argv[i][0] && optionC[1] == argv[i][1]) {
                                testC = true;
                        }
                        if (optionD[0] == argv[i][0] && optionD[1] == argv[i][1]) {
                                if (argv[i+1][0] == '0' || argv[i+1][0] == '1') {
                                        testD = true;
                                }
                        }
                        if ('0' == argv[i][0] || '1' == argv[i][0]) {
                                if (argv[i-1][0] == optionD[0] && argv[i-1][1] == optionD[1]) {
                                        testD = true;
                                }
                        }

                        if ((testA || testB || testC || testD) == false) {
                                helpMe();
                                aide = 1;
                        } else {
                                testA = testB = testC = testD = false;
                        }
                }
        }


        for (i=1; i < argc; i++) {
                if (optionA[0] == argv[i][0] && optionA[1] == argv[i][1] && aide == 0) {
                        printf("OPTION A\n");
                }
                if (optionB[0] == argv[i][0] && optionB[1] == argv[i][1] && aide == 0) {
                        printf("OPTION B\n");
                }
                if (optionC[0] == argv[i][0] && optionC[1] == argv[i][1] && aide == 0) {
                        printf("OPTION C\n");
                }
                if (optionD[0] == argv[i][0] && optionD[1] == argv[i][1] && aide == 0) {
                        if (argv[i+1][0] == '0') {
                                printf("OPTION D DE 0\n");
                        } else {
                                printf("OPTION D DE 1\n");
                        }
                }
        }

        return 0;
}
