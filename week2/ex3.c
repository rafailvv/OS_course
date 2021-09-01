#include <stdio.h>

int main(int argc, char *argv[]) {
    int n;
    if(argc > 1){
        sscanf(argv[1], "%d", &n);
    }

    int k = - 1;
    for (int i = n; i > 0; i--){
        k += 2;
        for (int j = 0; j < i-1; j++){
            printf(" ");
        }
        for (int j = 0; j < k; j++){
            printf("*");
        }
        printf("\n");
    }
}	
