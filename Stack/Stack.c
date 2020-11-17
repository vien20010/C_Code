/** 
 * 
 * November 17th, 2020
 * LV_Embedded
 * nguyenlamvien0110@gmail.com 
 * https://github.com/vien20010
 * 
 **/

#include "Stack.h"

int top = -1;

/**
 * 
 * @brief - Check Stack is Full or not
 * @param capacity - size of stack
 * @retval - true if stack is full and false if reserver
 * 
  */
bool IsFull(int capacity)
{
    if (top >= (capacity - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * 
 * @brief - Check Stack is Empty or not
 * @param None
 * @retval - true if stack is Empty and false if reserver
 * 
  */
bool IsEmpty()
{
    if (top <= -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/** 
 *
 * @brief - Push value in Stack have size capacity
 * @param Stack - pointer to Stack want to push
 * @param value - value want to push in Stack
 * @param capacity - size of stack
 * @retval None
 *   
 **/
void Push(int *Stack, int value, int capacity)
{
    if (IsFull(capacity) == true)
    {
        DBG("Stack is full now\n");
    }
    else
    {
        top++;
        *(Stack + top) = value;
    }
}
/**
 * 
 * @brief - Delete the top component in stack
 * @param Stack - pointer to Stack want to push
 * @param capacity - size of stack
 * @retval None
 *  
 **/
void Pop(int *Stack, int capacity)
{
    if (IsEmpty(capacity) == true)
    {
        DBG("Stack is empty now, don't have any value to pop\n");
    }
    else
    {
        top--;
    }
}
/**
 * 
 * @brief - Get the last value in Stack without delete it in stack
 * @param Stack - pointer to Stack want to push
 * @param value - pointer to value variable want to save
 * @param capacity - size of stack
 * @retval 
 *  
 **/
void Top(int *Stack, int *value, int capacity)
{
    if (IsEmpty(capacity) == true)
    {
        DBG("Stack is empty now, don't have any value to get\n");
    }
    else
    {
        *value = *(Stack + top);
    }
}

int Size(int *Stack)
{
    return top + 1;
}
