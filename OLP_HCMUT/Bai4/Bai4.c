/** 
 * 
 * November 17th, 2020
 * LV_Embedded
 * nguyenlamvien0110@gmail.com 
 * https://github.com/vien20010
 * 
 **/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Debug.h"

unsigned int Factorial(unsigned int n);
void print_array(unsigned int **arr, unsigned int n);

int main()
{
    FILE *fptr_in, *fptr_out;
    unsigned int n = 0;

    fptr_in = fopen("City.inp", "r");
    if (fptr_in == NULL)
    {
        DBG("Cannot open file\n");
        return 0;
    }
    fscanf(fptr_in, "%u", &n);
    unsigned int **graph;
    graph = (unsigned int **)malloc(n * sizeof(unsigned int *));
    for (int i = 0; i < n; i++)
    {
        *(graph + i) = (unsigned int *)malloc(n * sizeof(unsigned int));
    }
    unsigned int row = 0, column = 0;

    // All element of undirected graph in City.inp file
    for (int i = 0; i < Factorial(n) / (2 * Factorial(n - 2)); i++)
    {
        fscanf(fptr_in, "%u", &row);
        fscanf(fptr_in, "%u", &column);
        fscanf(fptr_in, "%u", (*(graph + row - 1) + column - 1));
        *(*(graph + column - 1) + row - 1) = *(*(graph + row - 1) + column - 1);
        //DBG("%u\t%u\n", *(*(graph + row - 1) + column - 1), *(*(graph + column - 1) + row - 1));
    }
    //print_array(graph, n);
    for (int i = 0; i < n; i++)
    {
        *(*(graph + i) + i) = 0;
    }
    /*     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%u\t", *(*(graph + i) + j));
        }
        printf("\n");
    } */
    DBG("Undirected Graph:\n");
    print_array(graph, n);

    return 0;
}

unsigned int Factorial(unsigned int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * Factorial(n - 1);
}

void print_array(unsigned int **arr, unsigned int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%u\t", *(*(arr + i) + j));
        }
        printf("\n");
    }
}