/*
 * MULTIPLICATION TABLES
 */

#include <stdio.h>

int main()
{
    int N = 12;
    int i, j;
    int result;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            result = i*j;
            printf("%4d", result);
        }
        printf("\n");
    }
}

