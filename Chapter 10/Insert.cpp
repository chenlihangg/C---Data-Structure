#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// 插入排序
typedef int KeyType;

// 直接插入排序 将无序区的元素移入有序区，使扩充后的有序区仍然保持有序，迭代到无序区结束
void InsertSort(KeyType R[],int n){
    int i,j; KeyType tmp;
    for(i = 1;i < n;i++){            // 从第二个元素开始，逐步缩小无序区
        if(R[i] < R[i - 1]){         // 当出现反序时,即无序区的首元素
            tmp = R[i];
            j = i - 1;
            do{
                R[j + 1] = R[j];
                j--;
            }while(j >= 0 && R[j] > tmp);    // 将大于首元素的有序区元素全部后移
            R[j + 1] = tmp;
        }
    }
}

// 折半插入排序 可以通过折半的方式搜索插入位置，相比直接插入排序略微提升了效率
void BinInsertSort(KeyType R[],int n){
    int i,j,low,high,mid;
    KeyType tmp;
    for(i = 1;i < n;i++){
        if(R[i] < R[i - 1]){              // 遇到无序区的首个元素
            low = 0; high = i - 1; 
            tmp = R[i];
            while(low <= high){
                mid = (low + high) / 2;
                if(R[mid] > tmp) high = mid - 1;
                else low = mid + 1;
            }
            for(j = i - 1;j >= high + 1;j--){
                R[j + 1] = R[j];
            }
            R[high + 1] = tmp;
        }
    }
}

// 希尔排序：将距离为d的元素分为一组，然后进行插入排序。然后逐渐减小距离d直到为1，实现全局有序
void ShellSort(KeyType R[],int n){
    int i,j,d;
    KeyType tmp;
    d = n/2;                     
    while(d > 0){
        for(i = d;i < n;i++){             // 对所有组进行插入排序
            tmp = R[i];
            j = i - d; 
            while(j >= 0 && tmp < R[j]){        // 出现逆序
                R[j + d] = R[j];
                j = j - d;
            }
            R[j + d] = tmp;
        }
        d = d/2;
    } 
}

int main(){
    KeyType arr[5] = {3,2,4,1,7};
    // InsertSort(arr,5);
    // BinInsertSort(arr,5);
    ShellSort(arr,5);
    for(int i = 0;i < 5;i++){
        cout << arr[i] << endl;
    }

    return 0;
}