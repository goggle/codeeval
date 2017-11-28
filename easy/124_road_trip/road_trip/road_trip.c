/*
 * ROAD TRIP
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* init_list(int value);
Node* add_node(Node *last, int value);
void clean_list(Node *root);
void print_list(Node *root);

Node* merge_sort(Node *list);

int main(int argc, char *argv[])
{
    FILE *file;
    int value;
    Node *root;
    Node *last;
    Node *current;
    int first;
    int c;

    int distance_from_start;

    int i;
    int previous_value;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        //eol = 0;
        first = 1;
        root = last = NULL;
        while ((c = getc(file)) != EOF) {
            if (c == ',') {
                fscanf(file, "%d", &value);
                //printf("%d\n", value);
                if (first) {
                    root = last = init_list(value);
                    first = 0;
                }
                else {
                    last = add_node(last, value);
                }
            }
            if (c == '\n') {
                root = merge_sort(root);
                if (root == NULL)
                    return 1;
                distance_from_start = root->value;
                printf("%d", distance_from_start);
                current = root->next;
                previous_value = distance_from_start;
                while(current != NULL) {
                    printf(",%d", current->value - previous_value);
                    previous_value = current->value;
                    current = current->next;
                }
                printf("\n");
                clean_list(root);
                root = last = NULL;
                first = 1;

            }
        }

        fclose(file);
    }
    else {
        return 1;
    }

    return 0;
}


Node* init_list(int value)
{
    Node *root = NULL;
    root = malloc(sizeof(Node));
    if (root == NULL) {
        return NULL;
    }
    root->value = value;
    root->next = NULL;
    return root;
}

Node* add_node(Node *last, int value)
{
    Node *new;
    new = malloc(sizeof(Node));
    if (new == NULL) {
        return last;
    }
    last->next = new;
    new->value = value;
    new->next = NULL;
    return new;
}

void clean_list(Node *root)
{
    Node *current;
    Node *next;

    current = root;
    next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    return;
}

void print_list(Node *root)
{
    Node *current;

    current = root;
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL)
            printf(" ");

        current = current->next;
    }
    printf("\n");
}

Node* merge_sort(Node *list)
{
    Node  *right;
    Node  *temp;
    Node  *last;
    Node  *next;
    Node  *result = NULL;
    Node  *tail = NULL;


    if (!list || !(list->next))
        return list;

    right = temp = last = list;
    while (temp && temp->next) {
        last = right;
        right = right->next;
        temp = temp->next->next;
    }

    last->next = NULL;

    list = merge_sort(list);
    right = merge_sort(right);

    while (list || right) {
        if (!right) {
            next = list;
            list = list->next;
        }
        else if (!list) {
            next = right;
            right = right->next;
        }
        else if (list->value < right->value) {
            next = list;
            list = list->next;
        }
        else {
            next = right;
            right = right->next;
        }
        if (!result) {
            result = next;
        }
        else {
            tail->next = next;
        }
        tail = next;
    }
    return result;
}
