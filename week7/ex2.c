#include <stdio.h>
#include <stdlib.h>

void print_arr(int* arr, int size){
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void filling_arr(int* arr, int size){
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }
}

int main() {
    int n;
    printf("N = ");
    scanf("%d", &n);
    int* arr = malloc(sizeof(int)* n);
    if(arr!=NULL) {
        filling_arr(arr, n);
        print_arr(arr, n);
        free(arr);

    } else {
        printf("Pointer is NULL");
    }
    
    return 0;
}