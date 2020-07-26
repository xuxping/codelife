
#include <stdio.h>
#include <stdlib.h>

// csdn、知乎、查询-》如何使用vscode执行C代码

// struct 结构体，将数据按照一定的方式组织起来
typedef struct Stack{
    int *data; // 指针表示，地址<-门牌号
    int maxSize;
    int top;
}Stack;

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
int push(Stack *stack, int value){
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
int pop(Stack *stack, int *value){
    if(stack->top == -1){
        return 0;
    }

    *value = stack->data[stack->top];
    --stack->top;
    return 1;
}


void display(Stack *stack){
    for(int i = stack->top; i > -1; --i){
        printf("%d->%d\n", i, stack->data[i]);
    }
}


int main(void){
    Stack *stack = initStack(5);
    push(stack, 2);
    push(stack, 5);

    display(stack);
    printf("\n");
    push(stack, 3);
    push(stack, 10);
    push(stack, 7);
    if(push(stack,3) == 0){
        printf("stack is full\n");
    }
    display(stack);


    int value;
    pop(stack, &value);
    printf("pop => %d\n", value);
    display(stack);
    pop(stack, &value);
    printf("pop => %d\n", value);
    pop(stack, &value);
    printf("pop => %d\n", value);
    pop(stack, &value);
    printf("pop => %d\n", value);

    pop(stack, &value);
    printf("pop => %d\n", value);
    display(stack);

    if(pop(stack, &value) == 0){
        printf("stack is empty!\n");
    }
    
    destoryStack(stack);

}





