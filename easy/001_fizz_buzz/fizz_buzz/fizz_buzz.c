/*
 * FIZZ BUZZ
 */

#include <stdio.h>


int main(int argc, char *argv[])
{
    FILE *file;
    int A, B, N;
    int i;

    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        while(fscanf(file, "%d %d %d", &A, &B, &N) == 3) {
            for (i = 1; i <= N; i++) {
                if ((i % A) == 0 || (i % B) == 0) {
                    if ((i % A) == 0)
                        printf("F");
                    if ((i % B) == 0)
                        printf("B");
                }
                else {
                    printf("%d", i);
                }
                if (i != N)
                    printf(" ");
            }
            printf("\n");
        }
        fclose(file);
    }
    else {
        return 1;
    }


    return 0;
}
