#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 20
using namespace std;

typedef float ElemType;              // 定义线性表的元素类型

//  顺序表的定义
struct SqList{
    ElemType data[MaxSize];            // 存放线性表的元素
    int length;                     // 存放线性表的长度
};

// 顺序表的创建
void CreateList(SqList*& L,ElemType a[],int n){
    int k = 0;
    L = new SqList;             // 初始化内存
    for(int i = 0;i < n;i++,k++){
        L->data[i] = a[i];
    }
    L->length = k;
    cout << "线性表已成功创建" << endl; 
}

// 顺序表的初始化
void InitList(SqList*& L){
    L = new SqList;
    L->length = 0;
}

// 顺序表的销毁
void DestoryList(SqList*& L){
    delete L;
    cout << "线性表已成功销毁" << endl;
}

// 判断顺序表是否为0
bool ListEmpty(SqList*& L){
    return L->length == 0;
}

// 求顺序表的长度
int ListLength(SqList*& L){
    return L->length;
}

// 输出顺序表
void DispList(SqList*& L){
    for(int i = 0;i < L->length;i++){
        cout << L->data[i] << " ";
    }
    cout << endl;
}

// 按元素值查找,查找第一个值为e的逻辑序号，若不存在则返回0
int SearchElem(SqList*& L,ElemType e){
    for(int i = 0;i < L->length;i++){
        if(L->data[i] == e) return i + 1;
    }
    return 0;
}

// 在第i个位置插入数据元素e,成功插入返回true，失败则返回false
bool InsertList(SqList*& L,int i,ElemType e){
    if(i <= 0||i > L->length + 1||L->length == MaxSize){
        return false;
    }
    for(int k = L->length - 1;k >= i;k--){
        L->data[k + 1] = L->data[k];
    }
    L->data[i] = e;
    L->length++;
    return true;
}

// 删除顺序表的第i个元素
bool DeleteList(SqList*& L,int i){
    if(i <= 0||i > L->length||L->length == 0){
        return false;
    }
    i--;                  // 逻辑序号转化为物理序号
    for(int k = i;k < L->length - 1;k++){
        L->data[k] = L->data[k + 1];
    }
    L->length--;
    return true;
}

void test(){
    SqList *L;
    ElemType arr[8] = {1.2,2.1,3.4,3.2,2.1,5.8,6.5,7.4};
    CreateList(L,arr,8);

    DispList(L);

    cout << "顺序表的长度为:" << ListLength(L) << endl;
    float e = 0;
    cout << "元素" << e << "在顺序表中的下标为:" << SearchElem(L,e) << endl;
    DispList(L);
    if(InsertList(L,0,e)){
        cout << "顺序表成功插入元素" << endl;
        DispList(L);
    }else{
        cout << "顺序表插入元素失败" << endl;
        DispList(L);
    }
    if(DeleteList(L,3)){
        cout << "顺序表成功插入元素" << endl;
        DispList(L);
    }else{
        cout << "顺序表删除元素失败" << endl;
        DispList(L);
    }

    DestoryList(L);
}