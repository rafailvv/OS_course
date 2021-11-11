#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 1000
#define MAX_RESOURCES_TYPE 1000

// The method for reading the input data from file with validation check
int read_input_data(FILE *input, char *name, int **e, int **a, int **c, int **r, int *n_p, int *n_r) {
    if ((input = fopen(name, "r")) == NULL) {
        return 1;
    }

    char temp_vec[MAX_PROCESS];
    char temp_matrix[MAX_RESOURCES_TYPE][MAX_PROCESS];

    while (fgets(temp_vec, MAX_PROCESS, input)[0] == '\n') {
        if (feof(input)) {
            return 2;
        }
    }

    for (int i = 0; i < MAX_PROCESS && temp_vec[i] != '\n'; i++) {
        if (temp_vec[i] >= '0' && temp_vec[i] <= '9') {
            ++*n_p;
        }
    }
    // Detecting and filling the E vector
    *e = (int *) malloc(*n_p * sizeof(int));
    for (int i = 0; i < *n_p; i++) {
        *(*e + i) = temp_vec[i * 2] - '0';
    }

    if (fgets(temp_vec, MAX_PROCESS, input)[0] != '\n') {
        return 2;
    }

    while (fgets(temp_vec, MAX_PROCESS, input)[0] == '\n') {
        if (feof(input)) {
            return 2;
        }
    }

    // Detecting and filling the A vector
    int n_p_temp = 0;
    for (int i = 0; i < MAX_PROCESS && temp_vec[i] != '\n'; i++) {
        if (temp_vec[i] >= '0' && temp_vec[i] <= '9') {
            n_p_temp++;
        }
    }

    if (*n_p != n_p_temp) {
        return 2;
    }

    *a = (int *) malloc(*n_p * sizeof(int));
    for (int i = 0; i < *n_p; i++) {
        *(*a + i) = temp_vec[i * 2] - '0';
    }

    if (fgets(temp_vec, MAX_PROCESS, input)[0] != '\n') {
        return 2;
    }

    while (fgets(temp_vec, MAX_PROCESS, input)[0] == '\n') {
        if (feof(input)) {
            return 2;
        }
    }

    // Detecting and filling the C matrix
    for (int i = 0; temp_vec[0] != '\n'; i++) {
        for (int j = 0; j < *n_p; j++) {
            temp_matrix[i][j] = temp_vec[j * 2];
        }
        if (temp_vec[(*n_p - 1) * 2 + 1] != '\n') {
            return 2;
        }
        ++*n_r;
        fgets(temp_vec, MAX_PROCESS, input);
    }

    *c = (int *) malloc(*n_p * *n_r * sizeof(int));
    for (int i = 0; i < *n_r; i++) {
        for (int j = 0; j < *n_p; j++) {
            *(*c + i * *n_p + j) = temp_matrix[i][j] - '0';
        }
    }

    while (fgets(temp_vec, MAX_PROCESS, input)[0] == '\n') {
        if (feof(input)) {
            break;
        }
    }

    int n_r_temp = 0;

    // Detecting and filling the R matrix
    for (int i = 0; temp_vec[0] != '\n'; i++) {
        for (int j = 0; j < *n_p; j++) {
            temp_matrix[i][j] = temp_vec[j * 2];
        }
        ++n_r_temp;
        if (temp_vec[(*n_p - 1) * 2 + 1] != '\n') {
            if (temp_vec[(*n_p - 1) * 2 + 1] == '\00' && *n_r == n_r_temp) {
                break;
            } else {
                return 2;
            }
        }

        fgets(temp_vec, MAX_PROCESS, input);
        if (feof(input)) {
            break;
        }
    }

    if (*n_r != n_r_temp) {
        return 2;
    }

    *r = (int *) malloc(*n_p * *n_r * sizeof(int));
    for (int i = 0; i < *n_r; i++) {
        for (int j = 0; j < *n_p; j++) {
            *(*r + i * *n_p + j) = temp_matrix[i][j] - '0';
        }
    }

    fclose(input);
    return 0;
}

// The function for checking the resource request of the process i
int check_request(int i, const int *a, const int *r, int n_p) {
    for (int j = 0; j < n_p; j++) {
        if (*(r + i * n_p + j) > *(a + j)) {
            return 0;
        }
    }
    return 1;
}

// The function that implements deadlock detection algorithm
int *algorithm(int *e, int *a, const int *c, int *r, int n_p, int n_r) {
    int *marked = (int *) calloc(n_r, sizeof(int));
    int num_of_actions = 1;
    for (int i = 1; num_of_actions != 0; i++) {
        num_of_actions = 0;
        printf("==================== Iteration %d ====================\n", i);
        for (int pi = 0; pi < n_r; pi++) {
            int is_request = check_request(pi, a, r, n_p);
            printf("Process i -> %d, marked -> %d, request -> %d\n", pi, *(marked + pi), is_request);
            if (is_request && !*(marked + pi)) {
                num_of_actions++;
                *(marked + pi) = 1;
                for (int j = 0; j < n_p; j++) {
                    *(a + j) += *(c + pi * n_p + j);
                }
            }
            printf("Available Vector => ");
            for (int j = 0; j < n_p; j++) {
                printf("%d ", *(a + j));
            }
            printf("\n");
        }
    }
    return marked;
}

// The function that print output information: ]
// no deadlock is detected or print out the numbers of processes that are deadlocked
void print_output_data(FILE *output, char *name, const int *marked, int n_r) {
    output = fopen(name, "w");
    int is_no_marked = 1;
    for (int i = 0; i < n_r; i++) {
        if (*(marked + i) == 0) {
            is_no_marked = 0;
            fprintf(output, "Process %d deadlocked\n", i);
        }
    }
    if (is_no_marked) {
        fprintf(output, "No deadlocked is detected");
    }
    fclose(output);
}


int main() {
    FILE *input, *output;
//    char name_input[] = "input_dl.txt";         // The files with a deadlock is commented out now
//    char name_output[] = "output_dl.txt";       // To work with it uncomment it and comment out the filenames to work without a deadlock
    char name_input[] = "input_ok.txt";           // The files without a deadlock is uncommented out now
    char name_output[] = "output_ok.txt";
    int num_processes = 0, num_resources_type = 0;
    int is_true;
    int *e, *a, *c, *r;
    is_true = read_input_data(input, name_input, &e, &a, &c, &r, &num_processes, &num_resources_type);
    if (is_true == 1) {
        printf("Could not open file");
        return 0;
    } else if (is_true == 2) {
        printf("Invalid input data");
        return 0;
    }
    int *marked = algorithm(e, a, c, r, num_processes, num_resources_type);
    print_output_data(output, name_output, marked, num_resources_type);

    return 0;
}
