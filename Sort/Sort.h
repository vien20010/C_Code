/** 
 * 
 * November 17th, 2020
 * LV_Embedded
 * nguyenlamvien0110@gmail.com 
 * https://github.com/vien20010
 * 
 **/
#ifndef _SORT_
#define _SORT_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Debug.h"

extern void print_array(int *arr, int n);
void swap(int *num1, int *num2);
void BubbleSort(int *array, int size);
void SelectionSort(int *array, int size);
void InsertionSort(int *array, int size);
void MergeSort(int *array, int l, int r);
void Merge(int *array, int l, int m, int r);

#endif