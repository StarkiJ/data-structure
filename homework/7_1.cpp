/* ˼·: ��Ϊ�ǻ�·������ֱ�Ӵ�v���������ܲ��ܻص�v */
#include "../ch8/AdjGraph.cpp" //����ͼ(�ڽӱ�)�Ļ��������㷨
#include <vector>
void DFS0(AdjGraph &G, int w, vector<int> &visited);
bool CycleOfv(AdjGraph &G, int v) //�Ӷ���v������������ͼG���Ƿ����ҵ���������v�Ļ�·
{
    vector<int> visited(MAXV, 0);
    ArcNode *p = G.adjlist[v].firstarc; // pָ�򶥵�v�ĵ�һ���ڽӵ�
    while (p != NULL)
    {
        int w = p->adjvex;   //�ڽӵ�Ϊw
        DFS0(G, w, visited); //��w��ʼ��ȱ�����v
        if (visited[v] == 1) //����ҵ�v�˼����ڻ�·����v,����true
            return true;
        p = p->nextarc; //û�ҵ��͵���һ���ڽӵ���
    }
    return false; //����������û�ҵ��򷵻�false
}
void DFS0(AdjGraph &G, int v, vector<int> &visited)
{
    // cout << "w: " << v << endl;
    visited[v] = 1;                     //���ѷ��ʱ��
    ArcNode *p = G.adjlist[v].firstarc; // pָ�򶥵�v�ĵ�һ���ڽӵ�
    while (p != NULL)
    {
        int w = p->adjvex; //�ڽӵ�Ϊw
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
        cout << "G��" << (CycleOfv(G, i) ? " �� " : " �� ") << "��������" << i << "�Ļ�·" << endl;
    system("pause");
    return 0;
}