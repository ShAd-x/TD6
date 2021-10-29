#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* prototypes des fonctions externes */
float moyenne(float[]);  
float mini(float[]);     
float maxi(float[]);     
void affiche(float[]);

int main(int argn, char *argv[], char *arge[]) {
    float *tablo = (float*) malloc(150 * sizeof(float));
    float Tab[50];
    if(argn < 2){
        printf("Un argument est requis\n"); // vérification qu'un chemin de fichier a été fournit
        return 1;
    } else {
        int file = open(argv[1], O_RDONLY);
        if (file != -1) { // check si le fichier est accessible
            for(int  CompteurTableau= 1; CompteurTableau<150; CompteurTableau++){
                *tablo = read(file, tablo, 150*sizeof(float));
            }
            printf("Espece Iris Setosa :\n");
            for(int CompteurTabSetosa=1, y=0; CompteurTabSetosa<50; CompteurTabSetosa++, y++){ // permet d'afficher les valeurs concernant L'Iris Setosa
                Tab[y] = tablo[CompteurTabSetosa];
            }
            affiche(Tab);

            printf("Espece Iris Versicolor :\n");
            for(int CompteurTabVersicolor=50, y=0; CompteurTabVersicolor<=99; CompteurTabVersicolor++, y++){ // permet d'afficher les valeurs concernant L'Iris Versicolor
                Tab[y] = tablo[CompteurTabVersicolor];
            }
            affiche(Tab);

            printf("Espece Iris Virginica :\n");
            for(int CompteurTabVirginica=100, y=0; CompteurTabVirginica<=149; CompteurTabVirginica++, y++){ // permet d'afficher les valeurs concernant L'Iris Virginica
                Tab[y] = tablo[CompteurTabVirginica];
            }
            affiche(Tab);
        } else {
            perror (argv[1]); // si le fichier n'est pas accessible, affiche l'erreur
            return 2;
        }
    }
    return 0;
}
// gcc analyse.c moyenne.c maximum.c minimum.c affichage.c -o analyse -Wall
// .\analyse.exe iris.dat