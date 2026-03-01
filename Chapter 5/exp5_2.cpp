#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 50
using namespace std;

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

void Display(SqStack *&st){
    for(int p = 0;p <= st->top;p++){
        cout << "(" << st->data[p].i << "," << st->data[p].j <<")";
    }
    cout << endl;
}

void Path(int &m,int &n,int i,int j,SqStack *&st,Box &e){
    if(i <= m && j <= n) {              // 在网格中
        if(i == m && j == n){           // 到达终点
            Display(st);
        }
        e.i = i + 1; e.j = j; Push(st,e); Path(m,n,i+1,j,st,e); Pop(st,e);  // 向下走
        e.i = i; e.j = j + 1; Push(st,e); Path(m,n,i,j+1,st,e); Pop(st,e);  // 向右走
    }
}


int main(){
    SqStack *s;
    InitStack(s);
    Box e;
    int rows = 3,cols = 4;
    Path(rows,cols,1,1,s,e);
    
    DestoryStack(s);
    return 0;
}