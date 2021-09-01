#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 50

int main() {
    printf("Print the string: ");
    char str_var[MAX_LIMIT];
    gets(str_var);
    printf("The reverse input string is ");
    for (int i = 0; i < strlen(str_var); i++){
        putchar(str_var[strlen(str_var) - i - 1]);
    }
printf("\n");
}
