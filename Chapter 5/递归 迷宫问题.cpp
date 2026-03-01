#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 50
using namespace std;

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

struct Box{
    int i,j;
};

struct Path{
    Box data[MaxSize];
    int length;
};

void MgPath(int xi,int yi,int xe,int ye,Path p){
    if(xi == xe && yi == ye){                         // 找到路径
        cout << "已成功找到路径" << endl;
        p.data[p.length].i = xi;
        p.data[p.length].j = yi;
        p.length++;
        for(int m = 0;m < p.length;m++){
            cout << "(" << p.data[m].i << "," << p.data[m].j << ")";
        }
        cout << endl;
    }else{
        mg[xi][yi] = -1;                  // 起点置为不可走状态
        p.data[p.length].i = xi;
        p.data[p.length].j = yi;
        p.length++;
        int i,j,di;
        for(di = 0;di < 4;di++){          // 从(xi,yi)向四周寻找可走方块
            switch(di){
                case 0:i=xi-1;j=yi;break;
                case 1:i=xi;j=yi+1;break;
                case 2:i=xi+1;j=yi;break;
                case 3:i=xi;j=yi-1;break;
            }
            if(mg[i][j] == 0){            // 若找到可走方块
                MgPath(i,j,xe,ye,p);
                
            }
        }
        mg[xi][yi] = 0;
        p.length--;
    }
}

int main(){
    Path pa;
    pa.length = 0;
    MgPath(1,1,8,8,pa);
    return 0;
}