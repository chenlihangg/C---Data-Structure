#include "LinkList.h"

ElemType data1[3] = {12,4,3};
ElemType data2[4] = {12,4,3,8};

// 对单链表进行排序
void SortList(LNode*&L){
    if(L == NULL || L->next == NULL) return;
    LNode* pre,*p = L->next->next,*q;
    L->next->next = NULL;
    while(p != NULL){
        q = p->next;
        pre = L;
        while(pre->next!=NULL&&pre->next->data<p->data){
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

// 求两个单链表的并集L3
void UnionList(LNode*&L1,LNode*&L2,LNode*&L3){
    InitList(L3);
    LNode*p1 = L1->next,*p2 = L2->next,*r3 = L3;
    while(p1 != NULL || p2 != NULL){
        // p1与p2均非空时
        if(p1 != NULL && p2 != NULL){
            LNode*q = new LNode;
            if(p1->data == p2->data){
                q->data = p1->data; q->next = NULL;
                r3->next = q;
                r3 = q;
                p1 = p1->next; p2 = p2->next;
            }else if(p1->data < p2->data){
                q->data = p1->data; q->next = NULL;
                r3->next = q;
                r3 = q;
                p1 = p1->next;
            }else{
                q->data = p2->data; q->next = NULL;
                r3->next = q;
                r3 = q;
                p2 = p2->next;
            }
        }else if(p1 == NULL){            // p1为空时
            while(p2 != NULL){
                LNode*q = new LNode;
                q->data = p2->data; q->next = NULL;
                r3->next = q; r3 = q;
                p2 = p2->next;
            }
        }else{                           // p2为空时
            while(p1 != NULL){
                LNode*q = new LNode;
                q->data = p1->data; q->next = NULL;
                r3->next = q; r3 = q;
                p1 = p1->next;
            }
        }
        
   }
}

// 求两个单链表的交集L3
void InterSectionList(LNode*&L1,LNode*&L2,LNode*&L3){
    InitList(L3);
    LNode*p1 = L1->next,*p2,*r3 = L3;
    while(p1 != NULL){
        p2 = L2->next;
        while(p2 != NULL && p2->data < p1->data){
            p2 = p2->next;
        }
        if(p2 == NULL) continue;         // p2中找不到与p1相同的元素时，跳过
        if(p2->data == p1->data){
            LNode*q = new LNode;
            q->data = p2->data; q->next = NULL;
            r3->next = q; r3 = q;
        }
        p1 = p1->next;
    }
}

// // 求两个单链表的差集:L1\l2
void DifferenceList(LNode*&L1,LNode*&L2,LNode*&L3){
    InitList(L3);
    LNode*p1=L1->next,*p2,*r3 = L3;
    while(p1 != NULL){
        p2 = L2->next;
        while(p2 != NULL && p2->data < p1->data){
            p2 = p2->next;
        }
        if(p2 != NULL){
            if(p2->data > p1->data){
                LNode*q = new LNode;
                q->data = p1->data; q->next = NULL;
                r3->next = q; r3 = q;
            }
        }

        p1 = p1->next;
    }
}

int main(){

    LNode*L1,*L2;
    TailCreateList(L1,data1,3);
    TailCreateList(L2,data2,4);
    
    SortList(L1);
    SortList(L2);

    
    

    // LNode*L3;
    // UnionList(L1,L2,L3);
    // DispList(L1);
    // DispList(L2);
    // DispList(L3);

    // LNode*L4;
    // InterSectionList(L1,L2,L4);
    // DispList(L1);
    // DispList(L2);
    // DispList(L4);

    LNode*L5;
    DifferenceList(L1,L2,L5);
    DispList(L1);
    DispList(L2);
    DispList(L5);

    Destory(L1);
    Destory(L2);
    // Destory(L3);
    // Destory(L4);
    Destory(L5);
    return 0;
}