#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 20
using namespace std;

typedef float ElemType;

// 单链表的定义
struct LNode{
    ElemType data;
    LNode* next;
};

// 头插法建立单链表
void HeadCreateList(LNode*& L,ElemType data[],int length){
    L = new LNode;
    L->next = NULL;
    for(int i = 0;i < length;i++){
        LNode*p = new LNode;
        p->data = data[i];
        p->next = L->next;
        L->next = p;
    }
    cout << "成功用头插法建立了单链表" << endl;
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

// 初始化单链表
void InitList(LNode*& L){
    L = new LNode;
    L->next = NULL;
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

// 判断链表是否为空
bool ListEmpty(LNode*& L){
    return L->next == NULL;
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


// 输出单链表 
void DispList(LNode*& L){
    LNode*p = L->next;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 按序号获取链表中的元素,并赋值给输出型参数e
bool GetElem(LNode*& L,int i,ElemType& e){
    LNode*p = L->next;
    int num = 1;
    if(i <= 0) return false;
    while(num < i&&p!=NULL){
        p = p->next;
        num++;
    }
    if(p == NULL){
        cout << "获取元素失败" << endl;
        return false;
    }else{
        e = p->data;
        cout << "获取元素成功" << endl;
        return true;
    }
}

// 查找元素值e，返回其逻辑序号，不存在则返回0
int SearchElem(LNode*& L,ElemType e){
    LNode* p = L->next;
    int num = 1;
    while(p!=NULL && p->data!= e){
        p = p->next;
        num++;
    }
    if(p == NULL){
        return 0;
    }else{
        return num;
    }
}

// 插入数据元素
bool InsertList(LNode*& L,int i,ElemType e){
    if(i <= 0 || i > ListLength(L) + 1 ) return false;
    LNode*p = L->next;
    for(int j = 1;j < i - 1 && p != NULL;j++){
        p = p->next;
    }
    LNode *q = new LNode;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

// 删除数据元素
bool DeleteList(LNode *&L,int i){
    if(i <= 0 || i > ListLength(L)) return false;
    LNode*p = L->next;
    for(int j = 1;j < i - 1 && p != NULL;j++){
        p = p->next;
    }
    LNode*q = p->next;
    p->next = q->next;
    delete q;
    return true;
}

// test:
void test(){

    ElemType data[7] = {1.3,1.4,1.6,2.1,1.9,3.2,6.2};
    LNode *L;

    // // 头插法测试
    // HeadCreateList(L,data,7);
    // cout << "链表的长度:" << ListLength(L)  << endl;
    // DispList(L);
    // Destory(L);

    // 尾插法测试
    TailCreateList(L,data,7);
    // cout << "链表的长度:" << ListLength(L)  << endl;
    DispList(L);
    // float e = 3;
    // GetElem(L,4,e);
    // cout << "单链表第4个元素为" << e << endl;
    // cout << "单链表中" << e << "的下标为" << SearchElem(L,e) << endl;
    // InsertList(L,8,e);
    DeleteList(L,3);
    DispList(L);
    Destory(L);
    

}


// 双链表的定义
struct DNode{
    DNode* prior;
    DNode* next;
    ElemType data;
};

// 双链表的相关算法与单链表类似，仅多了前驱指针的处理，故从略，循坏链表同理
// 有序表的结构均可归类到链表或顺序表，也从略