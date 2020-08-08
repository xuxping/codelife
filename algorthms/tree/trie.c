/**
 * 介绍：
 * Trie树，即字典树，又称单词查找树或键树，是一种树形结构，是一种哈希树的变种。
 * 典型应用是用于统计和排序大量的字符串（但不仅限于字符串），
 * 所以经常被搜索引擎系统用于文本词频统计，单词联想，判断字符串是否存在。
 * 优点是：利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较，查询效率比哈希树高。
 * 
 * 特点：
 * 1. 根节点不包含字符，每条边代表一个字符。
 * 2. 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
 * 3. 每个节点的所有子节点包含的字符都不相同。
 * 
 * 常见面试题：
 * 1、串的快速检索
 * 2、最长公共前缀
 * 3、文本词频统计
 * 4、“串”排序
 * 4、多模式匹配
 * 
 * 参考资料：
 * https://zhuanlan.zhihu.com/p/28891541
 * https://baike.baidu.com/item/%E5%AD%97%E5%85%B8%E6%A0%91
 **/

#include <stdio.h>
#include <stdlib.h>

#define MAX 26 // 26个英文字母

typedef struct TrieNode{
    int count; // 以当前单词结尾的单词数量，统计单词出现的次数
    int prefix; // prefix表示以该处节点之前的字符串为前缀的单词数量。
    struct TrieNode* next[MAX]; 
}TrieNode;

TrieNode *createTrieNode(){
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->count = 0;
    p->prefix = 0;
    for(int i = 0; i < MAX; ++i){
        p->next[i] = NULL;
    }
    return p;
}

// 插入字符串
void insertTrieNode(TrieNode *pRoot, char *str){
    if(pRoot == NULL || str == NULL || *str == '\0') {
        printf("EORROR:pRoot is NULL;");
        return;
    }
    TrieNode *p = pRoot;
    while(*str != '\0'){
        int k = (*str++) - 'a';
        if(p->next[k] == NULL)
            p->next[k] = createTrieNode();
        p = p->next[k];
        p->prefix++;
    }
    p->count++; // 以当前单词结尾的单词数量

}

int search(TrieNode *pRoot, char *str){
    if(pRoot == NULL || str == NULL || *str == '\0') {
        return 0;
    }
    TrieNode *p = pRoot;
    while(*str != '\0'){
        int k = (*str++) - 'a';
        if(p->next[k] == NULL){
            return 0;
        }
        p = p->next[k];
    }
    return p->count;
}

// 查询以str为前缀的单词数量
int searchPrefix(TrieNode *pRoot, char *str){
    if(pRoot == NULL || str == NULL || *str == '\0') {
        return 0;
    }
    TrieNode *p = pRoot;
    while(*str != '\0'){
        int k = (*str++) - 'a';
        if(p->next[k] == NULL){
            return 0;
        }
        p = p->next[k];
    }
    return p->prefix;
}

// 最长公共前缀
int getMaxCommonPrefixCount(TrieNode *pRoot){
    if(pRoot == NULL) return 0;
    TrieNode *p = pRoot;
    int count = 0;
    int k = -1;
    for(int i = 0 ; i < MAX; ++i){
        if(p->next[i] != NULL){
            count++;
            k = i;
        }
    }
    if(count == 1){
        return count + getMaxCommonPrefixCount(p->next[k]);
    }
    return 0;
}

int nIdx = 0;
void getStr(TrieNode *pRoot, char *s){
    TrieNode *p = pRoot;
    int hasNext = 0;
    int hasPrint = 0;
    for(int i = 0 ; i < MAX; ++i){
        if(p->next[i]!=NULL){
            hasNext = 1;
            s[nIdx++] = i + 'a'; // 入栈操作
            getStr(pRoot->next[i], s);
        }
        if(!hasPrint && p->count > 0){
            for(int j = 0; j< nIdx; j++){
                printf("%c", s[j]);
            }
            printf("\n");
            hasPrint = 1;
        }
    }
    nIdx--;
}

// 输出排序后的字符串
void printSortTrie(TrieNode *pRoot){
    char *s = (char *)malloc(sizeof(char) * MAX);
    int idx = 0;
    TrieNode *p = pRoot;
    getStr(pRoot, s);
    free(s);
    s = NULL;
}


// 删除树
void deleteTrie(TrieNode *pRoot){
    if(pRoot == NULL) return;
    TrieNode *p = pRoot;
    for(int i = 0; i < MAX; ++i){
        if(p->next[i]!=NULL){
            deleteTrie(p->next[i]);
        }
    }
    
    free(pRoot);
    pRoot = NULL;
}



int main(void){
    printf("============== create trie ==============\n");
    TrieNode *pRoot = createTrieNode();
    char *str[5] = {"abcd", "abcf","abc","abkf","akbcf"};
    printf("============== insert trie ==============\n");
    for(int i = 0; i < 5; ++i){
        insertTrieNode(pRoot, str[i]);
    }
    printf("search result: %d\n", search(pRoot, "ab"));
    printf("search result: %d\n", search(pRoot, "abkf"));
    printf("searchPrefix result: %d\n", searchPrefix(pRoot, "ab"));
    printf("getMaxCommonPrefixCount result: %d\n", getMaxCommonPrefixCount(pRoot));
    printf("printSortTrie result:\n");
    printSortTrie(pRoot);
    deleteTrie(pRoot);
    return 0;
}