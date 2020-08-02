
#ifndef STACK_H
#define STACK_H

typedef int ElemType;

typedef struct Stack{
    int *data; // 指针表示，地址<-门牌号
    int maxSize;
    int top;
}Stack;


Stack *initStack(int size);
void destoryStack(Stack *stack);
int StackEmpty(Stack *stack);
int push(Stack *stack, ElemType value);
int pop(Stack *stack, ElemType *value);

#endif