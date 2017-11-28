/*
 * MORSE CODE
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    char letter;
} Node;

typedef struct Morse {
    char letter;
    const char *code;
} Morse;

Node *root;
Morse *morsetable[36];

int build_tree();
void free_tree();
int build_table();
int add_code(int index, char letter, const char *code);
void free_table();

int main(int argc, char *argv[])
{
    FILE *file;
    int c;
    int space;
    Node *current;
    if (argc == 1)
        return 1;

    build_table();
    build_tree();

    file = fopen(argv[1], "r");
    current = root;
    space = 0;
    if (file) {
        while ((c = getc(file)) != EOF) {
            if (c == '.') {
                if (current->left == NULL)
                    return 1;
                current = current->left;
                space = 0;
            }
            else if (c == '-') {
                if (current->right == NULL)
                    return 1;
                current = current->right;
                space = 0;
            }
            else if (c == ' ') {
                if (!space) {
                    printf("%c", current->letter);
                    space = 1;
                }
                else {
                    printf(" ");
                    space = 0;
                }
                current = root;
            }
            else if (c == '\n') {
                printf("%c", current->letter);
                printf("\n");
                space = 0;
                current = root;
            }
        }
    }
    else {
        return 1;
    }

    fclose(file);

    free_tree();
    free_table();
    return 0;
}

int build_tree()
{
    int i;
    int j;
    Node *current;
    Node *new;

    root = malloc(sizeof(Node));
    if (root == NULL)
        return 1;
    root->letter = '?';
    root->left = root->right = NULL;

    for (i = 0; i < 36; i++) {
        current = root;
        new = NULL;
        j = 0;
        while (morsetable[i]->code[j] != '\0') {
            if (morsetable[i]->code[j] == '.') { /* go to the left */
                if (current->left == NULL) {
                    new = malloc(sizeof(Node));
                    if (new == NULL)
                        return 0;
                    new->left = new->right = NULL;
                    new->letter = '?';
                    current->left = new;
                }
                current = current->left;
            }
            else { /* go to the right */
                if (current->right == NULL) {
                    new = malloc(sizeof(Node));
                    if (new == NULL)
                        return 0;
                    new->left = new->right = NULL;
                    new->letter = '?';
                    current->right = new;
                }
                current = current->right;
            }
            j++;
        }
        current->letter = morsetable[i]->letter;
    }


    return 0;
}

void free_tree()
{
    Node *current = root;
    Node *previous = NULL;
    int left = 0;
    while (1) {
        if (current->left != NULL) {
            left = 1;
            previous = current;
            current = current->left;
            continue;
        }
        if (current->right != NULL) {
            left = 0;
            previous = current;
            current = current->right;
            continue;
        }
        if (current->left == NULL && current->right == NULL) {
            if (current == root) {
                free(root);
                break;
            }
            if (left) {
                previous->left = NULL;
            }
            else {
                previous->right = NULL;
            }
            free(current);
            current = root;
            continue;
        }
    }
}

int build_table()
{
    add_code(0,  'A', ".-");
    add_code(1,  'B', "-...");
    add_code(2,  'C', "-.-.");
    add_code(3,  'D', "-..");
    add_code(4,  'E', ".");
    add_code(5,  'F', "..-.");
    add_code(6,  'G', "--.");
    add_code(7,  'H', "....");
    add_code(8,  'I', "..");
    add_code(9,  'J', ".---");
    add_code(10, 'K', "-.-");
    add_code(11, 'L', ".-..");
    add_code(12, 'M', "--");
    add_code(13, 'N', "-.");
    add_code(14, 'O', "---");
    add_code(15, 'P', ".--.");
    add_code(16, 'Q', "--.-");
    add_code(17, 'R', ".-.");
    add_code(18, 'S', "...");
    add_code(19, 'T', "-");
    add_code(20, 'U', "..-");
    add_code(21, 'V', "...-");
    add_code(22, 'W', ".--");
    add_code(23, 'X', "-..-");
    add_code(24, 'Y', "-.--");
    add_code(25, 'Z', "--..");
    add_code(26, '1', ".----");
    add_code(27, '2', "..---");
    add_code(28, '3', "...--");
    add_code(29, '4', "....-");
    add_code(30, '5', ".....");
    add_code(31, '6', "-....");
    add_code(32, '7', "--...");
    add_code(33, '8', "---..");
    add_code(34, '9', "----.");
    add_code(35, '0', "-----");

    return 0;
}

int add_code(int index, char letter, const char *code)
{
    morsetable[index] = malloc(sizeof(Morse));
    if (morsetable[index] == NULL)
        return 0;
    morsetable[index]->letter = letter;
    morsetable[index]->code = code;
    return 1;
}

void free_table()
{
    int i;
    for (i = 0; i < 36; i++) {
        free(morsetable[i]);
    }
}
