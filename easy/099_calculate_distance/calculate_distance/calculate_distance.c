/* 
 * CALCULATE DISTANCE
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Pair {
    Point one;
    Point two;
} Pair;

Pair pair;
int line[25];

int calculate_distance(Pair *pair);
int read_line(FILE *f);
int parse_line();
int get_number(int ndigits, int digit1, int digit2, int minus);

int main(int argc, char *argv[])
{
    int dist;
    FILE *file;
    int c;
    int r;

    if (argc == 1)
        return 1;

    file = fopen(argv[1], "r");
    if (file) {
        while (1) {
            r = read_line(file);
            if (r == 4) {
                break;
            }
            if (r == 0) {
                goto abort;
            }
            r = parse_line();
            if (!r) {
                goto abort;
            }
            printf("%d\n", calculate_distance(&pair));

        }
    }
    else {
        return 1;
    }

    return 0;

abort:
    fclose(file);
    return 1;
}


int calculate_distance(Pair *pair)
{
    double dist;
    int diff1;
    int diff2;
    
    diff1 = pair->one.x - pair->two.x;
    diff2 = pair->one.y - pair->two.y;
    dist = sqrt(diff1 * diff1 + diff2 * diff2);
    return (int)dist;
}

int read_line(FILE *f)
{
    int c;
    int i;
    for (i = 0; i < 25; i++)
        line[i] = 100;

    i = 0;
    while ((c = getc(f)) != '\n') {
        if (c == EOF)
            return 4;
        if (i >= 25)
            return 0;
        line[i] = c;
        i++;
    }
    return 1;
}

int parse_line()
{
    int i = 0;
    int parantheses[4] = {-1, -1, -1, -1};
    int commas[2] = {-1, -1};
    int spaces[3] = {-1, -1, -1};
    int minus[4] = {-1, -1, -1, -1};
    int cpar = 0;
    int ccom = 0;
    int cspa = 0;
    int diff;
    int n1, n2, n3, n4;
    int d1, d2;

    /* Detect the parantheses, commas and whitespaces: */
    while (i < 25 && line[i] != -1) {
        if (line[i] == '(' || line[i] == ')') {
            if (cpar >= 4)
                return 0;
            parantheses[cpar] = i;
            cpar++;
        }
        else if (line[i] == ',') {
            if (ccom >= 2)
                return 0;
            commas[ccom] = i;
            ccom++;
        }
        else if (line[i] == ' ') {
            if (cspa >= 3)
                return 0;
            spaces[cspa] = i;
            cspa++;
        }
        i++;
    }

    /* Check if everything went well: */
    for (i = 0; i < 4; i++) {
        if (parantheses[i] < 0)
            return 0;
    }
    for (i = 0; i < 2; i++) {
        if (commas[i] < 0)
            return 0;
    }
    for (i = 0; i < 3; i++) {
        if (spaces[i] < 0)
            return 0;
    }

    /* Get the optional minus sign: */
    if (line[parantheses[0]+1] == '-')
        minus[0] = parantheses[0] + 1;
    if (line[spaces[0]+1] == '-')
        minus[1] = spaces[0] + 1;
    if (line[parantheses[2]+1] == '-')
        minus[2] = parantheses[2] + 1;
    if (line[spaces[2]+1] == '-')
        minus[3] = spaces[2] + 1;


    if (minus[0] != -1) {
        diff = commas[0] - minus[0] - 1;
        d1 = line[minus[0] + 1];
        d2 = line[minus[0] + 2];
    }
    else {
        diff = commas[0] - parantheses[0] - 1;
        d1 = line[parantheses[0] + 1];
        d2 = line[parantheses[0] + 2];
    }
    //printf("%d\n", diff);
    if (diff != 1 && diff != 2) {
        return 0;
    }
    n1 = get_number(diff, d1, d2, minus[0]);

    if (minus[1] != -1) {
        diff = parantheses[1] - minus[1] - 1;
        d1 = line[minus[1] + 1];
        d2 = line[minus[1] + 2];
    }
    else {
        diff = parantheses[1] - spaces[0] - 1;
        d1 = line[spaces[0] + 1];
        d2 = line[spaces[0] + 2];
    }
    //printf("%d\n", diff);
    if (diff != 1 && diff != 2) {
        return 0;
    }
    n2 = get_number(diff, d1, d2, minus[1]);

    if (minus[2] != -1) {
        diff = commas[1] - minus[2] - 1;
        d1 = line[minus[2] + 1];
        d2 = line[minus[2] + 2];
    }
    else {
        diff = commas[1] - parantheses[2] - 1;
        d1 = line[parantheses[2] + 1];
        d2 = line[parantheses[2] + 2];
    }
    //printf("%d\n", diff);
    if (diff != 1 && diff != 2) {
        return 0;
    }
    n3 = get_number(diff, d1, d2, minus[2]);

    if (minus[3] != -1) {
        diff = parantheses[3] - minus[3] - 1;
        d1 = line[minus[3] + 1];
        d2 = line[minus[3] + 2];
    }
    else {
        diff = parantheses[3] - spaces[2] - 1;
        d1 = line[spaces[2] + 1];
        d2 = line[spaces[2] + 2];
    }
    //printf("%d\n", diff);
    //printf("\n");
    if (diff != 1 && diff != 2) {
        return 0;
    }
    n4 = get_number(diff, d1, d2, minus[3]);

    //printf("(%d, %d) (%d, %d)\n", n1, n2, n3, n4);

    pair.one.x = n1;
    pair.one.y = n2;
    pair.two.x = n3;
    pair.two.y = n4;

    return 1;
}

int get_number(int ndigits, int digit1, int digit2, int minus)
{
    int number;
    if (ndigits == 1) {
        number = digit1 - 48;
        if (minus != -1)
            return -number;
        else
            return number;
    }
    else if (ndigits == 2) {
        number = (digit1 - 48) * 10 + (digit2 - 48);
        if (minus != -1)
            return -number;
        else
            return number;
    }
    return 0;
}
