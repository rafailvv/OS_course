#include <stdio.h>

struct pair {
    int first;
    int second;
};

struct pair swap(int *first_num, int *second_num) {
    int temp = *first_num;
    *first_num = *second_num;
    *second_num = temp;
    struct pair num = {*first_num, *second_num};
    return num;
}

int main() {

    int first_num, second_num;
    printf("Print two integers each on new row:\n");
    printf("First number: ");
    scanf("%d", &first_num);
    printf("Second number: ");
    scanf("%d", &second_num);
    struct pair res = swap(&first_num, &second_num);
    printf("After swapping: %d %d\n", res.first, res.second);

}
