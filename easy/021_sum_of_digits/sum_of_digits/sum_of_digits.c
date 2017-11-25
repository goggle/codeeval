/* 
 * SUM OF DIGITS
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *filecontent;
int *numbers;

void print_sum_of_digits(int number)
{
    int sum = 0;
    int digit;
    int digits;
    int i;
    int tmp;

    digits = number_of_digits(number);
    tmp = number;
    for (i = digits - 1; i >= 0; i--) {
        digit = tmp / (int)pow(10, i);
        tmp = tmp - digit * (int)pow(10, i);
        sum += digit;
    }
    printf("%d\n", sum);
}

int number_of_digits(int number)
{
    int digits = 1;
    while ((number = number / 10) != 0)
        digits++;
    return digits;
}

int main(int argc, char *argv[])
{
    int i;
    int number_of_characters = 0;
    int nelem = 0;
    if (argc == 1)
        return 0;
    number_of_characters = get_number_of_file_characters(argv[1]);
    if (get_file_content(argv[1], number_of_characters)) {
        nelem = get_numbers_from_filecontent(filecontent, number_of_characters);
        for (i = 0; i < nelem; i++)
            print_sum_of_digits(numbers[i]);
    }
    return 0;
}


int get_numbers_from_filecontent(int *content, int nchar)
{
    int i, j;
    int count_lines = 0;
    int *newline_pos;
    int number;
    int cur_pos, old_pos;
    int c;
    for (i = 0; i < nchar; i++){
        if (content[i] == 10)
            count_lines++;
    }
    numbers = malloc(count_lines * sizeof(int));
    newline_pos = malloc(count_lines * sizeof(int));
    j = 0;
    for (i = 0; i < nchar; i++) {
        if (content[i] == 10) {
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
            number += (content[j] - 48) * (int)pow(10, c);
            j--;
            c++;
        }
        old_pos = cur_pos;
        numbers[i] = number;
    }
    return count_lines;
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
