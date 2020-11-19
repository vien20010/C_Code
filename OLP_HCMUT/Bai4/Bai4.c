/* * 
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

int Factorial(int n);
void print_1Darray(char *arr, int n);
void print_2Darray(int **arr, int row, int column);
void swap(char *a, char *b);
void permute(char *a, int l, int r);
void mincost(char *a, int l, int r);

//Assume cost is internal
int cost = 999999;
int **graph;
char *Result;

int main()
{
    FILE *fptr_in, *fptr_out;
    int n = 0;
    char a[] = {0, 1, 2, 3};

    fptr_in = fopen("City.inp", "r");
    if (fptr_in == NULL)
    {
        DBG("Cannot open file\n");
        return 0;
    }
    fscanf(fptr_in, "%u", &n);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        *(graph + i) = (int *)malloc(n * sizeof(int));
    }
    int row = 0, column = 0;

    Result = (char *)malloc(n * sizeof(char));
    // All element of undirected graph in City.inp file
    for (int i = 0; i < Factorial(n) / (2 * Factorial(n - 2)); i++)
    {
        fscanf(fptr_in, "%u", &row);
        fscanf(fptr_in, "%u", &column);
        fscanf(fptr_in, "%u", (*(graph + row - 1) + column - 1));
        *(*(graph + column - 1) + row - 1) = *(*(graph + row - 1) + column - 1);
        //DBG("%u\t%u\n", *(*(graph + row - 1) + column - 1), *(*(graph + column - 1) + row - 1));
    }
    fclose(fptr_in);
    //print_array(graph, n);
    for (int i = 0; i < n; i++)
    {
        *(*(graph + i) + i) = 0;
    }

    DBG("Undirected Graph:\n");
    print_2Darray(graph, n, n);

    permute(a, 0, n - 1);
    DBG("Road: ");
    print_1Darray(Result, n);
    DBG("min cost = %d\n", cost);

    //print result to input

    fptr_out=fopen("City.out","w");
    if (fptr_out == NULL)
    {
        DBG("Cannot open file\n");
        return 0;
    }

    fprintf (fptr_out,"%d\n",cost);
    for (int i=0;i<n-1;i++)
    {
        fprintf(fptr_out,"%d %d\n",*(Result+i),*(Result+i+1));
    }
    fclose(fptr_out);
    return 0;
}

int Factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * Factorial(n - 1);
}

void print_1Darray(char *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

void print_2Darray(int **arr, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%u\t", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void swap(char *a, char *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 
 * @brief - calculate all permutation of string a begin from l to r
 * @param a - String want to permute
 * @param l - Starting index of the string
 * @param r - Ending index of the string
 * @retval - None
 * 
 */
void permute(char *a, int l, int r)
{
    int i;
    if (l == r)
    {
        //Code here
/*         DBG("permutation city:");
        for (int j = 0; j <= r; j++)
        {
            printf("%d\t", *(a + j));
        }
        printf("\n"); */
        /* printf("%s\n",a); */
        mincost(a, 0, r);
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i));
        }
    }
}

void mincost(char *a, int l, int r)
{
    int sum = 0;
    for (int i = l; i < r; i++)
    {
        //Calculate cost
        sum += *(*(graph + *(a + i % (r - l + 1))) + *(a + (i + 1) % (r - l + 1)));
    }
    //DBG("%d\n", sum);
    if (cost > sum)
    {
        cost = sum;
        for (int i = 0; i <= r; i++)
        {
            *(Result+i) = *(a + i)+1;
        }
    }
}