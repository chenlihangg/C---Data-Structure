#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef double ElemType;

// 单链表的定义
struct LNode{
    ElemType data;
    LNode* next;
};

// 逆置带头结点的单链表,参数列表为：头节点，置换长链表的长度
void Reverse(LNode *&L,int length){
    if(length == 0) return;                    // 递归结束出口
    LNode *p = L;
    for(int i = 1;i <= length;i++){            // 让p指向尾结点
        p = p->next;
    }
    p->next->next = L->next;
    L->next = p->next;
    p->next = NULL;
    Reverse(L->next,length - 1);
}

// 输出单链表 
void DispList(LNode*& L){
    LNode*p = L->next;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 求链表的长度
int ListLength(LNode*& L){
    int num = 0;
    LNode* p = L->next;
    while(p != NULL){
        num++;
        p = p->next;
    }
    return num;
}

// 尾插法建立单链表
void TailCreateList(LNode*& L,ElemType data[],int length){
    L = new LNode;
    LNode*r = L;
    L->next = NULL;
    for(int i = 0;i < length;i++){
        LNode* p = new LNode;
        p->data = data[i];
        p->next = NULL;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    cout << "成功用尾插法建立了单链表" << endl;
}

// 销毁单链表
void Destory(LNode*& L){
    LNode *pre = L,*p;
    while(pre != NULL){
        p = pre->next;
        delete pre;
        pre = p;
    }
    cout << "单链表成功销毁" << endl;
}

int main(){
    LNode*L;
    double arr[8] = {1,3,2,4,5,6,7,8};
    TailCreateList(L,arr,8);
    DispList(L);
    Reverse(L,ListLength(L) - 1);
    DispList(L);
    Destory(L);    
    return 0;
}