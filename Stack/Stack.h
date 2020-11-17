/** 
 * 
 * November 17th, 2020
 * LV_Embedded
 * nguyenlamvien0110@gmail.com 
 * https://github.com/vien20010
 * 
 **/

#ifndef _STACK_
#define _STACK_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "Debug.h"

extern int top;

bool IsFull(int capacity);
bool IsEmpty();
void Push(int *Stack, int value, int capacity);
void Pop(int *Stack, int capacity);
void Top(int *Stack, int *value, int capacity);
int Size(int *Stack);

#endif
