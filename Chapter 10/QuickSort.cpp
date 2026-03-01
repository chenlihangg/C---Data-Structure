#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef int KeyType;
// 快速排序:每次划分将第一个元素作为基准，然后将小于基准的元素移到基准前面，大于的元素移到基准后面，然后递归分割后的子表
int partition(KeyType R[],int s,int t){  // 对R[S]到R[t]中的元素进行划分
    int i = s,j = t;
    KeyType base = R[i];                 // 取第一个元素作为基准
    while(i < j){
        while(i < j && R[j] >= base) j--;      // 找到小于基准的
        if(i < j){
            R[i] = R[j];
            i++;
        }
        while(i < j && R[i] <= base) i++;       // 找到大于基准的
        if(i < j){
            R[j] = R[i];
            j--;
        }
    }
    R[i] = base;
    return i;
}
void QuickSort(KeyType R[],int s,int t){
    int i;
    if(s < t){
        i = partition(R,s,t);
        QuickSort(R,s,i-1);
        QuickSort(R,i+1,t);
    }
}

int main(){

    KeyType arr[5] = {3,2,5,6,1};
    QuickSort(arr,0,4);
    for(int i = 0;i < 5;i++){
        cout << arr[i];
    }

    return 0;
}