#include <stdio.h>

void figure1(const int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void figure2(const int *n) {
    for (int i = 0; i < *n; i++) {
        if (i < *n / 2) {
            for (int j = 0; j < i + 1; j++) {
                printf("*");
            }
        } else {
            for (int j = 0; j < *n - i; j++) {
                printf("*");
            }
        }
        printf("\n");
    }
}

void figure3(const int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            printf("*");
        }
        printf("\n");
    }
}


int main(int argc, char *argv[]){
    int n;
    if(argc > 1){
        sscanf(argv[1], "%d", &n);
        printf("%d\n", n);
    }
    figure1(&n);
    printf("\n");
    figure2(&n);
    printf("\n");
    figure3(&n);
}
