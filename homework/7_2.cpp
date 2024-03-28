/* ˼·: ��Dijkstra�����ϸĶ������ҵ�����֮�����·�������ǵð�������Ҳ��һ�£����ٵ������������ޣ� */
#include "../ch8/MatGraph.cpp" //����ͼ���ڽӾ��󣩵Ļ��������㷨
int DijkstraOfst(MatGraph &g, int s, int t)
{
    int dist[MAXV]; //����dist����
    int S[MAXV];    //����S����
    for (int i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[s][i]; //�����ʼ��
        S[i] = 0;                // S[]�ÿ�
    }
    S[s] = 1;                         //Դ����s����S��
    int mindis, u = -1;               //��ʱ���U��S����С�������С�����
    for (int i = 0; i < g.n - 1; i++) //ѭ����S�����n-1������
    {
        mindis = INF;                 // mindis����С���ȳ�ֵ
        for (int j = 0; j < g.n; j++) //ѡȡ����S���Ҿ�����С����Ķ���u
            if (S[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
        if (u == t) //�ҵ�s��t�����·���˾Ϳ���ֱ�ӷ��أ���ȥ��Զ�ĵ�ļ���
            return dist[t];
        S[u] = 1;                     //����u����S��
        for (int j = 0; j < g.n; j++) //�޸Ĳ���s�еĶ���ľ���
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
            cout << "�Ӷ��� " << i << " ������ " << j << " �����·������Ϊ " << DijkstraOfst(g, i, j) << endl;
    system("pause");
    return 0;
}