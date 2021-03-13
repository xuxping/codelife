/**
 * 单链表结构定义和方法
 */

// 定义一个链表节点
typedef struct LinkNode{
    int val;
    LinkList *next;
}LinkList;


/**
 * 释放单链表
 */
void freeLinkList(LinkList *head);

/**
 * 释放有环链表
 * len为链表的长度
 */
void freeCycleLinkList(LinkList *head, int len);

/**
 * 根据数组来创建链表
 */
LinkList *createLinkList(int *arr, int len);

/**
 * 打印单链表
 */
void printLinkList(LinkList *head);

/**
 * 随机初始化一个单链表
 */
LinkList *randomCreate(const int len);

/**
 * 获取无环链表的长度
 */
int getSizeOfLinklist(LinkList *head);

/**
 * TODO:单链表增删改查
 */