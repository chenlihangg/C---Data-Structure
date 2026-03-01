#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define MaxSize 50

typedef char ElemType;
// 二叉树的二叉链存储结构
struct BTNode{
    ElemType data;         // 存储的数据
    BTNode *lchild;        // 指向左子树
    BTNode *rchild;        // 指向右子树
};

void CreateBTree(BTNode *&bt,char *exp){
    BTNode *St[MaxSize],*p;           // St是二叉链结点的顺序栈
    char ch; 
    int j = 0,top = -1,k;             // top是栈顶指针
    ch = exp[j];
    bt = NULL;                        // 初始时二叉链为空
    while(ch != '\0'){
        switch(ch){
            case '(':top++; St[top] = p; k = 1; break;
            case ')':top--; break;
            case ',':k = 2;break;
            default: {
                p = new BTNode;
                p->lchild = p->rchild = NULL;
                p->data = ch;
                if(bt == NULL) bt = p;
                else{
                    if(k == 1){
                        St[top]->lchild = p;
                    }else{
                        St[top]->rchild = p;
                    }
                }
            }

        }
        j++;
        ch = exp[j];
    }
}

void DestoryTree(BTNode *&bt){
    if(bt != NULL){
        DestoryTree(bt->lchild);
        DestoryTree(bt->rchild);
        delete bt;
    }
}

// 查找值为x的结点，然后返回其指针
BTNode* FindNode(BTNode *bt,ElemType x){
    if(bt == NULL) return NULL;
    else{
        if(bt->data == x){
            return bt;
        }else{
            BTNode *p = FindNode(bt->lchild,x);
            if(p != NULL) return p;
            else{
                return FindNode(bt->rchild,x);
            }
        }
    }
}

int BTHeight(BTNode *bt){
    if(bt == NULL) return 0;
    else{
        int lh = BTHeight(bt->lchild);
        int rh = BTHeight(bt->rchild);
        int maxh = lh < rh ? rh : lh;
        return maxh + 1;
    }
}

void DispBTree(BTNode *bt){
    if(bt != NULL){
        cout << bt->data;
        if(bt->lchild != NULL || bt->rchild != NULL){
            cout << "(";
            DispBTree(bt->lchild);
            if(bt->rchild != NULL) cout << ",";
            DispBTree(bt->rchild);
            cout << ")"; 
        }
    }
}

// 遍历：先序遍历，中序遍历和后序遍历
int CountNodes(BTNode *bt){
    if(bt == NULL) return 0;
    else{
        return CountNodes(bt->lchild) + CountNodes(bt->rchild) + 1;
    }
}

void DispLeaf(BTNode *bt){
    if(bt == NULL) return;
    else{
        if(bt->lchild == NULL && bt->rchild == NULL){
            cout << bt->data << " ";
        }else{
            DispLeaf(bt->lchild);
            DispLeaf(bt->rchild);
        }
    }
}

// 查找结点值为x的结点层次
int Level(BTNode *b,ElemType x,int h){
    if(b == NULL) return -1;
    else if(b->data == x){
        return h;
    }else{
        int height = Level(b->lchild,x,h+1);
        if(height != -1) return height;
        else return Level(b->rchild,x,h+1);
    }  
}

// 求第k层的结点个数
void KLayerCount(BTNode *bt,int b,int k,int &n){
    if(bt == NULL) return;
    else{
        if(b < k){
            KLayerCount(bt->lchild,b + 1,k,n);
            KLayerCount(bt->rchild,b + 1,k,n);
        }else if(b == k){
            n++;
        }
    }
}

// 判断两棵树的结构是否相同
bool Same(BTNode *bt1,BTNode *bt2){
    if(bt1 == NULL && bt1 == NULL) return true;
    else if(bt1 != NULL && bt2 != NULL){
        return Same(bt1->lchild,bt2->lchild) && Same(bt1->rchild,bt2->rchild);
    }else return false;
}

// 输出结点值为x的所有祖先结点
bool Ancestor(BTNode *bt,ElemType x){
    if(bt == NULL) return false;
    else if(bt->data == x) return true;
    else{
        bool judge = Ancestor(bt->lchild,x) || Ancestor(bt->rchild,x);
        if(judge){
            cout << bt->data << " ";
            return true;
        }else{
            return false;
        }
    }
}

struct SqQueue{
    BTNode *data[MaxSize];
    int front,rear;
};
void EnQueue(SqQueue *&sq,BTNode *b){
    sq->rear++;
    sq->data[sq->rear] = b;
}
void DeQueue(SqQueue *&sq,BTNode *&b){
    sq->front++;
    b = sq->data[sq->front];
}
// 层次遍历，用顺序队列实现
void LevelOrder(BTNode *b){
    BTNode *p = nullptr;
    SqQueue *qu;
    qu = new SqQueue;
    qu->rear = qu->front = -1;
    EnQueue(qu,b);
    while(qu->rear != qu->front){
        DeQueue(qu,p);
        cout << p->data << " ";
        if(p->lchild != NULL) EnQueue(qu,p->lchild);
        if(p->rchild != NULL) EnQueue(qu,p->rchild);
    }
    delete qu;
}

// 二叉树的构造(通过前序和中序/后序和中序实现)
// pre存放前序序列，in存放中序序列，n为二叉树的节点个数，返回构造好的二叉树根节点
BTNode* CreateBT1(char *pre,char *in,int n){
    BTNode *b;
    char *p;
    int k;
    if(n <= 0) return NULL;
    b = new BTNode;
    b->data = *pre;
    for(p = in;p < in + n;p++){
        if(*p == *pre) break;
    }
    k = p - in;
    b->lchild = CreateBT1(pre + 1,in,k);
    b->rchild = CreateBT1(pre + k + 1,p + 1,n - k - 1);
    return b;
}

int main(){
    char str[] = "A(B(D(,G),C(E,F))";
    BTNode *bt;
    CreateBTree(bt,str);

    // int num = 0;
    // KLayerCount(bt,1,4,num);
    // cout << num << endl;

    // DispBTree(bt);
    // DispLeaf(bt);
    
    // BTNode *bt2;
    // char str2[] = "A(B(D(,G),C(E,F))";
    // CreateBTree(bt2,str2);
    // if(Same(bt,bt2)) cout << "相似" << endl;
    // else cout << "不相似" << endl;
    // DestoryTree(bt2);

    // Ancestor(bt,'G');

    // LevelOrder(bt);
    
    char p[] = "ABDGCEF",i[] = "DGBAECF";
    BTNode *bt3 = CreateBT1(p,i,7);
    DispBTree(bt3);
    DestoryTree(bt3); 

    DestoryTree(bt);
    
    return 0;
}