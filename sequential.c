#include <stdio.h>

int sequential_search(int array[], int n, int wanted){
    for(int i = 0; i < n; i++){
        if(array[i] == wanted){
            return i;
        }
    }
    return -1;
}

int main(){
    int dizi[100000];
    for(int i = 99999; i >= 0 ; i--){
        dizi[99999-i] = i;
    }
    
    sequential_search(dizi, 100000, 0);
    return 0;
}