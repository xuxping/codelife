/**
 * 采用单链表实现LRU算法
 * 维护一个有序单链表，越靠近链表尾部的结点是越早之前访问的。
 * 当有一个新的数据被访问时，我们从链表头开始顺序遍历链表。
 * 1. 如果此数据之前已经被缓存在链表中了，我们遍历得到这个数据对应的结点，并将其从原来的位置删除，然后再插入到链表的头部。
 * 2. 如果此数据没有在缓存链表中，又可以分为两种情况：
 *  如果此时缓存未满，则将此结点直接插入到链表的头部；
 *  如果此时缓存已满，则链表尾结点删除，将新的数据结点插入链表的头部。
 **/
#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

int LRU(LinkList *head, LinkList *iNode, int cacheSize){
    if(iNode == NULL) return -1;

    // 1、链表为空
    if(head->next == NULL){
        head->next = iNode;
        iNode->next = NULL;
        return 1;
    }

    // 2、链表至少有一个节点
    int linkSize = 0;
    LinkList *p = head->next;
    LinkList *prev = head;
    //
    while (p->val != iNode->val)
    {
        linkSize++;
        p = p->next;
        prev = prev->next;
        if(p == NULL) break;
    }
    // 此数据之前已经被缓存在链表中了，我们遍历得到这个数据对应的结点，
    // 并将其从原来的位置删除，然后再插入到链表的头部。
    if (p != NULL){
        prev->next = p->next;
        p->next = head->next;
        head->next = p;
        return 2;
    }

    // 如果此数据没有在缓存链表中，又可以分为两种情况：
    // 1. 缓存未满，则将此结点直接插入到链表的头部；
    // 2. 缓存已满，则链表尾结点删除，将新的数据结点插入链表的头部。
    if (linkSize < cacheSize){
        iNode->next = head->next;
        head->next = iNode;
        return 3;
    }
    LinkList *pprev = head;
    while (pprev->next != prev)
    {
        pprev = pprev->next;
    }
    pprev->next = NULL;
    iNode->next = head->next;
    head->next = iNode;        
    return 3;
}


int main(int argc, char const *argv[])
{
    // 设置一个head节点方便后续操作
    LinkList *head = (LinkList *)malloc(sizeof(LinkList));
    head->next = randomCreate(10);
    printLinkList(head->next);
    LinkList *iNode = (LinkList *)malloc(sizeof(LinkList));
    iNode->next = NULL;
    iNode->val = 20;

    int rst = LRU(head, iNode, 10);
    printf("rst=>%d\n", rst);
    printLinkList(head->next);

    return 0;
}
