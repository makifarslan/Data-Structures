#include <stdio.h>
#include <math.h>

void merge(int array[], int p , int q, int r){
    int n1 = (q - p + 1);
    int n2 = (r - q);
    int left[n1];
    int right[n2];
    int i, j;
    for(i = 0; i < n1; i++){
        left[i] = array[(p+1) - 1];
    }
    for(j = 0; j < n2; j++){
        right[j] = array[q + j];
    }
    i = 0;
    j = 0;
    for(int k = p; k < r; k++){
        if(left[i] <= right[j]){
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
    }
}

void merge_sort(int array[], int p, int r){
    if(p < r){
        int q = round(p + (r - p) / 2);
        merge_sort(array, p, q);
        merge_sort(array, q+1, r);
        merge(array, p, q, r);
    }
}

int main(){
    int dizi[8] = {5, 12, 8, 23, 1, 92};
    merge_sort(dizi, 0, 7);
    for(int i = 0; i < 8; i++){
        printf("%d ", dizi[i]);
    }
}