#include <stdio.h>

float moyenne(float[]);
float mini(float[]);
float maxi(float[]);

void affiche(float Tab[]){
    printf("    Moyenne: %f\n", moyenne(Tab));
    printf("    Maximum: %f\n", maxi(Tab));
    printf("    Minimum: %f\n", mini(Tab));
}