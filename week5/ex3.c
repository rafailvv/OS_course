#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 50
#define TRUE 1

int bConsumerSleeping = 0, bProducerSleeping = 0;
int position = 10;

void* consume(){
    while(TRUE){
        if(bConsumerSleeping){
            continue;
        }

        if(position == 0){
            bProducerSleeping = 0;
            bConsumerSleeping = 1;
        } else {
            printf("I am consumer - %d\n", position);
            --position;
        }
    }
}

void* produce(){
    while(TRUE){
        if(bProducerSleeping){
            continue;
        }

        if(position == MAX){
            bConsumerSleeping = 0;
            bProducerSleeping = 1;
        }else{
            printf("I am producer - %d\n", position);
            ++position;
        }
    }
}

int main(){
    pthread_t tProduce, tConsume;
    pthread_create(&tProduce, NULL, produce, NULL);
    pthread_create(&tConsume, NULL, consume, NULL);

    pthread_join(tProduce, NULL);
    pthread_join(tConsume, NULL);

    exit(EXIT_SUCCESS);
}
