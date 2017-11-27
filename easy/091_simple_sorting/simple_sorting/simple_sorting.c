/*
 * SIMPLE SORTING
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float value;
    struct Node *next;
} Node;

Node* init_list(float value);
Node* add_node(Node *last, float value);
void clean_list(Node *root);
void print_list(Node *root);

Node* merge_sort(Node *list);


int main(int argc, char *argv[])
{
    FILE *file;
    float value;
    Node *root;
    Node *last;
    Node *current;
    int first;
    char c;
    //int eol;

    int i;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        //eol = 0;
        first = 1;
        root = last = NULL;
        while (fscanf(file, "%f%c", &value, &c) == 2) {
            if (first) {
                root = init_list(value);
                last = root;
                first = 0;
            }
            else {
                last = add_node(last, value);
            }
            if (c == '\n') {

                root = merge_sort(root);
                print_list(root);

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


Node* init_list(float value)
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

Node* add_node(Node *last, float value)
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
        printf("%.3f", current->value);
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
