// 最大栈
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int *data;
    int size;
    int top;
    int *maxData;
    int maxTop;
}Stack;

Stack *createStack(int size){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(sizeof(int) * size);
    stack->top = -1;
    stack->maxData = (int *)malloc(sizeof(int) * size);
    stack->maxTop = -1;
    stack->size = size;
    return stack;
}

int push(Stack *stack, int value){
    if(stack == NULL) return -1;

    if(stack->top + 1 == stack->size){
        return -2;
    }

    stack->top++;
    stack->data[stack->top] = value;
    
    // 当值大于栈顶元素
    if(value >= stack->maxData[stack->maxTop]){
        stack->maxData[++stack->maxTop] = value;
    }
    return 1;
}

int pop(Stack *stack, int *value){
    if(stack == NULL) return -1;
    if(stack->top < 0) return -2;

    *value = stack->data[stack->top--];

    if (stack->maxTop>=0 && *value == stack->maxData[stack->maxTop]){
        stack->maxTop--;
    }
    return 1;
}

int getMax(Stack *stack){
    if (stack->maxTop < 0) return -1;
    int maxValue = stack->maxData[stack->maxTop];
    printf("max => %d\n", maxValue);
    return maxValue;
}

int main(int argc, char const *argv[])
{
    Stack *stack = createStack(5);
    push(stack, 1);
    getMax(stack);
    push(stack, 4);
    getMax(stack);
    push(stack, 2);
    getMax(stack);
    push(stack, 3);
    getMax(stack);
    printf("pop======\n");
    int *value = (int *)malloc(sizeof(int));
    pop(stack,value);
    getMax(stack);
    pop(stack,value);
    getMax(stack);
    pop(stack,value);
    getMax(stack);
    pop(stack,value);
    getMax(stack);

    return 0;
}
