#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef int KeyType;
// 归并排序：将数组切分为若干组，每两组有序表组合并成一组。然后不断归并
// 将两个有序表合并为一个有序表
void Merge(KeyType a[],int low,int mid,int high){
    KeyType *r1;
    int i = low,j = mid + 1,k = 0;
    r1 = new KeyType[high - low + 1];
    while(i <= mid && j <= high){
        if(a[i] < a[j]){
            r1[k] = a[i];
            k++; i++;
        }else{
            r1[k] = a[j];
            k++; j++;
        }
    }
    while(i <= mid){
        r1[k] = a[i];
        k++; i++;
    }
    while(j <= high){
        r1[k] = a[j];
        j++; k++;
    }
    for(k = 0,i = low;i <= high;i++,k++){
        a[i] = r1[k];
    }
    delete []r1;
}

// 将数组按照length长度进行分割，然后对相邻的子数组进行合并
void MergePass(KeyType a[],int length,int n){
    int i;
    for(i = 0;i + 2 * length - 1 < n;i = i + 2 * length){
        Merge(a,i,i + length - 1,i + 2 * length - 1);
    }
    if(i + length - 1 < n - 1)
        Merge(a,i,i + length - 1,n - 1);
}

// 归并排序算法
void MergeSort(KeyType a[],int n){
    int length;
    for(length = 1;length < n;length *= 2){
        MergePass(a,length,n);
    }
}

int main(){

    KeyType arr[5] = {3,2,5,6,1};
    MergeSort(arr,5);
    for(int i = 0;i < 5;i++){
        cout << arr[i];
    }
    return 0;
}