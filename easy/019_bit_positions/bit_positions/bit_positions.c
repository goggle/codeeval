/*
 * BIT POSITIONS
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} Node;

typedef struct Triple {
    int number;
    int bit1;
    int bit2;
} Triple;


Node* add_element(Node *root, int number);
void clean_list(Node *root);
void print_list(Node *root);
Triple* read_line(FILE *file);
int sum_line(Node *root);
int get_bit(int number, int bit_position);

int main(int argc, char *argv[])
{
    FILE *file;
    int c;
    Triple *triple;
    int bit1, bit2;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        while (1) {
            triple = read_line(file);
            if (triple == NULL) {
                break;
            }
            bit1 = get_bit(triple->number, triple->bit1);
            bit2 = get_bit(triple->number, triple->bit2);
            if (bit1 == bit2) {
                printf("true\n");
            }
            else{
                printf("false\n");
            }

            free(triple);

        }
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

Triple* read_line(FILE *file)
{
    int c;
    Node *number_line = NULL;
    Node *bit_line1 = NULL;
    Node *bit_line2 = NULL;
    Triple *triple = NULL;
    int comma = 0;

    while((c = getc(file)) != '\n') {
        if (c == EOF) {
            return NULL;
        }
        if (c == ',') {
            comma++;
            continue;
        }
        if (c >= '0' && c <= '9') {
            if (comma == 0) {
                number_line = add_element(number_line, c - 48);
            }
            else if (comma == 1) {
                bit_line1 = add_element(bit_line1, c - 48);
            }
            else {
                bit_line2 = add_element(bit_line2, c - 48);
            }
        }
    }
    triple = malloc(sizeof(Triple));
    if (triple == NULL) {
        return NULL;
    }
    triple->number = sum_line(number_line);
    triple->bit1 = sum_line(bit_line1);
    triple->bit2 = sum_line(bit_line2);
    clean_list(number_line);
    clean_list(bit_line1);
    clean_list(bit_line2);

    return triple;

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

int get_bit(int number, int bit_position)
{
    int position = bit_position - 1;
    int bit;
    bit = (number & (1 << position)) >> position;
    return bit;
}
