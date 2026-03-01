#include "LinkList.h"

ElemType data[7] = {3.0,1.4,1.6,2.1,1.9,3.2,6.2};

// 将单链表的首节点值x为基准将该单链表分割为两部分，使所有小于x的结点排在大于等于x的结点之前
void partition(LNode*& L){
    ElemType base = L->next->data;
    LNode* L2 = new LNode,* cur = L->next,*r = L,*r2 = L2;
    L2->next = L->next = NULL;
    while(cur != NULL){
        if(cur->data < base){
            r->next = cur;
            r = cur;
        }else{
            r2->next = cur;
            r2 = cur;
        }
        cur = cur->next;
    }
    r->next = L2->next;
}

int main(){
    LNode* L;
    TailCreateList(L,data,7);
    DispList(L);
    partition(L);
    DispList(L);
    Destory(L);
        
    return 0;
}