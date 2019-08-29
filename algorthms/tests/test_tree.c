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


int main(void){
    // test_preOrderWalkRecursion();
    // test_preOrderWalk();
    // test_inorderTreeWalkRecursion();
    // test_inOrderWalk();
    
    test_lastOrderWalkRecursion();
    test_lastOrderWalk();
    return 0;
}