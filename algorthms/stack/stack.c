
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


// 初始化栈
// 数组，0->size-1
// size 表示栈的大小，最多能存多少数据
Stack *initStack(int size){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(sizeof(int) * size);
    stack->maxSize = size;
    stack->top = -1;
    return stack;
}

// 销毁栈
void destoryStack(Stack *stack){
    if (stack == NULL) return;

    free(stack->data);
    stack->data = NULL;
    free(stack);
    stack = NULL;

}

// 判断栈为空
int StackEmpty(Stack *stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}

// 栈为空的时候，可以push
// 栈满的时候，不能push
int push(Stack *stack, ElemType value){
    if (stack->top + 1 == stack->maxSize){
        return 0; // 栈满
    }

    ++stack->top;
    stack->data[stack->top] = value;
    return 1;
}

// 出栈
// 栈为空，没有数据
// 栈满，返回数据
int pop(Stack *stack, ElemType *value){
    if(stack->top == -1){
        return 0;
    }

    *value = stack->data[stack->top];
    --stack->top;
    return 1;
}
