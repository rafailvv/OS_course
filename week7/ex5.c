#include <stdio.h>
#include "stdlib.h"
//The segmentation fault is that char **s doesn't allocate into the heap
//Therefore we shoud fix it using the malloc() method
int main () {
    char **s = malloc(sizeof(char *));
    char foo [] = "Hello World";
    *s = foo;
    printf ("s is %p\n" ,s);        // Also I was changed %s to the %p, becuase we should print a pointer instead of a string
    s[0] = foo ;
    printf ("s[0] is %s\n" ,s [0]) ;
    return (0) ;
}