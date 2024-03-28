/*思路：在基本的简单选择排序的基础上作出改动，只选出从小到大前m个*/
#include <iostream>
#include <vector>
using namespace std;
void disp(vector<int> &R, int low, int high)
{
    for (int i = low; i <= high; i++)
        cout << R[i] << " ";
    cout << endl;
}
void SelectMinm(vector<int> &R, int n, int m)
{
    if (m < 0 || m >= n) // m不符合要求则报错
    {
        cout << "false: m 不符合 \"0 < m << n\" " << endl;
        return;
    }
    for (int i = 0; i < m; i++) // 做第i趟排序
    {
        int minj = i;
        for (int j = i + 1; j < n; j++) // 在当前无序区R[i..n-1]中选最小元素R[minj]
            if (R[j] < R[minj])
                minj = j;        // minj记下目前找到的最小元素的位置
        if (minj != i)           // 若R[minj]不是无序区首元素
            swap(R[i], R[minj]); // 交换R[i]和R[minj]
    }
    cout << "从小到大顺序前" << m << "个:" << endl;
    disp(R, 0, m - 1);
}
int main()
{
    vector<int> R = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = R.size(), m = 5;
    cout << "原序列:" << endl;
    disp(R, 0, n - 1);
    SelectMinm(R, n, m);
    system("pause");
    return 0;
}