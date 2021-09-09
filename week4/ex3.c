#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    while (1){
        char input[50];
        printf(">");
        fgets(input, 50, stdin);
        system(input);
    }
    return 0;
}
