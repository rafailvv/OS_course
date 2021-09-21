#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    pthread_t thread_id;
    int thread_number;
    char* string;
} thread_info;


void *job(void *args) {
    thread_info *t = (thread_info*)args;
    printf("I am a thread %d\n", t->thread_number);
}

int main(){
    thread_info *tinfo;
    int N;
    printf("N = ");
    scanf("%d", &N);

    tinfo = calloc(N, sizeof(thread_info));
    for (int i = 0; i < N; ++i) {
        tinfo[i].thread_number = i;
        pthread_create(&tinfo[i].thread_id, NULL, job, (void*)&tinfo[i]);
    }
    exit(EXIT_SUCCESS);
}
