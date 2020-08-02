// 
// gcc -o stack stack_test.c stack.c
// 

#include "stack.h"
#include <stdio.h>


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





