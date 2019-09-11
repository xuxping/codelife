
#include <stdio.h>
#include <stdlib.h>
#include "../tree/tree.c"
#include "../tree/BinarySearchTree.c"


void test_BinarySearchTree(){
    char *str = "64835792";
    BSTree *pRoot = createTree(str);
    BSTree *pNode = TreeSearch(pRoot, 4);

    if (pNode != NULL){
        printf("pNode->val: %d\n", pNode->val);
    }
    BSTree *minNode = TreeMinimum(pRoot);
    BSTree *maxNode = TreeMaximum(pRoot);
    printf("min Node->val: %d\n",minNode->val);
    printf("max Node->val: %d\n",maxNode->val);

    BSTree *succNode = TreeSuccessor(minNode);
    BSTree *preNode = TreePreSuccessor(maxNode);
    printf("min succNode->val: %d\n",succNode->val);
    printf("max preNode->val: %d\n",preNode->val);
    
    // output:
    // pNode->val: 4
    // min Node->val: 2
    // max Node->val: 9
    // min succNode->val: 3
    // max preNode->val: 8
    
    destoryTree(pRoot);
    pRoot = NULL;
    printf("\n");
}

int main(void){
    test_BinarySearchTree();
    return 0;
}