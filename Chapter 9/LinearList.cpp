#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// 线性表的查找
typedef int KeyType;
struct RecType{
    KeyType key;            // 关键字
};

// 顺序表的查找，在长度为n的顺序表中寻找关键字为k的元素
int SeqSearch(RecType R[],int n,KeyType k){
    int i = 0;
    while(i < n && R[i].key != k){
        i++;
    }
    if(i >= n) return 0;
    else return i + 1;
}

// 折半查找，要求顺序表为递增有序表
int BinSearch(RecType R[],int n,KeyType k){
    int low = 0,high = n-1,mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(R[mid].key == k) return mid + 1;
        else if(R[mid].key < k) low = mid + 1;
        else high = mid - 1;
    }
    return 0;        // 未查找到
}

// 分块查找:要求分块有序
// 索引数组声明：存储第i快中的最大关键字及该块在表R中的起始下标,总共有b块
struct IdxType{
    KeyType key;            // 关键字
    int link;               // 指向对应块的起始下标
};
int IdxSearch(IdxType I[],int b,RecType R[],int n,KeyType k){
    int s = (n + b - 1) / b;            // s为每块中的元素个数，为[n/b];
    int low = 0,high = b - 1,mid,i;
    while(low <= high){                 // 采用折半查找，使得high+1停留在第一个比k大的块上
        mid = (low + high) / 2;
        if(I[mid].key >= k) high = mid - 1;
        else low = mid + 1;
    }
    i= I[high + 1].link;
    while(i <= I[high+1].link + s - 1 && R[i].key != k){
        i++;
    }
    if(i >= I[high + 1].link + s){
        return 0;
    }else return i + 1; 
}



int main(){

    RecType a[5];
    int arr[5] = {1,4,7,8,12};
    for(int i = 0;i < 5;i++){
        a[i].key = arr[i];
    }
    // cout << SeqSearch(a,5,2);
    cout << BinSearch(a,5,12);
    return 0;
}