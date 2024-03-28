/*
author: ZhuoXin Jiang
language: c++
time: Dec. 13th, 2022
最少布线（图）:使用Kruskal算法
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge // 边向量元素类型
{
    int num;                           // 结果要求输出编号,设置编号
    int u;                             // 边的起始顶点
    int v;                             // 边的终止顶点
    int w;                             // 边的权值
    Edge(int num, int u, int v, int w) // 构造函数
    {
        this->num = num;
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator<(const Edge &s) const // 重载<运算符
    {
        return w < s.w; // 用于按w递增排序
    }
};

void Kruskal(vector<Edge> E, int n, int e) // Kruskal算法输出最小生成树
{
    int num = 0;              // 铺设光缆的最小用料数
    int ans[n];               // 需要铺设的边的id
    int vset[n];              // 建立数组vset
    sort(E.begin(), E.end()); // 对E按权值递增排序
    for (int i = 0; i < n; i++)
        vset[i] = i; // 初始化辅助数组
    int k = 1;       // k表示当前构造生成树的第几条边,初值为1
    int j = 0;       // E中边的下标,初值为0
    while (k < n)    // 生成的边数小于n时循环
    {
        int u1 = E[j].u;
        int v1 = E[j].v; // 取一条边的起始和终止顶点
        int sn1 = vset[u1];
        int sn2 = vset[v1]; // 分别得到两个顶点所属的集合编号
        if (sn1 != sn2)     // 两顶点属于不同的集合,该边是最小生成树的一条边
        {
            num += E[j].w;
            ans[k] = E[j].num;          // 存入答案边
            k++;                        // 生成边数增1
            for (int i = 0; i < n; i++) // 两个集合统一编号
                if (vset[i] == sn2)     // 集合编号为sn2的改为sn1
                    vset[i] = sn1;
        }
        j++; // 扫描下一条边
    }
    cout << num << endl;
    sort(ans + 1, ans + n);
    for (int i = 1; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> E;
    int num = 0, u, v, w;
    while (num < e)
    {
        cin >> num >> u >> v >> w;
        E.push_back(Edge(num, u, v, w));
    }
    Kruskal(E, n, e);
    system("pause");
    return 0;
}