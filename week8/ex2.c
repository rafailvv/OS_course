#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    int i;
    for(i = 0; i < 10; ++i){
        int bytes = 10*1024*1024;
        char* arr = (char*)malloc(bytes);
        memset(arr, 0, bytes);
        sleep(1);
    }
}