/* 思路: 因为是回路，可以直接从v出发看看能不能回到v */
#include "../ch8/AdjGraph.cpp" //包含图(邻接表)的基本运算算法
#include <vector>
void DFS0(AdjGraph &G, int w, vector<int> &visited);
bool CycleOfv(AdjGraph &G, int v) //从顶点v出发搜索有向图G中是否能找到经过顶点v的回路
{
    vector<int> visited(MAXV, 0);
    ArcNode *p = G.adjlist[v].firstarc; // p指向顶点v的第一个邻接点
    while (p != NULL)
    {
        int w = p->adjvex;   //邻接点为w
        DFS0(G, w, visited); //从w开始深度遍历找v
        if (visited[v] == 1) //如果找到v了即存在回路经过v,返回true
            return true;
        p = p->nextarc; //没找到就到下一个邻接点找
    }
    return false; //遍历结束都没找到则返回false
}
void DFS0(AdjGraph &G, int v, vector<int> &visited)
{
    // cout << "w: " << v << endl;
    visited[v] = 1;                     //置已访问标记
    ArcNode *p = G.adjlist[v].firstarc; // p指向顶点v的第一个邻接点
    while (p != NULL)
    {
        int w = p->adjvex; //邻接点为w
        if (visited[w] == 0)
            DFS0(G, w, visited);
        p = p->nextarc;
    }
}
int main()
{
    AdjGraph G;
    int n = 5, e = 7;
    int a[MAXV][MAXV] = {{0, 1, 1, 0, 0},
                         {0, 0, 0, 0, 1},
                         {0, 1, 0, 1, 0},
                         {0, 1, 0, 0, 0},
                         {0, 0, 0, 1, 0}};
    G.CreateAdjGraph(a, n, e);
    G.DispAdjGraph();
    for (int i = 0; i < n; i++)
        cout << "G中" << (CycleOfv(G, i) ? " 有 " : " 无 ") << "经过顶点" << i << "的回路" << endl;
    system("pause");
    return 0;
}