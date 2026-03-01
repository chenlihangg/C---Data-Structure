#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define MaxSize 10
int arr[MaxSize][MaxSize] = {};

// 输出一个n*n的螺旋方阵，以顺时针为方向，从外到内旋转
void Rotation(int n){
    int nums = 1,di = 0;    
    int i = 0,j = 0;            // 当前所填的方块的行列标号                
    while(nums <= n*n){         // 对矩阵进行填数字
        arr[i][j] = nums;       // 当前位置填入对应的数字
        switch(di){
            case 0: j++; break;          // 向右
            case 1: i++; break;          // 向下
            case 2: j--; break;          // 向左
            case 3: i--; break;          // 向上
        }
        if(i >= n || j >= n || j < 0 || arr[i][j] != 0){
            di = (di + 1) % 4;
            switch(di){             // 对位置做一个修正
            case 0: i++; j++; break;          
            case 1: i++; j--; break;          
            case 2: i--; j--; break;          
            case 3: i--; j++; break;          
            }
        }
        nums++;
    }

    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    Rotation(8);
    return 0;
}