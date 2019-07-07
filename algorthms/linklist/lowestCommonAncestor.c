// 如何判断两个无环链表是否相交，如有求两个链表的第一个公共节点

/**
 * 1->2->3\
 *         > 4->5->6 
 * 1->2->3/
 */

#include <stdio.h>
#include "linklist.h"

/**
 * 思路：
 *  1、可以暴力搜索 T(n) = O(mn)
 *  2、借助栈，判断每次出栈的元素是否一致，找到最后一个一样的 T(n) = O(m+n)
 *  3、首先遍历两个链表得到他们的长度，就能知道哪个链表比较长，以及长的链表比短的链表多几个结点。
 *     在第二次遍历的时候，在较长的链表上先走若干步，接着同时在两个链表上遍历，找到的第一个相同
 *     的结点就是他们的第一个公共结点。
 */
struct LinkNode *lowestCommonAncestor(struct LinkNode *p, struct LinkNode *q){
    if (p == NULL || q == NULL){
        return NULL;
    }

    int lenOfp = 0;
    int lenOfq = 0;
    struct LinkNode *phead = p;
    struct LinkNode *qhead = q;
    
    // 遍历找到每个链表的长度
    while(phead != NULL){
        lenOfp++;
        phead = phead->next;
    }
    while(qhead != NULL){
        lenOfq++;
        qhead = qhead->next;
    }
    int step = lenOfp - lenOfq;
    if (step > 0){
        while(step>0){
            p = p->next;
            step--;
        }
    }else{
        step = -1 * step;
        while(step>0){
            q = q->next;
            step--;
        }
    }
    struct LinkNode *lowestCommonNode = NULL;
    // 找到第一个公共子节点
    while(p != NULL && q != NULL){
        if(p != q){
            p = p->next;
            q = q->next;
        }else{
            lowestCommonNode = p;
            break;
        }
    }

    return lowestCommonNode;
}


void testLowestCommonAncestor(){
    // 创建两个链表
    struct LinkNode *phead = randomCreate(5);
    printLinkList(phead);
    struct LinkNode *qhead = randomCreate(10);
    printLinkList(qhead);

    // 将第一个链表最后一个元素指向第二个链表中的某一个元素
    struct LinkNode *p = phead;
    while(p->next != NULL){
        p = p->next;
    }
    struct LinkNode *q = qhead;
    int i = 4;
    while(q->next != NULL && i > 0){
        q = q->next;
        i--;
    }
    p->next = q;

    
    struct LinkNode *lowestCommonNode = lowestCommonAncestor(phead, qhead);
    if (lowestCommonNode != NULL){
        printf("has cross in two linklist: %d\n", lowestCommonNode->val);
    }else{
        printf("no cross in two linklist\n");
    }
    printLinkList(qhead);
    
    // 解除链接并释放内存
    p->next = NULL;
    freeLinkList(phead);
    freeLinkList(qhead);
}

int main(void){
    testLowestCommonAncestor();
    return 0;
}