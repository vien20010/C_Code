#include "Stack.h"

int main()
{
    int capacity = 3;
    int *Stack;
    int value=0;
    Stack = (int *)malloc(capacity * sizeof(int));
    
    Push(Stack, 5, capacity);
    DBG("current size of Stack: %d\n", Size(Stack));
    Push(Stack, 10, capacity);
    DBG("current size of Stack: %d\n", Size(Stack));
    Push(Stack, 9, capacity);
    Push(Stack, 24, capacity);
    DBG("Current size of stack is %d\n", Size(Stack));
    Top(Stack, &value, capacity);
    DBG("Top element of stack: %d\n",value);    
    return 0;
}
