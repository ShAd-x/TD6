#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argn, char *argv[], char *arge[]) {
    float *tablo = (float*) malloc(150 * sizeof(float));

    if(argn < 2){
        printf("Un argument est requis\n");
        return 2;
    } else {
        int file = open(argv[1], O_RDONLY);
        if (file != -1) {
            for(int i = 0; i<150; i++){
                tablo[i] = read(file, tablo, 150*sizeof(float));
            }
            for(int i = 1; i<=3; i++){
                printf("%d\n", i);
                for(int y = 1; y<=50; y++){
                    printf("%f\n", tablo[y]);
                } 
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