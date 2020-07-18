// 二叉搜索树的实现，参考《算法导论》第12章

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

typedef TreeNode BSTree;

/**
 * 非递归方法
 * 检索关键字
 * T(n) = O(logn)
 */
BSTree *TreeSearch(BSTree *root, int key)
{

    while (root != NULL && root->val != key)
    {
        if (key < root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return root;
}

/**
 * 递归方法
 * 检索关键字
 * T(n) = O(logn)
 */
BSTree *TreeSearchRecursion(BSTree *root, int key)
{
    BSTree *p = root;
    if (p == NULL || p->val == key)
    {
        return p;
    }

    // 在左子树中查找
    if (key < p->val)
    {
        return TreeSearch(p->left, key);
    }

    // 在右子树中查找
    return TreeSearch(p->right, key);
}


/**
 * 返回值最小的节点
 * T(n) = O(n)
 */
BSTree *TreeMinimum(BSTree *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

/**
 * 返回值最大的节点
 * T(n) = O(n)
 */
BSTree *TreeMaximum(BSTree *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

/**
 * 返回中序遍历时x的后继节点
 */
BSTree *TreeSuccessor(BSTree *x)
{
    // 如果结点x的右子树非空，则返回右子树的最左节点
    if (x->right != NULL)
    {
        // x = x->right;
        // while(x->left!=NULL){
        //     x = x->left;
        // }
        // return x;
        // 右子树的最左子节点
        return TreeMinimum(x->right);
    }

    BSTree *p = x->parent;

    
    // 2、如果x是p的右节点，则需要继续向上// 没有右子树的情况
    // 1、如果x是p的左节点，则p为中序遍历的后继节点查找，直到x是p的左节点为止
    while (p != NULL && x == p->right)
    {
        x = p;
        p = p->parent;
    }
    return p;
}

/**
 * 返回中序遍历的前继节点
 */
BSTree *TreePreSuccessor(BSTree *x)
{
    if (x->left != NULL)
    {
        // 左子树的最右子节点
        return TreeMaximum(x->left);
    }

    BSTree *p = x->parent;

    // 没有左子树的情况
    // 1、如果x是p的右节点，则p为中序遍历的前继节点
    // 2、如果x是p的左节点，则需要继续向上查收，直到x是p的右节点为止
    while (p != NULL && x == p->left)
    {
        x = p;
        p = p->parent;
    }
    return p;
}


/**
 * 将一个新值插入到树中
 * 考虑树为空的情况
 */
void TreeInsert(BSTree *root, BSTree *node)
{
    BSTree *p = root;
    BSTree *p1 = root;
    int key = node->val;
    // 找到要插入的点
    while (p != NULL)
    {
        p1 = p;
        if (key > p->val)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    node->parent = p1;

    // 树为空
    if (p1 == NULL)
    {
        root = node;
    }
    else if (key > p1->val)
    {
        p1->right = node;
    }
    else
    {
        p1->left = node;
    }
}