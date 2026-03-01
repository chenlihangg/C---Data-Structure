#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// 邻接矩阵的声明
#define MAXV 10
#define INF 10000
struct AdjMatrix{
    int edges[MAXV][MAXV];         // 邻接矩阵
    int n,e;                       // 点数和边数
};

// 邻接表的声明
struct ArcNode{                    // 边结点
    int adjvex;                    // 邻接点的编号
    ArcNode *nextarc;              // 指向下一个邻接点的指针
    int weight;                    // 该边权值
};
struct VNode{                      // 顶点结点
    ArcNode *firstarc;             // 指向第一个边界点
};
struct AdjGraph{
    VNode adjlist[MAXV];           // 头结点数组
    int n,e;                       // 点数和边数
};

// 有向图，用于邻接表的构建
int A[MAXV][MAXV] = {
    {1,0,0,0,0,1,1,1,1,1},
    {0,0,0,1,0,0,0,1,0,1},
    {0,0,0,1,0,0,0,1,0,1},
    {0,0,0,0,0,1,1,0,0,1},
    {0,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,0,0,0,0,1,1},
};

// 无向图，用于邻接矩阵(最小生成树)的构建
#define INF 10000
int B[MAXV][MAXV] = {
    {0,INF,INF,INF,1,3,4,5,6,7},
    {INF,0,INF,4,INF,INF,INF,1,INF,2},
    {INF,INF,0,2,INF,INF,INF,1,INF,4},
    {INF,4,2,0,INF,1,1,INF,INF,2},
    {1,INF,INF,INF,0,INF,INF,INF,INF,2},
    {3,INF,INF,1,3,0,INF,INF,INF,INF},
    {4,INF,INF,3,INF,INF,0,8,INF,INF},
    {5,1,1,INF,1,INF,8,0,INF,INF},
    {6,INF,INF,INF,INF,INF,INF,INF,0,1},
    {7,2,4,2,2,INF,INF,INF,1,0},
};

// 邻接矩阵的创建
void CreateMat(AdjMatrix *&M,int a[MAXV][MAXV]){
    M = new AdjMatrix;
    M->n = MAXV; M->e = 0;
    int i,j;
    for(i = 0;i < M->n;i++){
        for(j = 0;j < M->n;j++){
            M->edges[i][j] = a[i][j];
            if(a[i][j] != 0 && a[i][j] < INF) M->e++;
        }
    }
}

// 邻接表的创建
void CreateAdj(AdjGraph *&G,int a[MAXV][MAXV],int n){
    int i,j,count = 0;ArcNode *p;
    G = new AdjGraph;
    for(i = 0;i < n;i++){
        G->adjlist[i].firstarc = NULL;
    }
    for(i = 0;i < n;i++){
        for(j = n - 1;j >= 0;j--){
            if(a[i][j] != 0){
                count++;
                p = new ArcNode;
                p->adjvex = j; p->weight = a[i][j]; 
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n; G->e = count;
}

void DispAdj(AdjGraph *G){
    int i;ArcNode *p;
    for(i = 0;i < G->n;i++){
        p = G->adjlist[i].firstarc;
        while(p != NULL){
            cout << "(" << i << "," << p->adjvex << ") " << p->weight;
            p = p->nextarc;
        }
        cout << endl;
    }
}

void DestoryAdj(AdjGraph *&G){
    int i; ArcNode *pre,*p;
    for(i = 0;i < G->n;i++){
        pre = G->adjlist[i].firstarc;
        while(pre != NULL){
            p = pre->nextarc;
            delete pre;
            pre = p;
        }
    }
    delete G;
}

// 图的遍历 DFS + BFS
// DFS:从顶点v出发，递归访问每个邻接顶点，用visit[]数组记录访问状态，0表示未访问，1表示已访问。
// 特征：优先往深的地方进行遍历，当所有的邻接点都遍历完了之后再回退到上一个顶点
int visit[MAXV] = {};
void DFS(AdjGraph *&G,int v){
    ArcNode *p;
    visit[v] = 1;
    cout << v << " ";
    p = G->adjlist[v].firstarc;
    while(p != NULL){
        if(visit[p->adjvex] == 0) DFS(G,p->adjvex);
        p = p->nextarc;
    }
}

// BFS:类似于树的层次遍历，利用队列实现。将头顶点进队，然后访问该顶点的所有邻接点，并将其进队。等到邻接点访问完毕后
// 再继续出队列中的顶点，然后再重复上述操作
typedef int ElemType;
#define MaxSize 10
struct SqQueue{
    ElemType data[MaxSize];
    int front,rear;                     // 队首和队尾指针
};
void InitQueue(SqQueue *&q){
    q = new SqQueue;
    q->front = q->rear = -1; 
}

void DestoryQueue(SqQueue *&q){
    delete q;
}

bool EmptyQueue(SqQueue *&q){
    return q->rear == q->front; 
}

bool EnQueue(SqQueue *&q,ElemType e){
    if(q->rear >= MaxSize - 1) return false;
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

bool DeQueue(SqQueue *&q,ElemType &e){
    if(EmptyQueue(q)) return false;
    q->front++;
    e = q->data[q->front];
    return true;
}
void BFS(AdjGraph *&G,int v){
    int w,i; ArcNode *p;
    SqQueue *qu;
    InitQueue(qu);
    int Visit[100];
    for(i = 0;i < G->n;i++){
        Visit[i] = 0;
    }
    cout << v << " ";
    Visit[v] = 1;
    EnQueue(qu,v);
    while(!EmptyQueue(qu)){
        DeQueue(qu,w);
        p = G->adjlist[w].firstarc;
        while(p != NULL){
            if(Visit[p->adjvex] == 0){
                cout << p->adjvex << " ";
                Visit[p->adjvex] = 1;             // 访问状态更新
                EnQueue(qu,p->adjvex);            // 已访问的顶点进队列
            }
            p = p->nextarc;
        }
    }
    DestoryQueue(qu);
}


// example
// 判断两点之间是否存在简单路径
int visited[MAXV] = {};
bool ExistPath(AdjGraph *G,int u,int v){
    ArcNode *p;
    visited[u] = 1;
    if(u == v) return true;
    p = G->adjlist[u].firstarc;
    bool judge = false;
    while(p !=NULL){
        if(visited[p->adjvex] == 0){
            if(ExistPath(G,p->adjvex,v)) judge = true;
        }
        p = p->nextarc;
    }
    return judge;
}

// 输出从顶点u到顶点v的一条简单路径
void DispPath(AdjGraph *G,int u,int v,int path[],int length){
    visited[u] = 1;
    path[length++] = u;               // 将起始点加入到路径数组中
    if(u == v){
        for(int i = 0;i < length;i++){
            cout << path[i] << " ";
        }
        return;
    }
    ArcNode *p = G->adjlist[u].firstarc;
    while(p != NULL){

        if(visited[p->adjvex] == 0){
            DispPath(G,p->adjvex,v,path,length);
        }
        p = p->nextarc;
    }
}

// 输出从u到v的所有简单路径，只需增加回溯功能即可
void DispPath2(AdjGraph *G,int u,int v,int path[],int length){
    visited[u] = 1;
    path[length++] = u;
    if(u == v){
        for(int i = 0;i < length;i++){
            cout << path[i] << " ";
        }
        cout << endl; 
        visited[u] = 0;
        return;
    }
    ArcNode *p = G->adjlist[u].firstarc;
    while(p != NULL){
        if(visited[p->adjvex] == 0){
            DispPath2(G,p->adjvex,v,path,length);
        }
        p = p->nextarc;
    }
    visited[u] = 0;                        // 结束该结点的遍历之后，需要重新将其置于未访问状态，回溯功能
}

// 输出u为端点的所有简单回路
void CyclePath(AdjGraph *G,int u,int v,int path[],int length){
    visited[u] = 1;
    path[length++] = u;
    ArcNode *p = G->adjlist[u].firstarc;
    while(p != NULL){
        if(p->adjvex == v && length > 2){           // 判断是否为邻接点时无需判断visited数组，故可用于回路的判断
            for(int i = 0;i < length;i++){   
                cout << path[i] << " ";
            }
            cout << v << endl;                      // 终点的端点没有进入到path数组，需要单独输出
        }
        if(visited[p->adjvex] == 0){ 
            CyclePath(G,p->adjvex,v,path,length);
        }
        p = p->nextarc;
    }
    visited[u] = 0;
}

// 最小生成树算法：Prim与kruskal
// Prim算法，通过贪心算法，每次只将权值最小的点进入确定的点击，然后更新最小权值，从v点开始
void Prim(AdjMatrix *M,int v){
    int lowcost[MAXV],closest[MAXV];
    int mindist,i,j,k;
    for(i = 0;i < MAXV;i++){                // 初始化
        lowcost[i] = M->edges[v][i];
        closest[i] = v;
    }
    for(i = 1;i < M->n;i++){                // 确定n-1个顶点
        mindist = 1000;
        for(j = 0;j < M->n;j++){            // 找出待确认点集中权值最小的
            if(lowcost[j] != 0){            // 不在最小生成树点集中
                if(lowcost[j] < mindist){
                    k = j;
                    mindist = lowcost[j];
                }
            }
        }
        cout << "(" << k << "," << closest[k] << ")," << "权值为:" << lowcost[k];
        lowcost[k] = 0;                     // 进入最小生成树点集
        for(j = 0;j < M->n;j++){            // 更新最小权值
            if(lowcost[j] != 0){
                if(lowcost[j] > M->edges[k][j]){
                    lowcost[j] = M->edges[k][j];
                    closest[j] = k;
                }
            }
        }
    }
}

// Kruskal算法(避圈法)
struct Edge{
    int u,v;
    int w;
};
void Sort(Edge *&E,int length){
    int i,j;
    Edge temp;
    for(i = length - 1;i >= 0;i--){
        for(j = 0;j < i;j++){
            if(E[j].w > E[j + 1].w){
                temp = E[j];
                E[j] = E[j + 1];
                E[j + 1] = temp;
            }
        }
    }
}
void Kruskal(AdjMatrix *m){
    int vest[MAXV];
    Edge E[MAXV * MAXV];
    int i,j,u1,v1,sn1,sn2,k;
    k = 0;                            // E数组的下标
    for(i = 0;i < m->n;i++){
        for(j = 0;j <= i;j++){        // 注意j的范围，不要重复选到同一条边
            if(m->edges[i][j] != 0){
                E[k].u = i; E[k].v = j; E[k].w = m->edges[i][j];
                k++;
            }
        }
    }
    Edge *e = E;
    Sort(e,k);
    for(i = 0;i < m->n;i++){
        vest[i] = i;
    }
    k = 1;                  // 构造四川省的第几条边
    j = 0;                  // E的下标
    while(k < m->n){
        u1 = E[j].u; v1 = E[j].v;
        sn1 = vest[u1]; sn2 = vest[v1];
        if(sn1 != sn2){
            cout << "(" << u1 << "," << v1 << "),权值是" << E[j].w  << endl;
            k++;
            for(i = 0;i<m->n;i++){
                if(vest[i] == sn1) vest[i] = sn2;
            }
        }
        j++;
    }
}

// 最短路径 迪科斯特拉和佛洛依德算法
// 狄克斯特拉算法：单源最短路径，每次找权值最短的边，然后将对应点进入路径，然后更新权值最小边
void Dijkstra(AdjMatrix *m,int v){
    int dist[MAXV],path[MAXV];         // dist存储源点到各点距离，然后path存储v到该点的最短路径的前一个点标号
    int S[MAXV];                       // s[i] = 1表示顶点i在最短路径的顶点集中，反之为0
    int mindist,i,j,u;
    for(i = 0;i < m->n;i++){           // 初始化
        dist[i] = m->edges[v][i];
        S[i] = 0;
        if(dist[i] < INF) path[i] = v;
        else path[i] = -1;
    }
    S[v] = 1;path[v] = 0;
    for(i = 1;i < m->n;i++){           // 求出到剩下的n-1个顶点的最短路径
        mindist = INF;
        for(j = 0;j < m->n;j++){       // 找权值最小的结点
            if(S[j] == 0){
                if(dist[j] < mindist){
                    mindist = dist[j];
                    u = j;
                }
            }
        }
        S[u] = 1;                      // 权值最小的结点进入到最短路径
        for(j = 0;j < m->n;j++){
            if(S[j] == 0){             
                // 更新最短路径
                if(m->edges[u][j] < INF  && dist[j] > dist[u] + m->edges[u][j]){
                    dist[j] = dist[u] + m->edges[u][j];
                    path[j] = u;
                }
            }
        }
    }
    for(i = 0;i < MAXV;i++){
        cout << dist[i] << endl;
    }
    // 输出最短路径
    int Dispath[MAXV],length;
    for(i = 0;i < m->n;i++){     // 对每一个终点进行遍历
        if(i == v) continue;     // 起点无需输出
        for(j = 0;j < MAXV;j++) Dispath[j] = 0;
        length = 0;                                       // 对输出的路径数组初始化
        Dispath[length++] = i;
        u = path[i];
        while(u != v){                                    // 还没迭代到起点时循环
            Dispath[length++] = u;
            u = path[u];
        }
        Dispath[length++] = v;
        for(j = length - 1;j >= 0;j--){
            cout << Dispath[j];
            if(j != 0) cout << "->";
        }
        cout << endl;
    }
}

// Floyd算法：多源最短路径算法
// 每次多考虑一个顶点，然后分析变化前后各点的距离及路径变化，并作出相应的更新
void Floyd(AdjMatrix *m){
    int A[MAXV][MAXV],path[MAXV][MAXV];     // A[i][j]表示从i到j的最短距离,path[i][j]表示从i到j的最短距离的前一个顶点
    int i,j,k;
    for(i = 0;i < m->n;i++){                                     // 数据初始化
        for(j = 0;j <m->n;j++){
            A[i][j] = m->edges[i][j];
            if(A[i][j] != 0 && A[i][j] < INF) path[i][j] = i;
            else path[i][j] = -1;
        }
    }
    for(k = 0;k < m->n;k++){                // 每次多考虑一个顶点
        for(i = 0;i < m->n;i++){
            for(j = 0;j < m->n;j++){
                if(A[i][j] > A[i][k] + A[k][j]){       // 若添加后的顶点后，最短距离需要更新
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }         
            }
        }
    }
    
}

int main(){
    // AdjGraph *g;
    // CreateAdj(g,A,MAXV);
    // DispAdj(g);
    // DFS(g,0);
    // BFS(g,0);
    // if(ExistPath(g,0,3)) cout << "存在简单路径" << endl;
    // else cout << "不存在" << endl;

    // int path[MAXV];
    // for(int i = 0;i < MAXV;i++){
    //     path[i] = 0;
    // }
    // DispPath(g,0,3,path,0);
    // DispPath2(g,0,3,path,0);
    // CyclePath(g,0,0,path,0);
    // DestoryAdj(g);


    AdjMatrix *m;
    CreateMat(m,B);
    
    // Prim(m,0);
    // Kruskal(m);
    
    Dijkstra(m,0);
    delete m;

    return 0;
}