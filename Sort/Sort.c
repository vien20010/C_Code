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
                min_index=j;
            }
        }
        swap(array+min_index, array+i);
    }
}