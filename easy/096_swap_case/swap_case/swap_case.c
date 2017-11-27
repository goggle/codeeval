/*
 * SWAP CASE
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;
    int c;

    if (argc == 1)
        return 0;
    file = fopen(argv[1], "r");
    if (file) {
        while ((c = getc(file)) != EOF) {
            if (c >= 'a' && c <= 'z') {
                c -= 32;
            }
            else if (c >= 'A' && c <= 'Z') {
                c += 32;
            }
            putchar(c);
        }

        fclose(file);
    }
    else {
        return 1;
    }

    return 0;
}
