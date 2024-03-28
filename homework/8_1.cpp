/*
思路：两序列长度一样，设置n存放长度，从小到大遍历到中位数的位置即第n个数
时间复杂度为O(n)，空间复杂度为O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
int MidOfTwo(vector<int> a, vector<int> b)
{
    int n = a.size();                 // 两序列等长，共用一个长度，同时长度即为中位数序号
    int i = 0, j = 0;                 // 存放当前遍历位置
    for (int num = 1; num < n; num++) // 循环到中位数前一个
    {
        if (a[i] < b[j])
            i++;
        else
            j++;
    }
    if (a[i] < b[j]) // 判断并返回中位数
        return a[i];
    else
        return b[j];
}
int main()
{
    vector<int> s1 = {11, 13, 15, 17, 19};
    vector<int> s2 = {2, 4, 6, 8, 20};
    cout << MidOfTwo(s1, s2) << endl; // 输出中位数
    system("pause");
    return 0;
}