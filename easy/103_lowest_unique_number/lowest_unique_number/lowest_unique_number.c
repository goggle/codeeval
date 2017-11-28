/*
 * LOWEST UNIQUE NUMBER
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int position;
    struct Node *next;
} Node;

Node* add_node(Node *root, int v, int p);
void clean_list(Node *root);
void print_list(Node *root);

int get_unique_position(Node *root);


int main(int argc, char *argv[])
{
    FILE *file;
    int val;
    int pos;
    char c;
    Node *root;
    int out;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        root = NULL;
        pos = 1;
        while (fscanf(file, "%d%c", &val, &c) == 2) {
            //printf("%d\n", val);
            root = add_node(root, val, pos);
            pos++;

            if (c == '\n') {
                out = get_unique_position(root);
                printf("%d\n", out);
                clean_list(root);
                root = NULL;
                pos = 1;
            }
            

        }

        fclose(file);
    }
    else {
        return 1;
    }

    return 0;
}


Node* add_node(Node *root, int v, int p)
{
    Node *new;

    if (root == NULL) {
        root = malloc(sizeof(Node));
        if (root == NULL)
            return NULL;
        root->value = v;
        root->position = p;
        root->next = NULL;
        return root;
    }

    new = malloc(sizeof(Node));
    if (new == NULL)
        return NULL;
    new->value = v;
    new->position = p;
    new->next = root;
    return new;
}

void clean_list(Node *root)
{
    Node *current;
    Node *temp;
    
    current = root;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    return;
}

void print_list(Node *root)
{
    Node *current;

    current = root;
    while (current != NULL) {
        printf("Position: %d Value: %d\n", current->position, current->value);
        current = current->next;
    }
    printf("\n");
}

int get_unique_position(Node *root)
{
    Node *current;
    int i;
    int unique;
    int appears;
    int pos;

    for (i = 1; i <= 9; i++) {
        appears = 0;
        unique = 0;
        current = root;
        while (current != NULL) {
            if (current->value == i) {
                appears = 1;
                unique++;
                pos = current->position;
            }
            current = current->next;
        }
        if (appears && unique == 1)
            return pos;
    }
    return 0;
}
