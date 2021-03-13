// 反转一个链表

#include <stdio.h>
#include "linklist.h"

/**
 * 将一个单链表反转
 * 借助栈的操作（由于没有实现动态栈的操作，假定链表不会很长）
 */
LinkList *reverseByStack(LinkList *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    LinkList *p = head;
    // note: 分配的存放指针的数组
    const int SIZE = getSizeOfLinklist(p);
    LinkList *stack[SIZE];
    int top = -1;
    // 进栈
    while(p != NULL){
        top++;
        stack[top] = p;
        p = p->next;
    }

    // 出栈
    LinkList *nhead = stack[top];
    LinkList *p1 = nhead;
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
 * 使用指针进行反转
 */
LinkList *reverseByPointer(LinkList *head){
    // 空指针或者只有一个结点
    if(head == NULL || head->next == NULL){
        return head;
    }

    LinkList *p1 = head;
    LinkList *p2 = head->next;
    LinkList *tmp = NULL; // 记录断链后面的起始节点
    
    p1->next = NULL;
    while(p2 != NULL){
        tmp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = tmp;
    }
    return p1;
}

/**
 * 递归反转打印链表
 */
void printReverse(LinkList *head){
    if (head != NULL){
        printReverse(head->next);
        printf("%d\t", head->val);
    }
}

/**
 * 测试用例:
 * 1、空链表、只有一个节点的链表，只有两个节点的链表
 * 2、大于两个节点的链表
 */ 
void testReverse(){
    // 创建一个有环的链表
    LinkList *head = randomCreate(10);
    printLinkList(head);
    // printf("reverse print\n");
    // printReverse(head);
    // printf("\n");
    // freeLinkList(head);

    // LinkList *nhead = reverseByPointer(head);
    LinkList *nhead = reverseByStack(head);
    printLinkList(nhead);

    freeLinkList(nhead);
}


int main(void){
    testReverse();
    return 0;
}