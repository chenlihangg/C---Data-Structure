#include "SqList.h"

// example 1: 将值为x的所有元素删去，要求时间复杂度为o(n),空间复杂度为o(1)
void DelNode(SqList*& L,ElemType x){
    int i = 0,k = 0;
    for(;i < L->length;i++){
        if(L->data[i] != x){
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

// example 2: 元素前后交换法(快速排序法的基础,构造基准，小于或等于该基准的移到基准前面，大于基准的移动到后面)
void Partition1(SqList*&L){
    int i = 0,j = L->length - 1;
    ElemType base = L->data[0];           // 以第一个元素作为基准
    while(i < j){
        while(i < j && L->data[j] > base) j--;
        L->data[i] = L->data[j];
        while(i < j && L->data[i] <= base) i++;
        L->data[j] = L->data[i];
    }           
    L->data[i] = base;                    // 第i个元素已经赋值到别的位置，该位置可被base覆盖
}

int main(){
    
    test();
    return 0;
}