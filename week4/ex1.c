#include <stdio.h>
#include <unistd.h>

int main() {
    int fork_var = fork();
    int n = 10;
    if (fork_var == 0)
        printf("Hello from child [%d - %d]\n", getpid(),n);
    else if (fork_var < 0)
	printf("Error...");
    else
        printf("Hello from parent [%d - %d]\n",getpid(), n);
    return 0;
}

