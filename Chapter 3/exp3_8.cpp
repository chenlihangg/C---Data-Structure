#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 50
#define n 8
using namespace std;

// n皇后问题求解思路：对每一行，可以放置时就进栈然后进入下一行，不能放置时就出栈然后退回上一行
struct Box{
    int i,j;
};

typedef Box ElemType;

struct SqStack{
    ElemType data[MaxSize];   // 存放数据元素
    int top;                  // 存放栈顶指针
};

void InitStack(SqStack*& st){
    st = new SqStack;
    st->top = -1; 
}

void DestoryStack(SqStack*& st){
    delete st;
}

bool EmptyStack(SqStack*& st){
    return st->top == -1;
}

bool Push(SqStack*& st,ElemType e){
    if(st->top >= MaxSize - 1) return false;
    st->top++;
    st->data[st->top] = e;
    return true;
}

// 退栈
bool Pop(SqStack*& st,ElemType &e){
    if(st->top <= -1) return false;
    e = st->data[st->top];
    st->top--;
    return true;
}

bool GetTop(SqStack *&st,ElemType &e){
    if(EmptyStack(st)) return false;
    e = st->data[st->top];
    return true;
}


int arr[n][n] = {};              // 棋盘的状态数组，0表示可以放置，非0表示不能放置

// 在(i,j)上放置皇后
bool SetQueen(int i,int j){
    if(arr[i][j] != 0) return false;
    int p,q;
    for(p = 0;p < n;p++) arr[p][j]++;              // 该列全都加一
    for(q = 0;q < n;q++) arr[i][q]++;              // 该行全都加一
    for(p = i,q = j;p >= 0 && q >= 0;p--,q--) arr[p][q]++;       // 左上对角线加一
    for(p = i,q = j;p >= 0 && q < n;p--,q++) arr[p][q]++;        // 右上对角线加一
    for(p = i,q = j;p < n && q >= 0;p++,q--) arr[p][q]++;        // 左下对角线加一
    for(p = i,q = j;p < n && q < n;p++,q++) arr[p][q]++;         // 右下对角线加一
    arr[i][j] = arr[i][j] - 5;
    return false;
}

// 在(i,j)上回溯皇后
bool ReSetQueen(int i,int j){
    if(arr[i][j] == 0) return false;
    int p,q;
    for(p = 0;p < n;p++) arr[p][j]--;              // 该列全都加一
    for(q = 0;q < n;q++) arr[i][q]--;              // 该行全都加一
    for(p = i,q = j;p >= 0 && q >= 0;p--,q--) arr[p][q]--;       // 左上对角线加一
    for(p = i,q = j;p >= 0 && q < n;p--,q++) arr[p][q]--;        // 右上对角线加一
    for(p = i,q = j;p < n && q >= 0;p++,q--) arr[p][q]--;        // 左下对角线加一
    for(p = i,q = j;p < n && q < n;p++,q++) arr[p][q]--;         // 右下对角线加一
    arr[i][j] = arr[i][j] + 5;
    return true;
}

void NQueen(){
    SqStack *st;
    InitStack(st);
    Box e;
    int i = 0,j = 0,count = 0,m;
    while(i < n && i >= 0){
        if(j <= n - 1 && arr[i][j] == 0){            // 该位置可以放置皇后
            e.i = i; e.j = j;
            Push(st,e);
            SetQueen(i,j);
            i++; j = 0;                // 从下一行的最左边开始搜索
        }else{                         // 该位置不可以放置皇后
            if(j < n - 1){             // 该位置不是最右边的情形时，继续往右搜索
                j++;   
            }else{                     // 该位置是最右边的情形，此时则需要退栈，然后退回到上一行
                Pop(st,e);             // 将最近的皇后剔除
                ReSetQueen(e.i,e.j);   // 将棋盘恢复原状
                i--; j = e.j + 1;      // 从上一个皇后位置的右一格位置开始搜索
            }
        }
        if(st->top == n - 1){          // 栈中有n元素，即有n个皇后，则可以输出信息并且回退
            count++;
            cout << "这是第" << count << "个方案:" << endl;
            for(m = 0;m <= st->top;m++){
                cout << "(" << st->data[m].i << "," << st->data[m].j << ") ";  
            }
            cout << endl;
            Pop(st,e);                 // 将最近的皇后剔除
            ReSetQueen(e.i,e.j);       // 将棋盘恢复原状
            i--; j = e.j + 1;          // 从上一个皇后位置的右一格位置开始搜索
        }
    }
    
    

    DestoryStack(st);
}

void Disp(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
   
    NQueen();

    return 0;
}