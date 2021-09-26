#include <stdio.h>
#include <stdlib.h>

// Indent line between the defferent information
void indentLine(int n){
    for (int j = 0; j < n; j++){
        printf("=");
    }
}

// Finction for swaping two variables
void swap(int *pLeft, int *pRight) {
    int temp = *pLeft;
    *pLeft = *pRight;
    *pRight = temp;
}

// Reading the input data which specified by the user
void reading_input_data(int *arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        indentLine(45);
        printf("Process # %d\n", i + 1);
        *(arr + i * m + 0) = i+1;
        printf("Arrival Time is ");
        scanf("%d", (arr + i * m + 1));
        printf("Burst time is ");
        scanf("%d", (arr + i * m + 2));
    }
}

// Print the statistics with all information into the table view
void print_statistics(const int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%25d", *(arr + i * m + j));
        }
        printf("\n");
    }
}


// Sorting the array by Arrival Time
void sorting(int *arr, int n, int m) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(arr + j * m + 1) > *(arr + (j + 1) * m + 1)) {
                swap(arr + j * m + 0, arr + (j + 1) * m + 0);
                swap(arr + j * m + 1, arr + (j + 1) * m + 1);
                swap(arr + j * m + 2, arr + (j + 1) * m + 2);
            }
        }
    }
}

// Computing the Waiting Time for each process
void computingWaitingTime(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        int wt = *(arr + 1);
        for (int j = 0; j < i; j++) {
            wt = wt + *(arr + j * m + 2);
        }
        wt = wt - *(arr + i * m + 1);
        if (wt < 0) {
            *(arr + i * m + 4) = 0;
        } else {
            *(arr + i * m + 4) = wt;
        }
    }
}

// Computing the Turnaround Time for each process
void computingTurnaroundTimes(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        *(arr + i * m + 5) = *(arr + i * m + 2) + *(arr + i * m + 4);
    }
}


// Computing the Completion Time for each process
void computingCompletionTimes(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        *(arr + i * m + 3) = *(arr + i * m + 5) + *(arr + i * m + 1);
    }
}

int main(int argc, char *argv[]) {
    int n;
    if(argc > 1){
        sscanf(argv[1], "%d", &n);
        printf("N = %d\n", n);
    }

    int m = 6;
    int quantum;
    int *input_data = (int *) malloc(n * m * sizeof(int));
    reading_input_data(input_data, n, m);

    sorting(input_data, n, m);

    printf("%26s", "Statistics\n");
    indentLine(160);
    printf("\n%25s%25s%25s%25s%25s%26s", "Process id", "Arrival Time", "Burst Time", "Completion Time", "Waiting Time",
           "Turnaround Time\n");
    computingWaitingTime(input_data, n, m);
    computingTurnaroundTimes(input_data, n, m);
    computingCompletionTimes(input_data, n, m);
    print_statistics(input_data, n, m);
    
    double averageWaitingTime = 0;
    double averageTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        averageWaitingTime = averageWaitingTime + *(input_data + i * m + 4);
        averageTurnaroundTime = averageTurnaroundTime + *(input_data + i * m + 5);
    }
    averageWaitingTime = averageWaitingTime / n;
    averageTurnaroundTime = averageTurnaroundTime / n;

    indentLine(160);

    printf("\n%25s%100f%25f\n", "Average", averageWaitingTime, averageTurnaroundTime);

    return 0;
}
