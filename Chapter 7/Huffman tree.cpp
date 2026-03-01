#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// 哈夫曼树：定义，构造，存储，遍历
struct HTNode{
    char data;                   // 结点值
    double weight;               // 权重
    int parent;                  // 双亲结点
    int lchild;                  // 左孩子
    int rchild;                  // 右孩子
};

// 哈夫曼树的构造
void CreateHT(HTNode ht[],int n0){
    int i,k,lnode,rnode;
    double min1,min2;
    for(i = 0;i < 2*n0 -1;i++){                            // 所有节点的相关域置初值-1
        ht[i].lchild = ht[i].rchild = ht[i].parent = -1;
    }
    for(i = n0;i <= 2*n0 - 2;i++){                         // 构造出n0 - 1个分支结点
        min1 = min2 = 19999;
        lnode = rnode = -1;
        for(k = 0;k <= i - 1;k++){             
            if(ht[k].parent == -1){                        // 筛选掉已经构造过的叶子节点。只处理没有构造的
                if(ht[k].weight < min1){                   // 找到权值最小的两个结点
                    min2 = min1; min1 = ht[k].weight;
                    rnode = lnode; lnode = k;
                }else if(ht[k].weight < min2){
                    min2 = ht[k].weight; rnode = k;
                }
            }            
        }
        ht[i].lchild = lnode; ht[i].rchild = rnode;
        ht[lnode].parent = ht[rnode].parent = i;
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
    }
}

// 哈夫曼编码
#define MaxSize 20
struct HCode{
    char cd[MaxSize];           // 存放当前节点的哈夫曼编码
    int start;                  // 表示cd[start,  ,n0]是哈夫曼编码
};
void CreateHCode(HTNode ht[],HCode hcd[],int n0){
    int i,f,c;
    HCode hc;
    for(i = 0l;i < n0;i++){
        hc.start = n0; c = i;            // 从叶子节点逐步往上确定编码，与start从末尾处开始往前迭代呼应
        f = ht[i].parent;
        while(f != -1){                  // 循环到无双亲结点，即到达根节点
            if(ht[f].lchild == i ){
                hc.cd[hc.start--] = '0';
            }else{
                hc.cd[hc.start--] = '1';
            }
            c = f; f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;
    }
}

int main(){



    return 0;
}