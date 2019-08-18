// 两数相加
// https://leetcode-cn.com/problems/add-two-numbers

#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 采用两个指针分别指向两个链表的头结点，然后进行计算，
 * 用carry表示进位数
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p3 = l3;

    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    int carry = 0;

    while(p1! = NULL || p2! = NULL){
        int x = (p1 != NULL) ? p1->val :0;
        int y = (p2 != NULL) ? p2->val :0;
        int sum  = carry + x + y;
        // 进位
        carry = sum / 10;
        
        // create new now to store sum
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;
        l3->next = node;

        l3 = node;

        if(p1!=NULL){
            p1 = p1->next;
        }
        if(p2!=NULL){
            p2 = p2->next;
        }
    }

    if(carry > 0){
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        l3->next = node;
    }

    return p3->next;
}

