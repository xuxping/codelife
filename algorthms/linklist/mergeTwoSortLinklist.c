// 合并两个有序链表， 依次实现了下面三种方式
// 1、开辟新的内存
// 2、不使用新的内存进行合并
// 3、使用递归进行合并
// 刚开始实现的算法可能不够好，逐渐见的多了，思考多了，就有新的方法


#include <stdio.h>
#include "linklist.h"

/**
 * 开辟新的内存
 */ 
struct LinkNode *mergeTwoSortLinkList(struct LinkNode *head1, struct LinkNode *head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct LinkNode *p1 = head1;
    struct LinkNode *p2 = head2;
    struct LinkNode *newLink = NULL;
    struct LinkNode *p3 = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        struct LinkNode *node = (struct LinkNode *)malloc(sizeof(struct LinkNode));
        if (node == NULL)
        {
            return NULL;
        }

        if (p1->val < p2->val)
        {
            node->val = p1->val;
            p1 = p1->next;
        }
        else
        {
            node->val = p2->val;
            p2 = p2->next;
        }
        node->next = NULL;

        if (newLink == NULL)
        {
            newLink = node;
            p3 = newLink;
        }
        else
        {
            p3->next = node;
            p3 = p3->next;
        }
    }

    while (p1 != NULL)
    {
        struct LinkNode *node = (struct LinkNode *)malloc(sizeof(struct LinkNode));
        if (node == NULL)
        {
            return NULL;
        }
        node->val = p1->val;
        p1 = p1->next;

        p3->next = node;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        struct LinkNode *node = (struct LinkNode *)malloc(sizeof(struct LinkNode));
        if (node == NULL)
        {
            return NULL;
        }
        node->val = p2->val;
        p2 = p2->next;

        p3->next = node;
        p3 = p3->next;
    }
    return newLink;
}

/**
 * 不使用新的内存进行合并
 */ 
struct LinkNode *mergeTwoSortLinkListByLocal(struct LinkNode *l1, struct LinkNode *l2){
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct LinkNode *start = NULL;
    // 确定起始节点
    if (l1->val <= l2->val){
        start = l1;
        l1 = l1->next;
    }else{
        start = l2;
        l2 = l2->next;
    }

    struct LinkNode *p3 = start;

    while(l1 != NULL && l1 != NULL){
        if(l1->val <= l2->val){
            p3->next = l1;
            l1 = l1->next;
        }else{
            p3->next = l2;
            l2 = l2->next;
        }
        p3 = p3->next;
    }

    p3->next = l1 ? l1: l2;

    return start;
}

/**
 * 使用递归的方式进行合并
 */ 
struct LinkNode *mergeTwoSortLinkListByRecursive(struct LinkNode *head1, struct LinkNode *head2){
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct LinkNode *p = NULL;

    if(head1->val < head2->val){
        p = head1;
        p->next = mergeTwoSortLinkListByRecursive(head1->next, head2);
    }else{
        p = head2;
        p->next = mergeTwoSortLinkListByRecursive(head1, head2->next);
    }
    return p;
}


void testMergeTwoSortLinkList()
{
    // 创建两个链表
    int arr1[5] = {1, 3, 4, 6, 9};
    struct LinkNode *head1 = createLinkList(arr1, 5);
    printLinkList(head1);

    int arr2[10] = {2, 3, 4, 4, 6, 8, 9, 10, 30, 34};
    struct LinkNode *head2 = createLinkList(arr2, 10);
    printLinkList(head2);

    struct LinkNode *newLink = mergeTwoSortLinkList(head1, head2);
    printLinkList(newLink);

    freeLinkList(head1);
    freeLinkList(head2);
}

void testMergeTwoSortLinkListLocal()
{
    // 创建两个链表
    int arr1[5] = {1, 3, 4, 6, 9};
    struct LinkNode *head1 = createLinkList(arr1, 5);
    printLinkList(head1);

    int arr2[10] = {2, 3, 4, 4, 6, 8, 9, 10, 30, 34};
    struct LinkNode *head2 = createLinkList(arr2, 10);
    printLinkList(head2);

    // struct LinkNode *newLink = mergeTwoSortLinkListByLocal(head1, head2);
    struct LinkNode *newLink = mergeTwoSortLinkListByRecursive(head1, head2);

    printLinkList(newLink);

    freeLinkList(newLink);
}

int main(void)
{
    testMergeTwoSortLinkList();

    return 0;
}