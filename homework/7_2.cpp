/* 思路: 在Dijkstra基础上改动，想找到两点之间最短路径好像还是得把其他点也算一下，减少的运算量很有限， */
#include "../ch8/MatGraph.cpp" //包含图（邻接矩阵）的基本运算算法
int DijkstraOfst(MatGraph &g, int s, int t)
{
    int dist[MAXV]; //建立dist数组
    int S[MAXV];    //建立S数组
    for (int i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[s][i]; //距离初始化
        S[i] = 0;                // S[]置空
    }
    S[s] = 1;                         //源点编号s放入S中
    int mindis, u = -1;               //临时存放U到S的最小距离和最小距离点
    for (int i = 0; i < g.n - 1; i++) //循环向S中添加n-1个顶点
    {
        mindis = INF;                 // mindis置最小长度初值
        for (int j = 0; j < g.n; j++) //选取不在S中且具有最小距离的顶点u
            if (S[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
        if (u == t) //找到s到t的最短路径了就可以直接返回，免去更远的点的计算
            return dist[t];
        S[u] = 1;                     //顶点u加入S中
        for (int j = 0; j < g.n; j++) //修改不在s中的顶点的距离
            if (S[j] == 0)
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j])
                    dist[j] = dist[u] + g.edges[u][j];
    }
}
int main()
{
    MatGraph g;
    int n = 7, e = 12;
    int A[MAXV][MAXV] = {
        {0, 4, 6, 6, INF, INF, INF},
        {INF, 0, 1, INF, 7, INF, INF},
        {INF, INF, 0, INF, 6, 4, INF},
        {INF, INF, 2, 0, INF, 5, INF},
        {INF, INF, INF, INF, 0, INF, 6},
        {INF, INF, INF, INF, 1, 0, 8},
        {INF, INF, INF, INF, INF, INF, 0}};
    g.CreateMatGraph(A, n, e);
    g.DispMatGraph();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            cout << "从顶点 " << i << " 到顶点 " << j << " 的最短路径长度为 " << DijkstraOfst(g, i, j) << endl;
    system("pause");
    return 0;
}