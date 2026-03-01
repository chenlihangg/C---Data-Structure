#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef char ElemType;

struct LinkNode{
    ElemType data;
    LinkNode* next;
};

void InitStack(LinkNode*& st){
    st = new LinkNode;
    st->next = NULL;
}

void DestoryStack(LinkNode*& st){
    LinkNode* p = st,* q;
    while(p!= NULL){
        q = p->next;
        delete p;
        p = q;
    }
}

bool EmptyStack(LinkNode*& st){
    return st->next == NULL;
}

bool Push(LinkNode*& st,ElemType e){
    LinkNode *p = new LinkNode;
    p->data = e;
    p->next = st->next;
    st->next = p;
    return true;                            // 头插法入栈，保证入栈位置在头结点处
}

bool Pop(LinkNode*& st,ElemType &e){
    if(EmptyStack(st)) return false;
    LinkNode* p = st->next;
    e = p->data;
    st->next = p->next;
    delete p;
    return true;
}

void Display(LinkNode*& st){
    if(EmptyStack(st)) return;
    Display(st->next);
    cout << st->next->data << " ";
}



void test(){
    string str = "abcde";
    LinkNode* st;
    InitStack(st);
    for(int i = 0;i < 5;i++){
        Push(st,str[i]);
    }
    Display(st);
    DestoryStack(st);
}