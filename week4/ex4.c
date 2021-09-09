#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int k = 0;
    char* argv[50];
    char input[50];
    printf(">");
    gets(input);
    char *input_split = strtok(input, " ");
    while (input_split != NULL){
        argv[k] = input_split;
        input_split = strtok(NULL, " ");
        k++;
    }
    if (fork() == 0){
        execvp(argv[0], argv);
    }
    return 0;
}
