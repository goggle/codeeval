/*
 * SUM OF PRIMES
 */

#include <stdio.h>

#define N 1000
#define LIST_SIZE 10000

int PRIME_LIST[LIST_SIZE];

int main() {
    int i, j = 0;
    int ind = 0;
    unsigned int count = 0;
    unsigned int sum = 0;

    /* Generate the prime list: */
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

    /* Calculate the sum of primes: */
    for (i = 0; i < LIST_SIZE; i++) {
        if (count >= N)
            break;
        if (PRIME_LIST[i] == 1) {
            count++;
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}
