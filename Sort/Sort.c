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
    int m = 0;
    if (l < r)
    {
        m = (r + l) / 2;
        MergeSort(array, l, m);
        MergeSort(array, m + 1, r);
        Merge(array, l, m, r);
    }
    //DBG("%d %d %d\n",l,m,r);
}
/**
 * 
 * @brief - Merges two subarrays of arr[].
 First subarray is arr[l..m]
 Second subarray is arr[m+1..r]
 * @param array - pointer to array want to sort
 * @param l - starting index
 * @param r - Ending index
 * @return None
 * 
  **/
void Merge(int *array, int l, int m, int r)
{
    int i, j, k, LeftIndex, RightIndex;
    int *LeftArray;
    int *RightArray;
    int n1 = m - l + 1;
    int n2 = r - m;
    //DBG("In Merge Function\n");
    LeftArray = (int *)malloc(n1 * sizeof(int));
    RightArray = (int *)malloc(n2 * sizeof(int));
    //DBG("%d %d %d %d\n",l,m,r,n1);
    /* Copy data to temp arrays LeftArray and RightArray */
    for (i = 0; i < n1; i++)
    {
        *(LeftArray + i) = *(array + l + i);
    }
    for (i = 0; i < n2; i++)
    {
        *(RightArray + i) = *(array + m + 1 + i);
    }

    LeftIndex = 0;
    RightIndex = 0;
    k = l;
    /* Merge the temp arrays back into array[l..r]*/
    while ((LeftIndex < n1) && (RightIndex < n2))
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

    while (LeftIndex < n1)
    {
        *(array + k) = *(LeftArray + LeftIndex);
        LeftIndex++;
        k++;
    }

    while (RightIndex < n2)
    {
        *(array + k) = *(RightArray + RightIndex);
        RightIndex++;
        k++;
    }
    free(LeftArray);
    free(RightArray);
}
/** 
 * 
 * @brief - The main function that implements QuickSort 
 * @param array - pointer to array want to sort
 * @param l - starting index
 * @param r - Ending index
 * @return None
 * 
 **/
void QuickSort(int *array, int l, int r)
{
    int PivotIndex;
    if (l < r)
    {
        PivotIndex = Partition(array, l, r);
        QuickSort(array, l, PivotIndex - 1);
        QuickSort(array, PivotIndex + 1, r);
    }
}

/**
 * 
 * @brief This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot
 * @param array - pointer to array want to sort
 * @param l - Starting index
 * @param r - Ending index
 * @return - Pivot Index
 *   
 **/
int Partition(int *array, int l, int r)
{
    //Choose Pivot is the last element of array
    int Pivot = *(array + r);
    int i = l - 1, j = 0;
    for (j = l; j < r; j++)
    {
        if (*(array + j) < Pivot)
        {
            i++;
            swap(array + i, array + j);
        }
    }
    swap(array + i + 1, array + r);
    return i + 1;
}
