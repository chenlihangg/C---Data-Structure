#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef int KeyType;
// 选择排序,每次找到最小的一个，然后和首个元素交换
void SelectSort(KeyType a[],int n){
    int i,j,k;
    KeyType tmp;
    for(i = 0;i < n;i++){
        k = i;                        // k记录最小元素的下标
        for(j = i + 1;j < n;j++){
            if(a[j] < a[k]) k = j;
        }
        if(k != i){
            tmp = a[i];
            a[i] = a[k];
            a[k] = tmp;
        }
    }
}

int main(){
    KeyType arr[5] = {3,2,5,6,1};
    SelectSort(arr,5);
    for(int i = 0;i < 5;i++){
        cout << arr[i];
    }
    return 0;
}