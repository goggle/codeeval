/*
 * SUM OF INTEGERS FROM FILE
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} Node;


Node* add_element(Node *root, int number);
void clean_list(Node *root);
void print_list(Node *root);
Node* read_line(FILE *file);
int sum_line(Node *root);
long int calculate_sum(Node *root);

int main(int argc, char *argv[])
{
    FILE *file;
    int c;
    int line_sum;
    Node* line_list;
    Node *number_list;
    long int sum;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        number_list = NULL;
        while (1) {
            line_list = NULL;
            line_list = read_line(file);
            if (line_list == NULL) {
                break;
            }
            //print_list(line_list);
            line_sum = sum_line(line_list);
            clean_list(line_list);

            number_list = add_element(number_list, line_sum);
        }
        sum = calculate_sum(number_list);
        printf("%ld\n", sum);
        clean_list(number_list);
        fclose(file);
    }

    else {
        return 1;
    }

    return 0;
}

Node* add_element(Node *root, int number)
{
    Node *new;
    
    if (root == NULL) {
        root = malloc(sizeof(Node));
        if (root == NULL) {
            return NULL;
        }
        root->next = NULL;
        root->number = number;
        return root;
    }
    
    new = malloc(sizeof(Node));
    if (new == NULL) {
        clean_list(root);
        return NULL;
    }
    new->number = number;
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

void print_list(Node *root)
{
    Node *current;

    current = root;
    while (current != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }
    printf("\n");
    return;
}

Node *read_line(FILE *file)
{
    int c;
    Node *line = NULL;
    while((c = getc(file)) != '\n') {
        if (c == EOF) {
            return NULL;
        }
        if (c >= '0' && c <= '9') {
            line = add_element(line, c - 48);
        }
    }
    return line;

}

int sum_line(Node *root)
{
    int sum;
    int factor;
    Node *current;

    sum = 0;
    factor = 1;
    current = root;
    while (current != NULL) {
        sum += factor * current->number;
        factor *= 10;
        current = current->next;
    }
    return sum;
}

long int calculate_sum(Node *root) {
    long int sum;
    Node *current;

    sum = 0;
    current = root;
    while (current != NULL) {
        sum += current->number;
        current = current->next;
    }
    return sum;
}
