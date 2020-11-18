/** 
 * 
 * November 17th, 2020
 * LV_Embedded
 * nguyenlamvien0110@gmail.com 
 * https://github.com/vien20010
 * 
 **/
#include "Sort.h"

void swap(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void BubbleSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (*(array + i) > *(array + j))
            {
                swap(array + i, array + j);
            }
        }
    }
}

void SelectionSort(int *array, int size)
{
    int min_index = 0;
    for (int i = 0; i < size; i++)
    {
        min_index = i;
        for (int j = i; j < size; j++)
        {
            if (*(array + j) < *(array + min_index))
            {
                min_index = j;
            }
        }
        swap(array + min_index, array + i);
    }
}

void InsertionSort(int *array, int size)
{
    int last, j;
    for (int i = 1; i < size; i++)
    {
        last = *(array + i);
        j = i;
        while ((j > 0) && (*(array + j - 1) > last))
        {
            swap(array + j - 1, array + j);
            j--;
        }
    }
}

void MergeSort(int *array, int l, int r)
{
    if (l < r)
    {
        int m = (r - l) / 2;
        DBG("%d\n",m);
        MergeSort(array, l, m);
        MergeSort(array, m + 1, r);
        Merge(array, l, m, r);
    }
}

void Merge(int *array, int l, int m, int r)
{
    int *LeftArray;
    int *RightArray ;
    
    LeftArray = (int *)malloc((m - l + 1) * sizeof(int));
    RightArray = (int *)malloc((r - m) * sizeof(int));
    for (int i = 0; i < m - l + 1; i++)
    {
        *(LeftArray + i) = *(array + l + i);
    }
    for (int i = 0; i < r - m; i++)
    {
        *(RightArray + i) = *(array + m + 1 + i);
    }

    int LeftIndex = 0, RightIndex = 0, k = 0;
    while ((LeftIndex < (m - l + 1)) && (RightIndex < (r - m)))
    {
        if (*(LeftArray + LeftIndex) < *(RightArray + RightIndex))
        {
            *(array + k) = *(LeftArray + LeftIndex);
            LeftIndex++;
        }
        else
        {
            *(array + k) = *(RightArray + RightIndex);
            RightIndex++;
        }
        k++;
    }

    while (LeftIndex < (m - l + 1))
    {
        *(array + k) = *(LeftArray + LeftIndex);
        LeftIndex++;
        k++;
    }

    while (RightIndex < (r - m))
    {
        *(array + k) = *(RightArray + RightIndex);
        RightIndex++;
        k++;
    }
    
}
