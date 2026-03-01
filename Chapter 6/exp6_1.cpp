#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// 稀疏矩阵的三元组表存储

#define M 4                     // 稀疏矩阵的行数
#define N 4                     // 稀疏矩阵的列数
#define MaxSize 16              // 稀疏矩阵非零元素的最多个数
typedef float ElemType;

ElemType A[M][N] = {
    {1,0,3,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,1,1}
};

ElemType B[M][N] = {
    {3,0,0,0},
    {0,4,0,0},
    {0,0,1,0},
    {0,0,0,2}
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

// 给出矩阵相乘后的三元组
void Multi(ElemType A[M][N],ElemType B[M][N],TSMatrix *&c){
    c = new TSMatrix;
    c->rows = M; c->cols = N; c->nums = 0;
    int i,j,k;
    ElemType e;
    TupNode elem;
    for(i = 0;i < c->rows;i++){
        for(j = 0;j < c->cols;j++){
            e = 0;
            for(k = 0;k < M;k++){
                e += A[i][k] * B[k][j];
            }
            if(e != 0){
                elem.i = i; elem.j = j; elem.d = e;
                c->data[c->nums++] = elem;
            }
        }
    }
}

int main(){

    TSMatrix *C;
    Multi(A,B,C);
    Disp(C);



    return 0;
}