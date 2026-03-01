#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 50
using namespace std;

typedef string ElemType;

struct SqQueue{
    ElemType data[MaxSize];
    int front,rear;                     // 队首和队尾指针
};

void InitQueue(SqQueue *&q){
    q = new SqQueue;
    q->front = q->rear = -1; 
}

void DestoryQueue(SqQueue *&q){
    delete q;
}

bool EmptyQueue(SqQueue *&q){
    return q->rear == q->front; 
}

bool EnQueue(SqQueue *&q,ElemType e){
    if(q->rear >= MaxSize - 1) return false;
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

bool DeQueue(SqQueue *&q,ElemType &e){
    if(EmptyQueue(q)) return false;
    q->front++;
    e = q->data[q->front];
    return true;
}

void Display(SqQueue *&q){
    for(int i = q->front + 1;i <= q->rear;i++){
        cout << q->data[i] <<  " ";
    }
}

// void test(){
//     SqQueue *q;
//     InitQueue(q);
//     ElemType arr[] = {1,3,2,4,5};
//     for(int i = 0;i <5;i++){
//         EnQueue(q,arr[i]);
//     }
//     Display(q);
//     ElemType e;
//     DeQueue(q,e);
//     Display(q); cout << e;
//     Destory(q);
// }