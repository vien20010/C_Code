#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Debug.h"
#include "Bubble_Sort.h"

void swap(char *a, char *b);
unsigned int FindGreat(char *Number, char n);

int main()
{
    FILE *fptr_in, *fptr_out;
    char *X, n = 0;
    unsigned int num = 0;

    X = (char *)malloc(10 * sizeof(char));
    fptr_in = fopen("X.inp", "r");
    fscanf(fptr_in, "%u", &num);
    itoa(num, X, 10);
    n = strlen(X);
    DBG("%u\t%s\n", n, X);
    fclose(fptr_in);
    FindGreat(X, n);
    num = atoi(X);
    DBG("%u\n", num);
    fptr_out = fopen("X.out", "w");
    fprintf(fptr_out, "%u", num);
    fclose(fptr_out);

    return 0;
}

void swap(char *a, char *b)
{
    char temp = *a; 
    *a = *b;
    *b = temp;
}

unsigned int FindGreat(char *Number, char n)
{
    int i, j, smallest;

    for (i = n - 1; i > 0; i--)
    {
        if (*(Number + i) > *(Number + i - 1))
            break;
    }
    DBG("%d\n", i);
    if (i == 0)
        return 0;
    smallest = i;
    for (j = i + 1; j < n; j++)
    {
        if ((*(Number + j) > *(Number + i)) && (*(Number + j) < *(Number + smallest)))
            smallest = j;
    }
    DBG("%d\n", smallest);
    swap(Number + i - 1, Number + smallest);
    DBG("%s\n", Number);
    BubbleSort(Number, i, n);
    DBG("%s\n", Number);
    return 1;
}

