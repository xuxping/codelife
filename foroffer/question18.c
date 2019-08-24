// 删除链表的节点
// 给定单链表的头指针和一个节点指针，在O(1)时间内删除该链表节点

#include <stdio.h>
#include <stdlib.h>
#include "../algorthms/linklist/linklist.h"


/**
 * T(n) = ((n-1)*O(1) * O(n))/n = O(1)
 */
void deleteNode(struct  LinkNode **pHead, struct  LinkNode *pDeleteNode){
    if(pHead == NULL || pDeleteNode == NULL){
        return ;
    }

    struct LinkNode *p = *pHead;
    // 1、pDeleteNode不是尾节点
    if(pDeleteNode->next != NULL){
        struct LinkNode *pNext = pDeleteNode->next;
        pDeleteNode->val = pNext->val;
        pDeleteNode->next = pNext->next;
        free(pNext);
        pNext = NULL;
    }
    else if(*pHead == pDeleteNode){
        // 2、链表只有一个节点，且为头节点，尾节点
        free(pDeleteNode);
        pHead = NULL;
        pDeleteNode = NULL;
    }else{
        while(p->next != pDeleteNode){
            p = p->next;
        }
        p->next = NULL;
        free(pDeleteNode);
        pDeleteNode = NULL;
    }
}


/**
 * 删除值重复的节点
 * 由于头结点也有可能被删除，因此传入为pHead的指针的指针，这样可以直接修改头节点
 */ 
void delelteDuplication(struct LinkNode **pHead){
    if(pHead == NULL || *pHead == NULL){
        return ;
    }

    struct LinkNode *pPreNode = NULL;
    struct LinkNode *pNode = *pHead;

    while(pNode != NULL){
        struct LinkNode *pNext = pNode->next;
        int needDelete = 0;

        if(pNext != NULL && pNext->val == pNode->val){
            needDelete = 1;
        }
        // 不需要删除
        if(!needDelete){
            pPreNode = pNode;
            pNode = pNode->next;
        }else{
            // 循环删除值重复的节点
            int value = pNode->val;
            struct LinkNode *pToBeDel = pNode;
            while(pToBeDel != NULL && pToBeDel->val == value){
                pNext = pToBeDel->next;
                free(pToBeDel);
                pToBeDel = NULL;
                pToBeDel = pNext;
            }


            if(pPreNode == NULL){
                *pHead = pNext;
            }else{
                pPreNode->next = pNext;
            }
            pNode = pNext;
        }
    }

}

void test_deleteNode(){
    const int len = 10;
    struct LinkNode *pHead = randomCreate(len);
    struct  LinkNode *pDeleteNode = pHead;
    int i = len >> 1;
    while(i > 0){
        pDeleteNode = pDeleteNode->next;
        --i;
    }
    printLinkList(pHead);
    printf("pDeleteNode = %d", pDeleteNode->val);
    deleteNode(&pHead, pDeleteNode);
    printLinkList(pHead);
}


void test_delelteDuplication(){
    const int len = 10;
    int arr[len] = {1,1,2,3,4,4,5,5,7,9};
    struct LinkNode *pHead = createLinkList(arr, len);
    
    printLinkList(pHead);
    delelteDuplication(&pHead);
    printLinkList(pHead);
}

int main(void){
    // test_deleteNode();

    test_delelteDuplication();

    return 0;
}