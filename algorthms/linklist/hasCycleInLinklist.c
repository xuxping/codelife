// 判断单链表上是否有环, 并记录环的大小
// 扩展问题（暂未实现）：
// 1、求链表的长度
// 2、求进入环的起始节点

#include <stdio.h>
#include "linklist.h"


/**
 * 可以使用两个指针，一个指针每次只走一步，一个指针每次走两步
 *
 * 之前在面试的时候没有做过这个题，提出了一种增加标志符的方式来判断，在
 * 遍历单链表的时候，记录被访问的时间，然后进行判断，如果已经被访问了，则肯定有环
 */
int hasCycleInLinkList(struct LinkNode *head){
    int flag = 0;
    // 为空或者只有1个节点
    if(head == NULL || head->next == NULL){
        return flag;
    }

    struct LinkNode *p1 = head;
    struct LinkNode *p2 = head;
    while(p1->next != NULL && p2->next->next != NULL){
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2){
            flag = 1;
            break;
        }
    }
    // 求出环的长度
    if (flag){
        int lenOfCycle = 1;
        struct LinkNode *p3 = p1->next;
        while(p3 != p1){
            lenOfCycle += 1;
            p3 = p3->next;
        }
        return lenOfCycle;
    }

    return flag;
}

/**
 * 创建有环的列表
 */
struct LinkNode *randomCreateCycle(const int len){
    struct LinkNode *head = randomCreate(len);

    struct LinkNode *p1 = head;
    struct LinkNode *p2 = head;
    // 到最后一个节点
    while(p1->next != NULL){
        p1 = p1->next;
    }
    for(int i = 0; i < (len / 2) + 1; ++i){
        p2 = p2->next;
    }
    p1->next = p2;
    return  head;
}


void testHasCycleInLinkList(){
    // 创建一个有环的链表
    struct LinkNode *head = randomCreateCycle(10);
    if(head == NULL){
        return 0;
    }
    
    int flag = hasCycleInLinkList(head);
    if (flag != 0){
        printf("cycle len == %d", flag);
    }else{
        printf("no cycle in linklist");
    }

    freeCycleLinkList(head, 10);
}


int main(void){
    testHasCycleInLinkList()
    return 0;
}