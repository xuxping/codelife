// 反转一个链表

#include <stdio.h>
#include "linklist.h"

/**
 * 将一个单链表反转
 * 借助栈的操作（由于没有实现动态栈的操作，假定链表不会很长）
 */
struct LinkNode *reverse(struct LinkNode *head){
    if(head == NULL){
        return head;
    }

    struct LinkNode *p = head;
    // note: 分配的存放指针的数组
    const int SIZE = getSizeOfLinklist(p);
    struct LinkNode *stack[SIZE];
    int top = -1;
    // 进栈
    while(p != NULL){
        top++;
        stack[top] = p;
        p = p->next;
    }

    // 出栈
    struct LinkNode *nhead = stack[top];
    struct LinkNode *p1 = nhead;
    p1->next = NULL;
    top--;
    while(top >= 0){
        p1->next = stack[top];
        p1 = p1->next;
        p1->next = NULL;
        top--;
    }

    return nhead;
}

/**
 * 递归反转打印链表
 */
void printReverse(struct LinkNode *head){
    if (head != NULL){
        printReverse(head->next);
        printf("%d\t", head->val);
    }
}

void testReverse(){
    // 创建一个有环的链表
    struct LinkNode *head = randomCreate(20);
    printLinkList(head);
    // printf("reverse print\n");
    // printReverse(head);
    // printf("\n");
    // freeLinkList(head);

    struct LinkNode *nhead = reverse(head);
    printLinkList(nhead);

    freeLinkList(nhead);
}


int main(void){
    testReverse();
    return 0;
}