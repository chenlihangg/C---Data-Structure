#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


typedef float ElemType; 
#define MaxSize 50

// 双亲存储结构
struct PTree{
    ElemType data[MaxSize];               // 存放结点值
    int parent[MaxSize];                  // 存放
};

// 孩子链存储结构
#define MaxSons 10                        // 最大的结点度数，即树的度
struct TSonNode{
    ElemType data;
    TSonNode *sons[MaxSons];
};

int TreeHeight1(TSonNode *t){
    int maxh = 0,h,i;
    TSonNode *son;
    if(t != NULL){
        for(i = 0;i < MaxSons;i++){
            h = TreeHeight1(t->sons[i]);
            if(maxh < h) maxh = h;
        }
    }
    return maxh + 1;
}

// 孩子兄弟链存储结构
struct TSBNode{
    ElemType data;
    TSBNode *bt;                   // 指向兄弟结点
    TSBNode *st;                   // 指向孩子结点
};

int TreeHeight2(TSBNode *t){
    int maxh = 0,h;
    if(t == NULL) return maxh;
    TSBNode *son = t->st;
    while(son != NULL){
        h = TreeHeight2(son);
        if(maxh < h) maxh = h;
        son = son->bt;
    }
    return maxh + 1;
   
}

int main(){


    return 0;
}