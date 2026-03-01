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
    {1,1,0,0,0,0,0,1,0,1},
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

// 输出迷宫的所有路径，并求第一条最短路径及其长度
bool MgPath(int xi,int yi,int xe,int ye){
    int i,j,i1,j1,di,count = 0,minnum = 65,minorder = 0;           // 记录路径的个数
    bool find;
    SqStack *st;
    InitStack(st);
    Box e;
    e.i = xi; e.j = yi;e.di = -1;
    Push(st,e);
    while(!EmptyStack(st)){
        GetTop(st,e);
        i = e.i; j = e.j; di = e.di;
        if(i == xe && j == ye){
            count++;
            cout << "这是第" << count << "条路径" << endl;
            if(minnum > st->top + 1){
                minnum = st->top + 1;
                minorder = count;
            }
            for(int p = 0;p <= st->top;p++){
                cout << "(" << st->data[p].i << "," << st->data[p].j << ")";
                if((p + 1) % 5 == 0) cout << endl;
            }
            cout << endl;
        }
        find = false;
        while(di < 4 && !find){
            di++;                   // 每次调整一次方向
            switch(di){
                case 0:i1 = i - 1; j1 = j; break;
                case 1:i1 = i; j1 = j + 1; break;
                case 2:i1 = i + 1; j1 = j; break;
                case 3:i1 = i; j1 = j - 1; break;
            }
            if(mg[i1][j1] == 0) find = true;
        }
        if(find){
            st->data[st->top].di = di;
            e.i = i1; e.j = j1; e.di = -1; 
            Push(st,e);
            mg[i1][j1] = -1;
        }else{
            Pop(st,e);
            mg[i][j] = 0;
        }


    }
    
    DestoryStack(st);
    if(count > 0){
        cout << "最短路径是第" << minorder << "条，长度为" << minnum << endl;
        return true;
    }else{
        return false;
    }
}


int main(){

    if(!MgPath(1,1,8,8)) cout << "该迷宫没有路径" << endl;

    return 0;
}