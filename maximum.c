float maxi(float T[]){
    float max = T[1];
    for(int i = 0; i < 50; i++) {
        if(max < T[i])  
            max = T[i];
    }
    return max;
}