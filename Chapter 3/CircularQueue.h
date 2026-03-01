#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 50
using namespace std;

typedef float ElemType;

// 定义循环队列
struct CirQueue{
    ElemType data[MaxSize];
    int front,rear;
};

void InitQueue(CirQueue *&q){
    q = new CirQueue;
    q->front = q->rear = 0;             // 注意设置为0，而不是-1
}

void DestoryQueue(CirQueue *&q){
    delete q;
}

bool EmptyQueue(CirQueue *&q){
    return q->front == q->rear;
}

bool EnQueue(CirQueue *&q,ElemType e){
    if((q->rear + 1) % MaxSize == q->front) return false;
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

bool DeQueue(CirQueue *&q,ElemType &e){
    if(EmptyQueue(q)) return false;
    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}