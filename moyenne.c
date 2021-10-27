float moyenne(float T[]){
    float somme=0;
    for(int i = 0; i < 50; i++){
        somme += T[i];
    }
    return somme/50;
}