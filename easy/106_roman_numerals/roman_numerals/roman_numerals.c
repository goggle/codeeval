/* 
 * ROMAN NUMERALS
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *filecontent;
int *numbers;

void calculate_roman(int number)
{
    int i;
    int thousand;
    int hundred;
    int ten;
    int one;
    int tmp;
    if (number >= 4000)
        return;
    thousand = number / 1000;
    tmp = number - 1000 * thousand; 
    hundred = tmp / 100;
    tmp = tmp - 100 * hundred;
    ten = tmp / 10;
    tmp = tmp - 10 * ten;
    one = tmp;
    //printf("%d\n%d\n%d\n%d\n", thousand, hundred, ten, one);
    for (i = 0; i < thousand; i++)
        printf("M");

    if (hundred == 4 || hundred == 9) {
        if (hundred == 4)
            printf("CD");
        if (hundred ==  9)
            printf("CM");
    }
    else {
        if (hundred >= 5) {
            printf("D");
            hundred -= 5;
        }
        for (i = 0; i < hundred; i++) {
            printf("C");
        }
    }

    if (ten == 4 || ten == 9) {
        if (ten == 4)
            printf("XL");
        if (ten ==  9)
            printf("XC");
    }
    else {
        if (ten >= 5) {
            printf("L");
            ten -= 5;
        }
        for (i = 0; i < ten; i++) {
            printf("X");
        }
    }

    if (one == 4 || one == 9) {
        if (one == 4)
            printf("IV");
        if (one ==  9)
            printf("IX");
    }
    else {
        if (one >= 5) {
            printf("V");
            one -= 5;
        }
        for (i = 0; i < one ; i++) {
            printf("I");
        }
    }
    printf("\n");
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
            calculate_roman(numbers[i]);
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
