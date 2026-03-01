#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef char ElemType;

struct GLNode{
    int tag;                                  // 标示结点状态，0为原子，1为子表
    union{
        ElemType data;
        GLNode* sublist;
    }val;
    GLNode *link;
};

// 利用字符串构造出广义表
void Create(GLNode *&L,char *&exp){
    if(*exp != '\0'){                         // 当字符非空的时候进行处理
        if(*exp == '('){                      // 处理子表内容
            L = new GLNode;
            L->tag = 1;
            exp++;
            Create(L->val.sublist,exp);       // 递归处理子表
            Create(L->link,exp);              // 继续处理其兄弟结点
        }else if(*exp == ')'){                // 说明子表的内容就结束
            L = NULL;
            exp++;
        }else if(*exp == ','){                               
            exp++;
            Create(L,exp);
        }else{
            L = new GLNode;                   // 处理原子内容
            L->tag = 0;
            L->val.data = *exp;
            exp++;
            Create(L->link,exp);
        }
    }else{                                    // 无字符的时候，结点为空，并结束构建
        L = NULL; 
    }
}

int GLLength(GLNode *L){
    GLNode *p = L->val.sublist;
    int length = 0;
    while(p != NULL){
        length++;
        p = p->link;
    }
    return length;
}

// 求广义表的深度，原子为0，子表为该子表的所有子表的深度最大值加一
int GLDepth(GLNode *&L){
    GLNode *g;
    if(L->tag == 0) return 0;             // 原子
    int maxd = 0,dep;
    g = L->val.sublist;
    if(g == NULL) return 1;               // 空表
    while(g != NULL){                     // 子表
        dep = GLDepth(g);
        if(dep > maxd) maxd = dep;
        g = g->link;
    }
    return maxd + 1;
}

void Disp(GLNode *L){
    if(L != NULL){
        if(L->tag == 0){
            cout << L->val.data; 
            return;
        }                                                     // 原子
        GLNode *g = L->val.sublist;                           // 子表
        cout << "(";
        while(g != NULL){
            Disp(g);
            if(g->link != NULL) cout << ",";
            g = g->link;           
        }
        cout << ")";
    }
}

int Count(GLNode *L){
    int count = 0;
    GLNode *g = L->val.sublist;
    while(g != NULL){
        if(g->tag == 0) count++;
        else count += Count(g);
        g = g->link;
    }
    return count;
}

int main(){
    char e[] = "(a,(b,(c)),e,f,(g,h),((())))";
    char *p = e;
    GLNode *L;
    Create(L,p);
    cout << Count(L) << endl;
    Disp(L);
    return 0;
}