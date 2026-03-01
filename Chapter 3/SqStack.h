#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 50
using namespace std;

typedef char ElemType;

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
    for(int i = 0;i <= st->top;i++){
        cout << st->data[i] << " ";
    }
    cout << endl;
}

bool GetTop(SqStack *&st,ElemType &e){
    if(EmptyStack(st)) return false;
    e = st->data[st->top];
    return true;
}

// void test(){
//     string str = "acdes"; char e;
//     SqStack *st;
//     InitStack(st);
//     for(int i = 0;i < str.size();i++){
//         Push(st,str[i]);
//     }
//     Display(st);
//     Pop(st,e); Pop(st,e);
//     Display(st);
//     DestoryStack(st);
// }