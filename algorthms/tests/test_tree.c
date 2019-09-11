// test tree algorithms

#include <stdio.h>
#include "../tree/tree.c"
#include "../utils.c"

void test_preOrderWalkRecursion(){
    char *str = "148#456##7";
    TreeNode *pRoot = createTree(str);
    preOrderWalkRecursion(pRoot);
    destoryTree(pRoot);
    pRoot = NULL;
    printf("\n");
}

void test_preOrderWalk(){
    char *str = "148#456##7";
    TreeNode *pRoot = createTree(str);
    preOrderWalk(pRoot);
    destoryTree(pRoot);
    pRoot = NULL;
    printf("\n");
}

void test_inorderTreeWalkRecursion(){
    char *str = "148#456##7";
    TreeNode *pRoot = createTree(str);
    inorderTreeWalkRecursion(pRoot);
    destoryTree(pRoot);
    pRoot = NULL;
    printf("\n");
}

void test_inOrderWalk(){
    char *str = "148#456##7";
    TreeNode *pRoot = createTree(str);
    inOrderWalk(pRoot);
    destoryTree(pRoot);
    pRoot = NULL;
    printf("\n");
}

void test_lastOrderWalkRecursion(){
    char *str = "148#456##7";
    TreeNode *pRoot = createTree(str);
    lastOrderWalkRecursion(pRoot);
    destoryTree(pRoot);
    pRoot = NULL;
    printf("\n");
}

void test_lastOrderWalk(){
    char *str = "148#456##7";
    TreeNode *pRoot = createTree(str);
    lastOrderWalk(pRoot);
    destoryTree(pRoot);
    pRoot = NULL;
    printf("\n");
}

void test_getNodePathByVal(){
    char *str = "148#956##7";
    TreeNode *pRoot = createTree(str);
    TreeNode *node = getNodeByVal(pRoot, 7);
    if(node != NULL){
        printf("find node: %d\n", node->val);
    }
    
    destoryTree(pRoot);
    pRoot = NULL;
    printf("\n");
}

/**
 * input: 148#956##7
 *           1
 *       4      8
 *     #   9  5   6
 *   #  # 7
 */ 
void test_getNodePath(){
    char *str = "148#956##7";
    TreeNode *pRoot = createTree(str);
    TreeNode *node = getNodeByVal(pRoot, 7);
    printf("find node: %d\n", node->val);

    TreeStack *treeStack = getNodePath(pRoot, node);
    while(treeStack->top >= 0){
        TreeNode *pNode = treeStack->stack[treeStack->top];
        printf("%d\n", pNode->val);
        --treeStack->top;
    }
    free(treeStack->stack);
    treeStack->stack=NULL;
    free(treeStack);
    treeStack = NULL;
    destoryTree(pRoot);
    pRoot = NULL;
}


int main(void){
    // test_preOrderWalkRecursion();
    // test_preOrderWalk();
    // test_inorderTreeWalkRecursion();
    // test_inOrderWalk();
    // test_lastOrderWalkRecursion();
    // test_lastOrderWalk();
    test_getNodePath();
    // test_getNodePathByVal();
    return 0;
}