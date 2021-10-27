float moyenne(float T[]){ // fonction qui retourne la moyenne des valeurs du tableau rentré en paramètre
    float somme=0;
    for(int i = 0; i < 50; i++){
        somme += T[i];
    }
    return somme/50;
}