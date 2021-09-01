#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

struct Node {
    int data;
    struct Node *next;
};

void print_list(struct Node *n) {
    if (n == NULL) {
        puts("List is empty\n");
    } else {
        printf("The Linked List contains elements: ");
        while (n != NULL) {
            printf("%d ", n->data);
            n = n->next;
        }
        puts("\n");
    }
}

void insert_node(struct Node *head, int data_of_prev_node, int new_data) {
    struct Node *prev_node = head;
    if (prev_node == NULL) {
        printf("The element not exist\n");
    } else {
        while (prev_node != NULL && prev_node->data != data_of_prev_node) {
            prev_node = prev_node->next;
        }
        struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
        puts("Well done!\n");
    }
}

struct Node *delete_node(struct Node *head, int data_of_del_node) {
    struct Node *cur_node = head;
    struct Node *prev_node = NULL;
    while (cur_node != NULL && cur_node->data != data_of_del_node) {
        prev_node = cur_node;
        cur_node = cur_node->next;
    }
    if (cur_node == NULL) {
        printf("The element not exist\n");
    } else {
        if (cur_node != head) {
            prev_node->next = cur_node->next;
        } else {
            head = head->next;
        }
        puts("Well done!\n");
    }
    if (head == NULL) {
        puts("List is empty\n");
    }

    return head;
}

int main() {
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));

    head->data = 3;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;

    print_list(head);

    while (TRUE) {
        puts("If you want to insert node, print \"Insert\"");
        puts("If you want to delete node, print \"Delete\"");
        puts("If you want to print the linked list, enter \"Print\"");
        puts("If you to stop the program, print: \"None\"");
        char input[6];
        scanf("%s", input);
        if (strcmp(input, "Insert") == 0) {
            int prev_data;
            int new_data;
            puts("Enter the data of the element after which do you want to insert: ");
            scanf("%d", &prev_data);
            puts("Enter the data of the inserted element:");
            scanf("%d", &new_data);
            insert_node(head, prev_data, new_data);
        } else if (strcmp(input, "Delete") == 0) {
            int del_data;
            puts("Enter the data of the deleted element: ");
            scanf("%d", &del_data);
            head = delete_node(head, del_data);
        } else if (strcmp(input, "Print") == 0) {
            print_list(head);
        } else if (strcmp(input, "None") == 0) {
            break;
        } else {
            puts("Error, try again\n");
        }
    }
    return 0;
}


