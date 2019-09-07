// 最近公共父节点
/**
1）如果是二叉搜索树：
    遍历找到比第一个节点大，比第二个节点小的节点即可
2）如果是父子间有双向指针的树：
    由下往上看，转化为找两个链表的第一个公共节点问题
3）如果只是一个包含父到子的指针的普通树：
   3.1）如果不能使用额外空间，从根节点开始判断他的子树是否包含那两个节点，找到最小的的子树即可
        时间复杂度o(n^2)(此为最差，平均不太好算。。。),空间复杂度为o(1)
   3.2) 如果能用额外空间，可以遍历两次(深度优先)获取根节点到那两个节点的路径，然后求两个路径的最后一个公共节点
        时间复杂度o(n)，空间复杂度o(logn)
*/

#include <stdio.h>

#include "tree.c"

/**
 * input: 148#956##7
 *           1
 *       4      8
 *     #   9  5   6
 *   #  # 7
 *  2）由下往上看，转化为找两个链表的第一个公共节点问题
 * 思路：
 *  1、可以暴力搜索 T(n) = O(mn)
 *  2、借助栈，判断每次出栈的元素是否一致，找到最后一个一样的 T(n) = O(m+n)
 *  3、首先遍历两个链表得到他们的长度，就能知道哪个链表比较长，以及长的链表比短的链表多几个结点。
 *     在第二次遍历的时候，在较长的链表上先走若干步，接着同时在两个链表上遍历，找到的第一个相同
 *     的结点就是他们的第一个公共结点。
 */
TreeNode *lowestCommonAncestorByParent(TreeNode *root, TreeNode *p, TreeNode *q){
    if (root == NULL || p == NULL || q == NULL){
        return NULL;
    }

    int lenOfp = 0;
    int lenOfq = 0;
    TreeNode *phead = p;
    TreeNode *qhead = q;
    
    // 遍历找到每个链表的长度
    while(phead != NULL){
        lenOfp++;
        phead = phead->parent;
    }
    while(qhead != NULL){
        lenOfq++;
        qhead = qhead->parent;
    }
    int step = lenOfp - lenOfq;
    if (step > 0){
        while(step>0){
            p = p->parent;
            step--;
        }
    }else{
        step = -1 * step;
        while(step>0){
            q = q->parent;
            step--;
        }
    }
    printf("p->val: %d\n", p->val);
    printf("q->val: %d\n", q->val);
    TreeNode *lowestCommonNode = NULL;
    // 找到第一个公共子节点
    while(p != NULL && q != NULL){
        if(p != q){
            p = p->parent;
            q = q->parent;
        }else{
            lowestCommonNode = p;
            break;
        }
    }

    return lowestCommonNode;
}


/**
 * 对应与3.1
 * @param root:根节点
 * @param p: 给定第一个结点
 * @param q: 给定第二个结点
 */
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
    // 找到节点或者root为NULL
    if (root == NULL||p == root||q == root){
        return root;
    }
    // 要么在左子树中，要么在右子树中
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    return root;
}


void test_lowestCommonAncestorByParent(){
    char *str = "148#956##7";
    TreeNode *pRoot = createTree(str);
    TreeNode *node1 = getNodeByVal(pRoot, 7);
    TreeNode *node2 = getNodeByVal(pRoot, 6);
    TreeNode *pCommonAncestor = lowestCommonAncestorByParent(pRoot,node1, node2);

    if(pCommonAncestor != NULL){
        printf("pCommonAncestor->val: %d", pCommonAncestor->val);
    }

    destoryTree(pRoot);
    pRoot = NULL;
    printf("\n");
}

void test_lowestCommonAncestor(){
    char *str = "148#956##7";
    TreeNode *pRoot = createTree(str);
    TreeNode *node1 = getNodeByVal(pRoot, 7);
    TreeNode *node2 = getNodeByVal(pRoot, 6);
    TreeNode *pCommonAncestor = lowestCommonAncestor(pRoot,node1, node2);

    if(pCommonAncestor != NULL){
        printf("pCommonAncestor->val: %d", pCommonAncestor->val);
    }

    destoryTree(pRoot);
    pRoot = NULL;
    printf("\n");
}

int main(void){
    test_lowestCommonAncestorByParent();
    test_lowestCommonAncestor();
    return 0;
}