#ifndef TREE_H_
#define TREE_H_
// 树结构定义
#include <stdlib.h>

typedef struct TreeNode{
   int val;
   struct TreeNode *parent; // 根据情况使用
   struct TreeNode *left;
   struct TreeNode *right; 
}TreeNode;

// 树的创建
TreeNode *createTreeNode(char *str, int idx, int len);
TreeNode *createTree(char *str);
void destoryTree(TreeNode *root);

// 遍历
void preOrderWalkRecursion(TreeNode *root);
void preOrderWalk(TreeNode *root);

void inorderTreeWalkRecursion(TreeNode *root);
void inOrderWalk(TreeNode *root);

void lastOrderWalkRecursion(TreeNode *root);
void lastOrderWalk(TreeNode *root);

#endif  // TREE_H_