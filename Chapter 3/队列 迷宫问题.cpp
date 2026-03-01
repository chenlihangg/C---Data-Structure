#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 50
using namespace std;

struct Box{
    int i,j;
    int pre;             // 本路径中上一个方块在队列中的下标，以此实现回溯来找到路径
};

struct SqQueue{
    Box data[MaxSize];
    int front,rear;
};

int mg[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

void InitQueue(SqQueue *&q){
    q = new SqQueue;
    q->front = q->rear = -1; 
}

void Destory(SqQueue *&q){
    delete q;
}

bool EmptyQueue(SqQueue *&q){
    return q->rear == q->front; 
}

bool EnQueue(SqQueue *&q,Box e){
    if(q->rear >= MaxSize - 1) return false;
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

bool DeQueue(SqQueue *&q,Box &e){
    if(EmptyQueue(q)) return false;
    q->front++;
    e = q->data[q->front];
    return true;
}

// 求解从(xi,yi)->(xe,ye)的路径，若方块可走，则入队。否则不管。（无需做退队处理）
bool MgPath(int xi,int yi,int xe,int ye){
    SqQueue *q;
    InitQueue(q);
    Box e; e.i = xi; e.j = yi; e.pre = -1;
    int i,j,i1,j1,di;
    EnQueue(q,e);
    mg[xi][yi] = -1;
    while(!EmptyQueue(q)){
        DeQueue(q,e);
        i = e.i; j = e.j;
        if(i == xe && j == ye){
            cout << "已成功找到路径" << endl;
            // 打印出路径
            int n = q->front;
            while(n != -1){
                cout << "(" << q->data[n].i << "," << q->data[n].j << ")" << endl;
                n = q->data[n].pre;
            }
            return true;
        }
        for(di = 0;di < 4;di++){
            switch(di){
                case 0:i1 = i - 1;j1 = j;break;
                case 1:i1 = i;j1 = j + 1;break;
                case 2:i1 = i + 1;j1 = j;break;
                case 3:i1 = i;j1 = j - 1;break;
            }
            if(mg[i1][j1] == 0){
                e.i = i1; e.j = j1; e.pre = q->front;
                EnQueue(q,e);
                mg[i1][j1] = -1;
            }
        }
    }
   

    Destory(q);
    return false;

    
}


int main(){
    if(!MgPath(1,1,8,8)){
        cout << "该迷宫无路径" << endl;
    }
    return 0;
}