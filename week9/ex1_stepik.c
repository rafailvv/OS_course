#include <stdio.h>

struct memory_access {
    int t, a, b;
};
struct frame {
    int page, value, right_bit;
};

void initial_input(struct memory_access memory_accesses[], struct frame frames[], int n, int m) {
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &memory_accesses[i].t, &memory_accesses[i].a);
        memory_accesses[i].b = 0;
    }

    for (int i = 0; i < n; ++i) {
        frames[i].value = 0;
        frames[i].page = -1;
        frames[i].right_bit = 0;
    }
}

int position(struct frame frames[], int n, int a) {
    for (int i = 0; i < n; ++i) {
        if (frames[i].page == a) {
            return i;
        }
    }
    return -1;
}

float compute_ratio(struct memory_access memory_accesses[], int m) {
    int hit = 0;
    for (int i = 0; i < m; ++i) {
        if (memory_accesses[i].b == 1) {
            hit++;
        }
    }
    return (float) hit / (float) (m - hit);
}

void print_result(struct memory_access memory_accesses[], int m) {
    for (int i = 0; i < m; ++i) {
        printf("%d\n", memory_accesses[i].b);
    }
    printf("%f\n", compute_ratio(memory_accesses, m));
}

void ageing_algorithm(struct memory_access memory_accesses[], struct frame frames[], int n, int m) {
    int busy_frames = 0;
    for (int i = 0; i < m; ++i) {
        if (i != 0 && memory_accesses[i].t != memory_accesses[i - 1].t) {
            for (int j = 0; j < busy_frames; ++j) {
                frames[j].value = (frames[j].value >> 1) | (frames[j].right_bit << 7);
                frames[j].right_bit = 0;
            }
        }

        int current_position = position(frames, busy_frames, memory_accesses[i].a);
        if (current_position != -1) {
            memory_accesses[i].b = 1;
            frames[current_position].right_bit = 1;
        } else {
            busy_frames++;
            int id = busy_frames - 1;
            if (busy_frames > n) {
                struct frame min_frame;
                min_frame.value = frames[0].value;
                min_frame.page = frames[0].page;
                int min_id = 0;
                busy_frames--;
                for (int j = 1; j < busy_frames; ++j) {
                    if (min_frame.value == frames[j].value && min_frame.page > frames[j].page ||
                        min_frame.value > frames[j].value) {
                        min_id = j;
                        min_frame.value = frames[j].value;
                        min_frame.page = frames[j].page;
                    }
                }
                id = min_id;
            }
            frames[id].right_bit = 1;
            frames[id].value = 0;
            frames[id].page = memory_accesses[i].a;
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    struct memory_access memory_accesses[m];
    struct frame frames[n];
    initial_input(memory_accesses, frames, n, m);
    ageing_algorithm(memory_accesses, frames, n, m);
    print_result(memory_accesses, m);
    return 0;
}
