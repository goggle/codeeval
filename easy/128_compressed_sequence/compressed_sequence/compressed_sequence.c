/*
 * COMPRESSED SEQUENCE
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} Node;

Node *root = NULL;

Node* add_node(Node *last, int number);
void clean_list();
void print_list();
int read_line(FILE *f);
void perform_compression();

int main(int argc, char *argv[])
{
    FILE *file;
    int c;
    int r;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        while (1) {
            r = read_line(file);
            if (r == 4)
                break;
            if (r == 1) {
                //print_list();
                perform_compression();
                clean_list();
            }
        }
        fclose(file);
    }
    else {
        return 1;
    }

    return 0;
}

Node* add_node(Node *last, int number)
{
    Node *new;
    
    if (last == NULL) {
        root = malloc(sizeof(Node));
        if (root == NULL)
            return NULL;
        root->next = NULL;
        root->number = number;
        return root;
    }

    new = malloc(sizeof(Node));
    if (new == NULL) {
        return NULL;
    }
    last->next = new;
    new->number = number;
    new->next = NULL;
    return new;
}

void clean_list()
{
    Node *next;
    Node *current;

    current = root;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    root = NULL;
    return;
}

void print_list()
{
    Node *current;

    current = root;
    while (current != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }
    printf("\n");
}

int read_line(FILE *f)
{
    int c;
    int digit1;
    int digit2;
    int number;
    Node *current;

    number = 0;
    digit1 = digit2 = -1;
    root = NULL;
    current = NULL;
    while (1) {
        c = getc(f);
        if (c == EOF) {
            return 4; /* End of file */
        }
        if (c == ' ' || c == '\n') {
            if (digit2 == -1) {
                number = digit1 - 48;
            }
            else {
                number = 10 * (digit1 - 48) + (digit2 - 48);
            }
            current = add_node(current, number);
            digit1 = digit2 = -1;
            if (c == '\n')
                return 1;
        }
        if (c >= '0' && c <= '9') {
            if (digit1 == -1) {
                digit1 = c;
            }
            else {
                digit2 = c;
            }
        }
    }
    return 1;
}

void perform_compression()
{
    int count;
    Node *current;
    Node *previous;

    current = root;
    previous = NULL;
    count = 0;
    while (current != NULL) {
        if (previous == NULL) {
            count++;
            if (current->next == NULL) {
                printf("%d %d\n", count, current->number);
            }
            previous = current;
            current = current->next;
            continue;
        }
        if (previous->number == current->number) {
            count++;
        }
        else {
            printf("%d %d ", count, previous->number);
            count = 1;
        }
        
        if (current->next == NULL) {
            printf("%d %d\n", count, current->number);
        }

        previous = current;
        current = current->next;
    }
    return;
}
