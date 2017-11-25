/*
 * SELF DESCRIBING NUMBERS
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int digit;
    int position;
    struct Node *next;
} Node;

Node* add_element(Node *root, int digit, int position);
void clean_list(Node *root);

Node* read_line(FILE *file);
int* count_occurences(Node *root);
int is_self_describing_number(Node *root);


int main(int argc, char *argv[])
{
    FILE *file;
    Node *root;
    int i;


    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        while (1) {
            root = NULL;
            root = read_line(file);
            if (root == NULL) {
                break;
            }
            printf("%d\n", is_self_describing_number(root));
            clean_list(root);

        }
        fclose(file);
    }
    else {
        return 1;
    }

    return 0;
}


Node* add_element(Node *root, int digit, int position)
{
    Node *new;

    if (root == NULL) {
        root = malloc(sizeof(Node));
        if (root == NULL) {
            return NULL;
        }
        root->digit = digit;
        root->position = position;
        root->next = NULL;
        return root;
    }

    new = malloc(sizeof(Node));
    if (new == NULL)
        return NULL;
    new->digit = digit;
    new->position = position;
    new->next = root;

    return new;
}

void clean_list(Node *root)
{
    Node *current;
    Node *next;

    current = root;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return;
}

Node* read_line(FILE *file)
{
    int i;
    int c;
    Node *root;

    root = NULL;
    i = 0;
    while (1) {
        c = getc(file);
        if (c == EOF) {
            return NULL;
        }
        if (c == '\n') {
            break;
        }
        if (c >= '0' && c <= '9') {
            root = add_element(root, c - 48, i);
            i++;
        }

    }
    return root;
}

int* count_occurences(Node *root)
{
    Node *current;
    int* occurences = NULL;
    int i;

    occurences = malloc(10 * sizeof(int));
    if (occurences == NULL) {
        return NULL;
    }
    for (i = 0; i < 10; i++) {
        occurences[i] = 0;
    }

    current = root;
    while (current != NULL) {
        occurences[current->digit]++;
        current = current->next;
    }
    return occurences;
}

int is_self_describing_number(Node *root)
{
    int self_describing;
    int *occurences;
    Node *current;

    occurences = count_occurences(root);
    self_describing = 1;
    current = root;

    while (current != NULL) {
        if (current->position > 9)
            return 0;
        if (current->digit != occurences[current->position] ) {
            self_describing = 0;
            break;
        }
        current = current->next;
    }

    free(occurences);

    return self_describing;
}
