float mini(float T[]){
    float minimum;
    minimum = T[1];
    for(int i = 0; i < 50; i++) {
        if(T[i] < minimum)
            minimum = T[i];
    }
    return minimum;
}