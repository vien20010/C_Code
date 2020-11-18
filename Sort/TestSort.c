/** 
 * 
 * November 17th, 2020
 * LV_Embedded
 * nguyenlamvien0110@gmail.com 
 * https://github.com/vien20010
 * 
 **/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Sort.h"
#include "Debug.h"

int random_element_in_array(int a, int b)
{
    return a + rand() % (b - a + 1);
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    clock_t start, end;
    int n = 10;
    int *a = (int *)malloc(n * sizeof(int));

    /**
 * 0: Bubble Sort
 * 1: Selection Sort
 * 2: InSertion Sort
  */
    int FlagSort = 0;
    printf("Selection type of sort want to use:\n");
    printf("0: Bubble Sort\n1: Selection Sort\n2: Insertion Sort\n3: Merge Sort\n");
    scanf("%d", &FlagSort);
    for (int i = 0; i < n; i++)
    {
        *(a + i) = random_element_in_array(0, n);
    }

    print_array(a, n);
    switch (FlagSort)
    {
    case 0:
        start = clock();
        BubbleSort(a, n);
        end = clock();
        DBG("Time of Bubble Sort algorithm: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
        print_array(a, n);
        break;
    case 1:
        start = clock();
        SelectionSort(a, n);
        end = clock();
        DBG("Time of Selection Sort algorithm: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
        print_array(a, n);
        break;
    case 2:
        start = clock();
        InsertionSort(a, n);
        end = clock();
        DBG("Time of Insertion Sort algorithm: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
        print_array(a, n);
        break;
    case 3:
        start = clock();
        MergeSort(a, 0, n - 1);
        end = clock();
        DBG("Time of Merge Sort algorithm: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
        print_array(a, n);
        break;
    default:
        break;
    }

    return 0;
}