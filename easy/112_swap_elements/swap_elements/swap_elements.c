/*
 * SWAP ELEMENTS
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file;
    int nlines;
    int c;
    char ch;
    int *nelem;
    int *nswap;
    int *elems;
    int *swaps;
    int i;
    int j;
    int number;
    int s0, s1;
    int tmp;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (!file)
        return 1;

    nlines = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n')
            nlines++;
    }
    rewind(file);

    nelem = malloc(nlines * sizeof(int));
    nswap = malloc(nlines * sizeof(int));
    if (nelem == NULL || nswap == NULL)
        return 1;
    for (i = 0; i < nlines; i++) {
        nelem[i] = nswap[i] = 0;
    }

    for (i = 0; i < nlines; i++) {
        while (fscanf(file, "%d ", &number) == 1) {
            nelem[i]++;
        }
        while ((c = fgetc(file)) != '\n' && c != EOF) {
            if (c == ' ') {
                fscanf(file, "%d-%d", &s0, &s1);
                nswap[i]++;
            }
        }
    }

    rewind(file);
    for (i = 0; i < nlines; i++) {
        elems = malloc(nelem[i] * sizeof(int));
        swaps = malloc(2 * nswap[i] * sizeof(int));
        if (elems == NULL || swaps == NULL)
            return 1;
        j = 0;
        while (fscanf(file, "%d ", &number) == 1) {
            elems[j] = number;
            j++;
        }
        j = 0;
        while ((c = fgetc(file)) != '\n' && c != EOF) {
            if (c == ' ') {
                fscanf(file, "%d-%d", &s0, &s1);
                swaps[2*j] = s0;
                swaps[2*j+1] = s1;
                j++;
            }
        }
        for (j = 0; j < nswap[i]; j++) {
            tmp = elems[swaps[2*j]];
            elems[swaps[2*j]] = elems[swaps[2*j+1]];
            elems[swaps[2*j+1]] = tmp;
        }
        for (j = 0; j < nelem[i]; j++) {
            if (j == nelem[i] - 1) {
                printf("%d\n", elems[j]);
            }
            else {
                printf("%d ", elems[j]);
            }
        }
        free(elems);
        free(swaps);
    }

    free(nelem);
    free(nswap);

    fclose(file);
    return 0;
}
