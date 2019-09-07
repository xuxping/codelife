/**
 * 树的创建，销毁和遍历
 */ 

#include <stdio.h>
#include <stdlib.h>

#include "string.h"
#include "tree.h"

TreeNode *createTreeNode(char *str, int idx, int len, TreeNode *pParent){
    TreeNode *pRoot = NULL;
    if(idx < len && str[idx] != '#'){
        pRoot = (TreeNode *)malloc(sizeof(TreeNode));
        pRoot->val = str[idx] - '0';
        pRoot->parent = pParent;
        pRoot->left = createTreeNode(str, 2 * idx + 1, len, pRoot);
        pRoot->right = createTreeNode(str, 2 * idx + 2, len, pRoot);
    }
    return pRoot;
}


/**
 * 输入的字符串中应该不含有重复的字符，除了特殊符号#
 * input: 148#456##7
 *           1
 *       4      8
 *     #   4  5   6
 *   #  # 7
 */ 
TreeNode *createTree(char *str){
    if (str == NULL || *str == '\0'){
        return NULL;
    }
    TreeNode *pRoot = createTreeNode(str, 0, strlen(str), NULL);
    return pRoot;
}


void destoryTree(TreeNode *pRoot){
    if (pRoot == NULL) return;
    if(pRoot->left){
        destoryTree(pRoot->left);
    }
    if(pRoot->right){
        destoryTree(pRoot->right);
    }
    // printf("\nfree %d", pRoot->val);
    free(pRoot);
    pRoot = NULL;
}


void preOrderWalkRecursion(TreeNode *root){
    if (root != NULL)
    {
        printf("%d,", root->val);
        preOrderWalkRecursion(root->left);
        preOrderWalkRecursion(root->right);
    }
}


void preOrderWalk(TreeNode *root){
    if (root == NULL) return;
    TreeNode *stack[100];
    TreeNode *p = root;
    int top = -1;
    stack[++top] = root;
    while(top >= 0){
       p = stack[top--];
       printf("%d,", p->val);
       if(p->right){
           stack[++top] = p->right;
       }

       if(p->left){
           stack[++top] = p->left;
       }
    }
}


/**
 * 递归算法
 * 中序遍历，结果为有序数组
 * T(n) = O(n)
 */
void inorderTreeWalkRecursion(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTreeWalkRecursion(root->left);
        printf("%d,", root->val);
        inorderTreeWalkRecursion(root->right);
    }
}


/**
 * 非递归中序遍历
 */
void inOrderWalk(TreeNode *root){
    if(root == NULL) return;
    TreeNode *stack[100];
    TreeNode *p = root;
    int top = -1;

    while(top >= 0 || p != NULL){
        // 将左子树全部入栈
        while (p != NULL){
            top++;
            stack[top] = p;
            p = p->left;
        }

        // 出栈
        if(top >= 0){
            p = stack[top--];
            printf("%d,", p->val);
            // 遍历右子树
            p = p->right;
        }
    }
}



void lastOrderWalkRecursion(TreeNode *root){
    if (root != NULL)
    {
        lastOrderWalkRecursion(root->left);
        lastOrderWalkRecursion(root->right);
        printf("%d,", root->val);
    }
}


/**
 * 非递归后续序遍历
 */
void lastOrderWalk(TreeNode *root){
    if(root == NULL) return;
    TreeNode *stack[100];
    TreeNode *p = root;
    int top = -1;
    int loop = 1;

    stack[++top] = root;

    while(top >= 0){
        /** 入栈时，先将右子树（若存在）入栈再将左子树（若存在）入栈，
        * 然后指向左孩子（若存在左孩子，否则指向右孩子）。
        * 在对这个部分结点构成的栈进行出栈操作时，应该注意到两个特点。
        * 第一、叶结点，他是左右子树均为空，而跳出循环时，从栈顶推出。
        * 第二、任一结点出栈后，考察他和栈顶结点的关系，若是双亲关系，
        * 则说明下一个结点在该结点访问完后也可以访问，直接出栈即可。
        * 若不是双亲关系，则下一个结点应进入本段开头所说的循环将有关结点持续入栈
        * */
        while(p && loop){
            if(p->right){
                stack[++top] = p->right;
            }
            if(p->left){
                stack[++top] = p->left;
            }

            if(p->left){
                p = p->left;
            }else{
                p = p->right;
            }
        }
        
        p = stack[top--];
        printf("%d,", p->val);
        if(top <= -1) break;

        // 是否是双亲，如果是则可以继续出栈，否则需要将其他元素进栈
        if(p == stack[top]->left || p == stack[top]->right){
            loop = 0;
        }else{
            loop = 1;
        }
        p = stack[top];
    }
}

/**
 * 假设val值唯一
 */ 
TreeNode *getNodeByVal(TreeNode *root, int val){
    TreeNode *p = root;

    if (p != NULL)
    {
        if(root->val == val){
            return p;
        }
        p = getNodeByVal(p->left, val);
        if (p == NULL || p->val != val){
            p = getNodeByVal(root->right, val);
        }
    }
    return p;
}


