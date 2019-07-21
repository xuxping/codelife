// 合并两个有序链表

#include <stdio.h>
#include "linklist.h"

struct LinkNode *mergeTwoSortLinkList(struct LinkNode *head1, struct LinkNode *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

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
    freeLinkList(newLink);
}

int main(void)
{
    testMergeTwoSortLinkList();

    return 0;
}