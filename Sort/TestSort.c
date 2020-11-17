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

    for (int i=0; i<n;i++)
    {
        *(a+i)=random_element_in_array(0, n);
    }

    print_array(a, n);
    start = clock();
    BubbleSort(a, n);
    end = clock();
    DBG("Time of algorithm: %f\n",(double)(end - start)/CLOCKS_PER_SEC);
    print_array(a, n);
    return 0;
}