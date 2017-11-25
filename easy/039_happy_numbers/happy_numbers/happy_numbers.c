/*
 * HAPPY NUMBERS
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    long int value;
    struct Node *next;
} Node;


int count_digits(long int number);
long int square_sum_of_digits(long int number);
Node* add_node(Node *root, long int value);
void clean_list(Node *root);
int is_element(Node *root, long int element);

int main(int argc, char *argv[])
{
    FILE *file;
    long int number;
    long int ss;
    Node *root;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        while (fscanf(file, "%ld", &number) == 1)
        {
            root = NULL;
            while (1) {
                ss = square_sum_of_digits(number);
                number = ss;
                if (ss == 1) {
                    printf("1\n");
                    break;
                }
                else {
                    if (is_element(root, ss)) {
                        printf("0\n");
                        break;
                    }
                }
                root = add_node(root, ss);
            }
            clean_list(root);
        }

        fclose(file);
    }
    else {
        return 1;
    }

    return 0;
}

int count_digits(long int number)
{
    int ndigits = 0;
    long int div = number;
    while (div != 0) {
        div /= 10;
        ndigits++;
    }
    return ndigits;
}

long int square_sum_of_digits(long int number)
{
    int ndigits;
    int i;
    long int sum;
    long int *dig;
    long int tmp;

    ndigits = count_digits(number);
    dig = malloc(ndigits * sizeof(long int));
    if (dig == NULL)
        return 0;
    tmp = number;
    for (i = 0; i < ndigits; i++) {
        dig[i] = tmp % 10;
        tmp = (tmp - dig[i]) / 10;
    }

    sum = 0;
    for (i = 0; i < ndigits; i++) {
        sum += dig[i] * dig[i];
    }
    free(dig);
    return sum;
}

Node* add_node(Node *root, long int value)
{
    Node *new;

    if (root == NULL) {
        root = malloc(sizeof(Node));
        if (root == NULL)
            return NULL;
        root->value = value;
        root->next = NULL;
        return root;
    }

    new = malloc(sizeof(Node));
    if (new == NULL)
        return NULL;
    new->value = value;
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


int is_element(Node *root, long int element)
{
    Node *current;

    current = root;
    while (current != NULL) {
        if (current->value == element)
            return 1;
        current = current->next;
    }
    return 0;
}
