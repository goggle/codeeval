/* 
 * Fibonacci Series
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *filecontent;
int *fibonacci_index;

int main(int argc, char *argv[])
{
    int i, j;
    int number_of_characters = 0;
    int count_lines = 0;
    int *newline_pos;
    int number;
    int cur_pos, old_pos;
    int c;
    double phi = (1 + sqrt(5)) / 2.0;
    double theta = 1 - phi;
    double fib;
    long int fib_rounded;
    if (argc == 1)
        return 0;
    number_of_characters = get_number_of_file_characters(argv[1]);
    if (get_file_content(argv[1], number_of_characters)) {
        for (i = 0; i < number_of_characters; i++){
            if (filecontent[i] == 10)
                count_lines++;
        }
        fibonacci_index = malloc(count_lines * sizeof(int));
        newline_pos = malloc(count_lines * sizeof(int));
        j = 0;
        for (i = 0; i < number_of_characters; i++) {
            if (filecontent[i] == 10) {
                newline_pos[j] = i;
                j++;
            }
        }
        old_pos = -1;
        for (i = 0; i < count_lines; i++) {
            cur_pos = newline_pos[i];
            j = cur_pos - 1;
            c = 0;
            number = 0;
            while(j > old_pos) {
                number += (filecontent[j] - 48) * (int)pow(10, c);
                j--;
                c++;
            }
            old_pos = cur_pos;
            fibonacci_index[i] = number;
        }

        // Calculate and print the fibonacci numbers:
        for (i = 0; i < count_lines; i++) {
            fib = (pow(phi, fibonacci_index[i]) - pow(theta, fibonacci_index[i]))/sqrt(5);
            fib_rounded = llround(fib);
            printf("%d\n", fib_rounded);
        }
    }
    return 0;
}

int get_number_of_file_characters(const char *filename)
{
    int count = 0;
    int c;
    FILE *file;
    file = fopen(filename, "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            count++;
        fclose(file);
    }
    return count;
}

int get_file_content(const char *filename, int nchar)
{
    int i = 0;
    int c;
    FILE *file;
    filecontent = malloc(nchar * sizeof(int));
    file = fopen(filename, "r");
    if (file) {
        while ((c = getc(file)) != EOF) {
            filecontent[i] = c;
            i++;
        }
        fclose(file);
        return 1;
    }
    return 0;
}
