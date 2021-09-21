#include <stdio.h>
#include <pthread.h>

typedef struct {
    int number;
} thread_info;


void *show_info(void *args) {
    thread_info *tread = args;
    printf("I am a thread %d\n", tread->number);

    return 0;
}

int main(){
    pthread_t thread_id;
    int n = 5;
    printf("n = ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        thread_info new_tread;
        new_tread.number = i+1;
        printf("Creating thread %d\n", i+1);
        pthread_create(&thread_id, NULL, &show_info, &new_tread);
        printf("Terminating of thread %d\n", i+1);
    }
    pthread_exit(NULL);
}

