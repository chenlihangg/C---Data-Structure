#include "LinkList.h"

// 将两个单链表L1,L2交替合并为新的单链表L3,多的部分全部接到最后面
void Integral(LNode*& L1,LNode*& L2,LNode*& L3){
    InitList(L3);
    LNode*r1 = L1->next,*r2 = L2->next,*r3 = L3,*p,*q;
    while(r1 != NULL && r2 != NULL){
        p = r1->next; q = r2->next;
        r3->next = r1; r3 = r1;
        r3->next = r2; r3 = r2;
        r1 = p; r2 = q;
    }
    if(r1 == NULL){
        r3->next = r2;
    }else{
        r3->next = r1;
    }
}

ElemType data1[3] = {1,3,5};
ElemType data2[4] = {2,4,6,8};

int main(){
    LNode*L1,*L2,*L3;
    TailCreateList(L1,data1,3);
    TailCreateList(L2,data2,4);
    Integral(L1,L2,L3);

    DispList(L3);
    
    Destory(L1);  
    Destory(L2);

    return 0;
}