float mini(float T[]){ // fonction qui retourne la valeur minimum du tableau rentré en paramètre
    float minimum = T[1];
    for(int i = 0; i < 50; i++) {
        if(T[i] < minimum)
            minimum = T[i];
    }
    return minimum;
}