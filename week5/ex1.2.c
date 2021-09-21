#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>

typedef struct {
    pthread_t pthread_id;
    int pthread_number;
    char *argv_string;
} thread_info;


void *job(void *args) {
    thread_info *threadInfo = args;
    printf("I am a thread %d\n", threadInfo->pthread_number);

    return 0;
}

int main(int argc, char *argv[]){
    int n, cur_thread;
    thread_info *threadInfo;
    void *result;
    pthread_t new_thread;

    printf("n = ");
    scanf("%d", &n);

    threadInfo = calloc(n, sizeof(thread_info));
    if (threadInfo == NULL){
        perror("Error of calloc operation");
    } else {
        for (int i = 0; i < n; ++i) {
            threadInfo[i].pthread_number = i + 1;

            printf("Thread %d is started\n", i+1);
            cur_thread = pthread_create(&new_thread, NULL, &job, &threadInfo[i]);
            threadInfo[i].pthread_id = new_thread;
        }

        for (int i = 0; i < n; ++i) {
            cur_thread = pthread_join(threadInfo[i].pthread_id, &result);
            printf("Joined with thread %d\n", threadInfo[i].pthread_number);
            free(result);
        }
    }
    pthread_exit(&cur_thread);
}

