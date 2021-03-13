// 根据前序和中序重建二叉树

#include <stdio.h>
#include <stdlib.h>

#include "algorthms/tree/tree.h"


TreeNode *rebuildTree(int *preorder, int *inorder, int length){
    if(preorder == NULL || inorder == NULL || length <= 0){
        return NULL;
    }

    return rebuildCore(preorder, preorder +length - 1, inorder, inorder + length - 1);
}


TreeNode *rebuildCore(int *startPreorder, int *endPreorder,
                      int *startInorder, int *endInorder){

    // 第一个元素
    int rootValue = startPreorder[0];
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

    root->val = rootValue;
    root->left = root->right = NULL;

    if(startPreorder == endPreorder){
        if(startInorder == endInorder && *startPreorder == *startInorder){
            return root;
        }
        return NULL;
    }
    // 在中序遍历序列中找到根节点的值
    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
    {
        ++rootInorder;
    }
    // 没找到
    if(rootInorder == endInorder && *rootInorder != rootValue){
        return NULL;
    }

    int leftLength = rootInorder - startInorder;
    int leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0){
        // 构建左子树
        root->left = rebuildCore(startPreorder + 1, leftPreorderEnd, startPreorder, rootInorder-1);
    }

    if(leftLength < endPreorder - startPreorder){ // 说明还有右节点
        // 构建右子树
        root->right = rebuildCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
    }
    return root;

}