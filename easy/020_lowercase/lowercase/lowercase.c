/*
 * LOWERCASE
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int c;
    FILE *file;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        while ((c = getc(file)) != EOF) {
            if (c >= 65 && c <= 90)
                putchar(c + 32);
            else
                putchar(c);
        }
    }
    fclose(file);

    return 0;
}
