/*
 * QUERY BOARD
 */
#include <stdio.h>

const int N = 256;
int board[256][256];

int main(int argc, char *argv[])
{
    FILE *file;
    int i, j, x;
    int c;
    int set_query = 0;
    int row;
    int sum;
    if (argc == 1)
        return 0;

    file = fopen(argv[1], "r");
    if (file) {
        while (1) {
            c = getc(file);
            if (c == EOF)
                break;
            if (c == 'S') {
                set_query = 1;
                c = getc(file);
                c = getc(file);
                c = getc(file);
                if (c == 'R') {
                    row = 1;
                    c = getc(file);
                    c = getc(file);
                    c = getc(file);
                }
                else if (c == 'C') {
                    row = 0;
                    c = getc(file);
                    c = getc(file);
                    c = getc(file);
                }
                fscanf(file, "%d %d\n", &i, &x);

            }
            else if (c == 'Q') {
                set_query = 2;
                c = getc(file);
                c = getc(file);
                c = getc(file);
                c = getc(file);
                c = getc(file);
                if (c == 'R') {
                    row = 1;
                    c = getc(file);
                    c = getc(file);
                    c = getc(file);
                }
                else if (c == 'C') {
                    row = 0;
                    c = getc(file);
                    c = getc(file);
                    c = getc(file);
                }
                fscanf(file, "%d\n", &i);
            }
            
            if (set_query == 1 && row) {
                for (j = 0; j < N; j++) {
                    board[i][j] = x;
                }
            }
            else if (set_query == 1 && !row) {
                for (j = 0; j < N; j++) {
                    board[j][i] = x;
                }
            }
            else if (set_query == 2 && row) {
                sum = 0;
                for (j = 0; j < N; j++) {
                    sum += board[i][j];
                }
                printf("%d\n", sum);
            }
            else if (set_query == 2 && !row) {
                sum = 0;
                for (j = 0; j < N; j++) {
                    sum += board[j][i];
                }
                printf("%d\n", sum);
            }
                

        }

        fclose(file);
    }
    else {
        return 1;
    }

    return 0;
}
