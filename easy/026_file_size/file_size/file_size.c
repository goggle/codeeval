#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;
    unsigned long size;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (!file)
        return 1;

    fseek(file, 0, SEEK_END);
    size = (unsigned long)ftell(file);
    fclose(file);

    printf("%lu\n", size);



    return 0;
}
