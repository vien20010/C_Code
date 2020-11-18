#include "Bubble_Sort.h"

void BubbleSort(char *str, char start, char stop)
{
    int i, j;
    for (i = start; i < stop - 1; i++)
    {
        for (j = i + 1; j < stop; j++)
        {
            if (*(str + i) > *(str + j))
            {
                swap(str + i, str + j);
            }
        }
    }
}