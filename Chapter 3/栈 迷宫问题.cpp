#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 50
using namespace std;

// eg_2 用栈求解迷宫问题
// 二维数组定义迷宫,1表示不可走，0表示可走
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
struct Box{            // 存放某一个迷宫方块的信息
    int i,j;           // 当前方块的行号，列号
    int di;            // 走到下一相邻可走方块的方位号
};
struct SqStack{
    Box data[MaxSize];
    int top;
};
void InitStack(SqStack *&st){
    st = new SqStack;
    st->top = -1;
}
void DestoryStack(SqStack *&st){
    delete st;
}
bool EmptyStack(SqStack *&st){
    return st->top == -1;
}
bool Push(SqStack *&st,Box e){
    if(st->top >= MaxSize - 1) return false;
    st->top++;
    st->data[st->top] = e;
    return true;
}
bool Pop(SqStack*& st,Box &e){
    if(EmptyStack(st)) return false;
    e = st->data[st->top];
    st->top--;
    return true;
}
bool GetTop(SqStack *&st,Box &e){
    if(EmptyStack(st)) return false;
    e = st->data[st->top];
    return true;
}

// 求解从(xi,yi)->(xe,ye)的路径,若起点周围有可走方块，则将其入栈。然后后续循环取栈顶元素，重复该过程，知道栈顶元素为终点
bool mgPath(int xi,int yi,int xe,int ye){
    SqStack *st;
    InitStack(st);
    int i,j,di,i1,j1;
    bool find;
    Box e;
    e.i = xi; e.j = yi; e.di = -1;
    Push(st,e);
    mg[xi][yi] = -1;
    while(!EmptyStack(st)){
        GetTop(st,e);
        i = e.i; j = e.j; di = e.di;
        if(i == xe && j == ye){
            cout << "已成功找到迷宫" << endl;
            // 打印迷宫路径
            for(int p = 0;p <= st->top;p++){
                cout << "(" << st->data[p].i << "," << st->data[p].j << ")";
                if(p % 5 == 0) cout << endl;
            }
            return true;
        }
        find = false;
        while(di < 4 && !find){                   // 从目前的方块向四周寻找可行方块
            di++;                                 // 每次改变一次方向
            switch(di){
                case 0:i1 = i - 1; j1 = j; break;
                case 1:i1 = i; j1 = j + 1; break;
                case 2:i1 = i + 1; j1 = j; break;
                case 3:i1 = i; j1 = j - 1; break;
            }
            if(mg[i1][j1] == 0) find = true;
        }
        if(find){                                 // 找得到就进栈
            st->data[st->top].di = di;
            e.i = i1; e.j = j1; e.di  = -1;
            Push(st,e);                           // 将方块进入到路径栈
            mg[i1][j1] = -1;                      // 将路径上的方块状态置于不可走
        }else{                                    // 否则就退栈
            Pop(st,e);
            mg[i][j] = 0;
        }


    }
    return false;
}
void mgTest(){
    if(!mgPath(1,1,8,8)) cout << "迷宫没有路径" << endl;
}

int main(){
    mgTest();
    return 0;
}