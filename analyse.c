#include <stdio.h>

int main(int argn, char *argv[], char *arge[]) {
    if(argn < 2){
        printf("Un argument est requis\n");
        return 2;
    } else {
        FILE *fp = fopen (argv[1], "rb");
        if (fp != NULL) {
            for(int i = 1; i<=3; i++){
                for(int y = 1; y<=50; y++){
                    printf("%d\n", y); // replace y par la valeur dans le fichier
                }
                printf("%d\n", i);
            }
        } else {
            perror (argv[1]);
            return 1;
        }
        //if(fichier introuvable) return 1;
        //150 * sizeof.float
    }
    return 0;
}
// gcc analyse.c -o analyse -Wall
// .\analyse.exe iris.dat