/*
 * HIDDEN DIGITS
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
        return 0;

    FILE *file;
    int c;
    int found;

    file = fopen(argv[1], "r");

    if (file) {
        found = 0;
        while ((c = getc(file)) != EOF) {
            if (c == '\n') {
                if (!found)
                    printf("NONE");
                printf("\n");
                found = 0;

            }
            if (c >= 'a' && c <= 'j') {
                printf("%d", c - 97);
                found = 1;
            }
            if (c >= '0' && c <= '9') {
                printf("%d", c - 48);
                found = 1;
            }

        }
        fclose(file);
    }
    else {
        return 1;
    }

    return 0;
}
