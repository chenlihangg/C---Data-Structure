#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// 堆排序：将数组视作完全二叉树的顺序存储结构，利用完全二叉树中双亲结点和孩子节点的位置关系在无序区中选择关键字最大的元素
// 堆满足性质：父母<=孩子(小根堆) or 父母>=孩子(大根堆)。
// 筛选操作：大者上浮，小者下沉
typedef int KeyType;
void sift(KeyType a[],int low,int high){
    int i = low,j = 2*i;   // j是i的左孩子，此为完全二叉树顺序存储结构的结论
    KeyType tmp = a[i];
    while(j <= high){
        if(j < high && a[j] < a[j+1]){        // 判断大孩子是否为右孩子
            j++;
        }
        if(tmp < a[j]){                       // 判断是否需要将根节点下沉
            a[i] = a[j];
            i = j;
            j = 2 * i;                        // 交换后大根堆可能被破坏，因此需要继续迭代，直到到达叶子节点
        }else break;                          // 无需下沉时结束循环
    }
    a[i] = tmp;
}
void HeapSort(KeyType a[],int n){
    int i; KeyType tmp;
    for(i = n/2;i >= 1;i--){                // 初始化建立初始堆，从[n/2]开始到1进行筛选(分支节点)
        sift(a,i,n);                    
    }
    
    for(i = n;i >= 2;i--){
        tmp = a[1];                         // 当大根堆建立好后，第一个元素，即根节点是最大值，将其与最后面的元素交换
        a[1] = a[i];                        // 然后再重新构建好大根堆(进行筛选操作，范围减一即可)，然后继续循环 
        a[i] = tmp;
        sift(a,1,i - 1);
    }
}

int main(){


    KeyType arr[6] = {0,3,2,4,1,7};
    HeapSort(arr,5);
    for(int i = 1;i < 6;i++){
        cout << arr[i] << endl;
    }
    return 0;
}