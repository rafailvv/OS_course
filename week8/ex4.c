#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    char *arr;
    int bytes = (10*1024*1024);

    for (int j = 0; j < 10; ++j) {
        arr = (char *) malloc(bytes);
        for (int i = 0; i < bytes; ++i) {
            arr[i] = '0';
        }
        int who = RUSAGE_SELF;
        struct rusage r_usage;
        int ret = getrusage(who, &r_usage);
        printf("%ld\n", r_usage.ru_maxrss);
        sleep(1);
        free(arr);
    }



    return 0;
}