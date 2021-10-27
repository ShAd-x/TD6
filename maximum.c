float maxi(float T[]){ // fonction qui retourne la valeur maximum du tableau rentré en paramètre
    float max = T[1];
    for(int i = 0; i < 50; i++) {
        if(max < T[i])  
            max = T[i];
    }
    return max;
}