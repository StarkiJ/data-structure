/*
author: ZhuoXin Jiang
language: c++
time: Dec. 11th, 2022
*/
#include <iostream>
#include <vector>
using namespace std;
int LargestSubmatrix(vector<vector<int>> &a, int m, int n, int x, int y)
{
    // 暴力破解太蠢了,xy较大时会有大量重复运算,重建一个数组简化运算
    int b[m + 1][n + 1];         // b[i][j]存储左上角所有元素和,为了避免i-x和j-y超出,左上边加一条0
    int ans = 0;                 // 存储最大值即答案
    for (int j = 0; j <= n; j++) // 第一行边界外元素
        b[0][j] = 0;
    for (int i = 1; i <= m; i++) // 处理剩下的元素并找出最大子矩阵
    {
        b[i][0] = 0; // 第一列边界外元素
        for (int j = 1; j <= n; j++)
        {
            // a比b小一条记得-1
            b[i][j] = a[i - 1][j - 1] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            if (i >= x && j >= y) // 达到可以取大小为x,y的子矩阵时比较
                ans = max(ans, b[i][j] - b[i][j - y] - b[i - x][j] + b[i - x][j - y]);
        }
    }
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    vector<vector<int>> a;
    for (int i = 0; i < m; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            tmp.push_back(k);
        }
        a.push_back(tmp);
    }
    cout << LargestSubmatrix(a, m, n, x, y) << endl;
    fclose(stdin);
    freopen("CON", "r", stdin);
    system("pause");
    return 0;
}