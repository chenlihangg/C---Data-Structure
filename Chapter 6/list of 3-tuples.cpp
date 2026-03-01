#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// 稀疏矩阵的三元组表存储

#define M 10                     // 稀疏矩阵的行数
#define N 10                     // 稀疏矩阵的列数
#define MaxSize 100              // 稀疏矩阵非零元素的最多个数
typedef float ElemType;

ElemType mg[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

struct TupNode{              // 三元组的定义
    int i,j;                 // 行号和列号
    ElemType d;              // 对应的元素；
};

struct TSMatrix{
    int rows,cols;           // 稀疏矩阵的行数，列数
    int nums;                // 非零元素的个数
    TupNode data[MaxSize];      // 以矩阵的行序为主序
};

void CreateMat(TSMatrix *&t,ElemType mg[M][N]){
    int i,j;
    t = new TSMatrix;
    t->rows = M; t->cols = N; t->nums = 0;
    for(i = 0;i < t->rows;i++){
        for(j = 0;j < t->cols;j++){
            if(mg[i][j] != 0){
               t->data[t->nums].i = i;
               t->data[t->nums].j = j;
               t->data[t->nums].d = mg[i][j];
               t->nums++;
            }
        }
    }
}

// 在(i,j)上赋值
bool Vaule(TSMatrix *&t,int i,int j,ElemType e){
    if(i >= t->rows || j >= t->cols) return false;
    int count = 0;
    while(count < t->nums && t->data[count].i < i){
        count++;
    }
    while(count < t->nums && t->data[count].i == i && t->data[count].j < j){
        count++;
    }
    if(t->data[count].i == i && t->data[count].j == j){                   // 找到相应位置的元素
        t->data[count].d = e;
    }else{                                                                // 创建新的元素插入到三元组表中   
        TupNode x;
        x.i = i; x.j = j; x.d = e;
        for(int p = t->nums;p > count;p--){
            t->data[p] = t->data[p-1];
        } 
        t->data[count] = x;
        t->nums++;
    }
    return true;
    
}

// 打印
void Disp(TSMatrix *&t){
    for(int i = 0;i < t->nums;i++){
        cout << "第" << i + 1 << "个元素坐标为(" << t->data[i].i << "," << t->data[i].j << "),元素为" << t->data[i].d;
        cout << endl;
    }
}

// 转置矩阵后将其输入到三元组表中
void Trans(TSMatrix *&ta,TSMatrix *&tb){
    tb->nums = 0;
    tb->rows = ta->cols; tb->cols = ta->rows;
    int p;
    for(int j = 0;j < N;j++){
        for(p = 0;p < ta->nums;p++){
            if(ta->data[p].j == j){
                tb->data[tb->nums].i = ta->data[p].j;
                tb->data[tb->nums].j = ta->data[p].i;
                tb->data[tb->nums].d = ta->data[p].d;
                tb->nums++;
            }
        }
    }
}

int main(){
    TSMatrix *t,*tb;
    CreateMat(t,mg);
    
    Vaule(t,7,8,100);
    

    tb = new TSMatrix;
    Trans(t,tb);
    Disp(tb);

    delete t;
    return 0;
}