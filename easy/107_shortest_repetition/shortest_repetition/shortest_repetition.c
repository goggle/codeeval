/*
 * SHORTEST REPETITION
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *file;
    char line[100];
    int i;
    int length;
    int p;
    int found;
    int period;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (!file)
        return 1;
    while (!feof(file)) {
        for (i = 0; i < 100; i++) {
            line[i] = 0;
        }
        if (fgets(line, 100, file)) {
            length = 0;
            while (line[length] != '\n' && line[length] != '\0') {
                length++;
            }
            found = 0;
            period = length;
            for (p = 1; p < length/2 + 1; p++) {
                if (found) {
                    break;
                }
                for (i = 0; i < length; i++) {
                    if (line[i] != line[i % p]) {
                        break;
                    }
                    if (i == length-1) {
                        period = p;
                        found = 1;
                    }
                }

            }
            printf("%d\n", period);
        }
    }
    fclose(file);

    return 0;
}
