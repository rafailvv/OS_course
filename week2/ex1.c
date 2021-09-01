#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int int_var;
    float float_var;
    double double_var;

    int_var = INT_MAX;
    float_var = FLT_MAX;
    double_var = DBL_MAX;

    printf("Size of integer variable is %d and maximum value is %lu\n", int_var, sizeof(int_var));
    printf("Size of float variable is %f and maximum value is %lu\n", float_var, sizeof(float_var));
    printf("Size of double variable is %f and maximum value is %lu\n", double_var, sizeof(double_var));
}


