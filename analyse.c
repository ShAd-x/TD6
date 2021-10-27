#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* prototypes des fonctions externes */
// float moyenne(float[]);  Inutile car pas appellée dans cette classe.
// float mini(float[]);     Inutile car pas appellée dans cette classe.
// float maxi(float[]);     Inutile car pas appellée dans cette classe.
void affiche(float[]);

int main(int argn, char *argv[], char *arge[]) {
    float *tablo = (float*) malloc(150 * sizeof(float));
    float Tab[50];
    if(argn < 2){
        printf("Un argument est requis\n");
        return 1;
    } else {
        int file = open(argv[1], O_RDONLY);
        if (file != -1) {
            for(int i = 1; i<150; i++){
                *tablo = read(file, tablo, 150*sizeof(float));
            }
            printf("Espece Iris Setosa :\n");
            for(int i=1, y=0; i<=50; i++, y++){ // pas bonne valeur pour le 1er (J'ai mis 50 et ça donne des trucs)
                Tab[y] = tablo[i];
            }
            affiche(Tab);

            printf("Espece Iris Versicolor :\n");
            for(int i=50, y=0; i<=99; i++, y++){
                Tab[y] = tablo[i];
            }
            affiche(Tab);

            printf("Espece Iris Virginica :\n");
            for(int i=100, y=0; i<=149; i++, y++){
                Tab[y] = tablo[i];
            }
            affiche(Tab);
        } else {
            perror (argv[1]);
            return 2;
        }
    }
    return 0;
}
// gcc analyse.c moyenne.c maximum.c minimum.c affichage.c -o analyse -Wall
// .\analyse.exe iris.dat