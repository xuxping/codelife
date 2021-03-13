/**
 * 单链表结构定义和方法
 */

#include "linklist.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>


/**
 * 释放单链表
 */
void freeLinkList(LinkList *head){
    LinkList *p = NULL;
    printf("\nrelese memory:\n");

    while(head != NULL){
        p = head;
        printf("%d\t", p->val);
        head = head->next; // 下一个节点
        free(p);
    }
    printf("\n");
}

/**
 * 释放有环链表
 * len为链表的长度
 */
void freeCycleLinkList(LinkList *head, int len){
    LinkList *p = NULL;

    for(int i = 0; i < len; i++){
        p = head;
        head = head->next;
        free(p);
    }

    head = NULL;
}

/**
 * 根据数组来创建链表
 */
LinkList *createLinkList(int *arr, int len){
    printf("create link list\n");

    if (arr == NULL || len <= 0){
        return NULL;
    }
    LinkList *head = (LinkList *)malloc(sizeof(LinkList));
    if(head == NULL){
        printf("no memory to allocate!");
        exit(-1);
    }
    head->val = arr[0];
    head->next = NULL;
    LinkList *p = head;

    for(int i = 1; i < len; ++i){
        LinkList *node = (LinkList *)malloc(sizeof(LinkList));
        if(node == NULL){
            freeLinkList(head);
            printf("no memory to allocate!");
            exit(-1);
        }
        node->val = arr[i];
        node->next = NULL;
        p->next = node;
        p = p->next;
    }

    return head;
}

/**
 * 打印单链表
 */
void printLinkList(LinkList *head){
    printf("\nprint linklisk\n");
    LinkList *p = head;
    while(p != NULL){
        printf("%d\t", p->val);
        p = p->next;
    }
    printf("\n");

}

/**
 * 随机初始化一个单链表
 */
LinkList *randomCreate(const int len){
    int *arr = (int *)malloc(sizeof(int) * len);
    if (arr == NULL){
        printf("no memory to allocate!");
        exit(-1);
    }
    for(int i = 0; i < len; i++){
        arr[i] = rand_idx(0,10);
    }

    LinkList *head = createLinkList(arr, len);
    return  head;
}

/**
 * 获取链表的长度
 */
int getSizeOfLinklist(LinkList *head){
    LinkList *p = head;
    int size = 0;
    while(p!=NULL){
        size++;
        p = p->next;
    }
    printf("\nlinklisk size:%d\n", size);
    return size;
}

/**
 * TODO:单链表增删改查
 */