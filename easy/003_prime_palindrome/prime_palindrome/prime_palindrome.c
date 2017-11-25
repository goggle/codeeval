/*
 * PRIME PALINDROME
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIST_SIZE 1001

char PRIME_LIST[LIST_SIZE];

void generate_prime_list()
{
    int i, j, ind = 0;
    PRIME_LIST[0] = PRIME_LIST[1] = 0;
    for (i = 2; i < LIST_SIZE; i++)
        PRIME_LIST[i] = 1;
    for (i = 2; i < LIST_SIZE; i++) {
        if (2*i >= LIST_SIZE)
            break;
        j = 2;
        ind = i*j;
        while (ind < LIST_SIZE) {
            PRIME_LIST[ind] = 0;
            ind = (++j)*i;
        }
    }
    return;
}

int check_palindrome(unsigned int number)
{
    int digits = 0;
    unsigned int tmp;
    int *number_array;
    int i;
    int middle;
    
    // Count the number of digits:
    tmp = number;
    while (tmp > 0) {
        tmp /= 10;
        digits++;
    }
    
    if (digits == 0 || digits == 1)
        return 1;

    // Write the input number digit per digit into an array:
    number_array = malloc(digits * sizeof(int));
    tmp = number;
    for (i = 0; i < digits; i++) {
        number_array[i] = tmp / (int)(pow(10, digits - i - 1));
        tmp = tmp - number_array[i] * (int)pow(10, digits - i - 1);
    }

    // Check if number is a palindrome:
    middle = digits / 2;
    for (i = 0; i < middle; i++) {
        if (number_array[i] == number_array[digits - 1 - i])
            continue;
        return 0;
    }
    return 1;
}


int main()
{
    int i;
    int biggest_palindrome = 0;
    generate_prime_list();

    for (i = 2; i < LIST_SIZE; i++) {
        if (PRIME_LIST[i]) {
            if (check_palindrome(i)) {
                biggest_palindrome = i;
            }
        }
    }
    printf("%d\n", biggest_palindrome);

    return 0;
}
