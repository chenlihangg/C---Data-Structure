#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef int KeyType;
// 二叉排序树(排序：树构建完成后，中序遍历是递增序列，满足排序的定义)
struct BSTNode{
    KeyType key;
    BSTNode *lchild,*rchild;
};

// 二叉树的插入(每次插入都是作为叶子节点插入)
BSTNode *InsertBST(BSTNode *&bt,KeyType k){
    if(bt == NULL){
        bt = new BSTNode;
        bt->key = k;
        bt->lchild = bt->rchild = NULL;
    }else{
        if(k < bt->key) bt->lchild = InsertBST(bt->lchild,k);
        else if(k > bt->key) bt->rchild = InsertBST(bt->rchild,k);
    }
    return bt;
}
BSTNode *CreateBST(KeyType a[],int length){
    BSTNode *bt = NULL;
    for(int i = 0;i < length;i++){
        bt = InsertBST(bt,a[i]);
    }
    return bt;
}

// 二叉排序树的查找
BSTNode *SearchBST(BSTNode *bt,KeyType k){
    if(bt == NULL || bt->key == k) return bt;
    else{
        if(k < bt->key) return SearchBST(bt->lchild,k);
        else return SearchBST(bt->rchild,k);
    }
}

// 二叉排序树的删除
BSTNode *DeleteBST(BSTNode *bt,KeyType k){
    if(bt == NULL) return bt;
    BSTNode *p = bt,*f = NULL;          // 利用p来查找删除节点，f作为p的双亲结点
    while(p != NULL && p->key != k){
        
        f = p;
        if(p->key < k) p = p->rchild;
        else p = p->lchild;
    }
    if(p == NULL){
        return bt;            // 没有找到待删除结点，直接返回
    } 
    if(p->lchild == NULL && p->rchild == NULL){       // 情况1，p是叶子节点，直接删除即可
        if(p == bt) bt = NULL;
        else{
            if(p == f->lchild) f->lchild = NULL;
            else f->rchild = NULL;
        } 
        delete p;
    }else if(p->rchild == NULL){                      // 情况2：p没有右子树，直接将p的左子树代替p即可
        if(f == NULL) bt = bt->lchild;
        else{
            if(p == f->lchild) f->lchild = p->lchild;
            else f->rchild = p->lchild;
        }
        delete p;
    }else if(p->lchild == NULL){                      // 情况3：p没有左子树，直接将p的右子树代替p即可
        if(f == NULL) bt = bt->rchild;
        else{
            if(p == f->lchild) f->lchild = p->rchild;
            else f->rchild = p->rchild;
        }
        delete p;
    }else{                                            // 情况4:p同时有左右子树,找到p左子树的最右结点，将其替代p即可
        BSTNode *q = p->lchild;
        f = p;                                        // f指向q的双亲结点
        while(q->rchild != NULL){
            f = q;
            q = q->rchild;
        }
        p->key = q->key;                              // 结点值替换
        if(q == f->lchild) f->lchild = q->lchild;     // 删除p结点，即情况2(p无右子树)
        else f->rchild = q->lchild;
        delete q;
    }                       
    return bt;
}

void DispBST(BSTNode *bt){
    if(bt != NULL){
        DispBST(bt->lchild);
        cout << bt->key << " ";
        DispBST(bt->rchild);
    }
}

int main(){

    KeyType arr[5] = {4,3,2,6,5};
    BSTNode *bt;
    bt = CreateBST(arr,5);
    
    // BSTNode *p;
    // p = SearchBST(bt,5);
    // cout << p->key << endl;
    

    bt = DeleteBST(bt,3);
    DispBST(bt);
    return 0;
}