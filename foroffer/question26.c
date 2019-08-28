// 判断两棵树是否含有相同的子结构 

#include <stdio.h>
#include "../algorthms/tree/tree.h"
#include <string.h>

typedef TreeNode BSTree;

// double类型不能直接用==判断两数是否相对，浮点型数据表示都会存在一点误差
int equal(double val1, double val2){
    if (val1 - val2 > -0.000001 && val1 - val2 < 0.000001){
        return 1;
    }
    return 0;
}

// 递归判断两个子树是否相同
int doesTree1hasTree2(BSTree *pRoot1, BSTree *pRoot2){
    if (pRoot2 == NULL){
        return 1;
    }
    if (pRoot1 == NULL){
        return 0;
    }
    if (!equal(pRoot1->val, pRoot2->val)){
        return 0;
    }

    return doesTree1hasTree2(pRoot1->left, pRoot2->left) && 
            doesTree1hasTree2(pRoot1->right, pRoot2->right);
}

int hasSubTree(BSTree *pRoot1, BSTree *pRoot2){
    int result = 0;

    if(pRoot1 != NULL && pRoot2 != NULL){
        if(equal(pRoot1->val, pRoot2->val)){
            result = doesTree1hasTree2(pRoot1, pRoot2);
        }

        if (!result){
            result = hasSubTree(pRoot1->left, pRoot2);
        }

        if(!result){
            result = hasSubTree(pRoot1->right, pRoot2);
        }
    }

    return result;
}

void test1(){
    char *str1 = "148#456##7";
    BSTree *pRoot1 = createTree(str1);
    preOrderWalkRecursion(pRoot1);
    printf("\n");

    char *str2 = "4#4";
    BSTree *pRoot2 = createTree(str2);
    preOrderWalkRecursion(pRoot2);
    printf("\n");

    int result = hasSubTree(pRoot1, pRoot2);
    printf("result = %d \n", result);
}
void test2(){
    char *str1 = "148#456##7";
    BSTree *pRoot1 = createTree(str1);
    preOrderWalkRecursion(pRoot1);
    printf("\n");

    char *str2 = "85";
    BSTree *pRoot2 = createTree(str2);
    preOrderWalkRecursion(pRoot2);
    printf("\n");

    int result = hasSubTree(pRoot1, pRoot2);
    printf("result = %d \n", result);
}


int main(void){
    test1();
    test2();

    return 0;
}