#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int* my_realloc(int* ptr, int old_size, int new_size){
    if(ptr==NULL) {
        return malloc(sizeof(int)*new_size);
    }
    if (new_size == 0) {
        free(ptr);
    } else if(new_size>old_size) {
        int* new_arr = malloc(sizeof(int)*new_size);
        for (int i = 0; i < old_size; ++i) {
            new_arr[i] = ptr[i];
        }
        return new_arr;
    } else {
        return ptr;
    }
}

int main(){
    //Allows you to generate random number
    srand(time(NULL));

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size:");
    int n1=0;
    scanf("%d",&n1);

    //Create a new array of n1 ints
    int* a1 = malloc(sizeof(int) * n1);
    int i;
    for(i=0; i<n1; i++){
        a1[i] = 100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2=0;
    scanf("%d",&n2);

    //Dynamically change the array to size n2
    a1 = my_realloc(a1, n1, n2);

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    if (n2>n1){
        for (int j = n1; j < n2; ++j) {
            a1[j] = 0;
        }
    }


    for(i=0; i<n2;i++){
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D

    return 0;
}