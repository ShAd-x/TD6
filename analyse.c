#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

float Tab1[50];
float Tab2[50];
float Tab3[50];

float moyenne(float[]);
float mini(float[]);
float maxi(float[]);

int main(int argn, char *argv[], char *arge[]) {
    float *tablo = (float*) malloc(150 * sizeof(float));

    if(argn < 2){
        printf("Un argument est requis\n");
        return 1;
    } else {
        int file = open(argv[1], O_RDONLY);
        if (file != -1) {
            for(int i = 1; i<150; i++){
                *tablo = read(file, tablo, 150*sizeof(float));
                printf("%d: %f\n", i, tablo[i]);
            }
            printf("Espece Iris Setosa :\n");
            for(int i=1, y=0; i<=49; i++, y++){ //pas bonne valeur pour le 1er
                Tab1[y] = tablo[i];
            }
            printf("Moyenne: %f\n", moyenne(Tab1));
            printf("Maximum: %f\n", maxi(Tab1));
            printf("Minimum: %f\n", mini(Tab1));

            printf("Espece Iris Versicolor :\n");
            for(int i=50, y=0; i<=99; i++, y++){
                Tab2[y] = tablo[i];
            }
            printf("Moyenne: %f\n", moyenne(Tab2));
            printf("Maximum: %f\n", maxi(Tab2));
            printf("Minimum: %f\n", mini(Tab2));

            printf("Espece Iris Virginica :\n");
            for(int i=100, y=0; i<=149; i++, y++){
                Tab3[y] = tablo[i];
            }
            printf("Moyenne: %f\n", moyenne(Tab3));
            printf("Maximum: %f\n", maxi(Tab3));
            printf("Minimum: %f\n", mini(Tab3));
        } else {
            perror (argv[1]);
            return 2;
        }
    }
    return 0;
}

float moyenne(float T[]){
    float somme=0;
    for(int i = 0; i <= 50; i++){
        somme += T[i];
    }
    return somme/50;
}

float maxi(float T[]){
    float max = T[1];
    for(int i = 0; i < 50; i++) {
        if(max < T[i])  
            max = T[i];
    }
    return max;
}

float mini(float T[]){
    float minimum;
    minimum = T[1];
    for(int i = 0; i < 50; i++) {
        if(T[i] < minimum)
            minimum = T[i];
    }
    return minimum;
}
// gcc analyse.c -o analyse -Wall
// .\analyse.exe iris.dat