/*思路：添加一个顺序表用于存储查找序列，每次比对时将比对数加入查找序列中，找到则输出*/
#include <iostream>
#include <vector>
using namespace std;
void ShowVector(vector<int> s) // 输出顺序表内元素
{
    int len = s.size();
    for (int i = 0; i < len; i++)
        cout << s[i] << " ";
    cout << endl;
}
void OutBinSearch(vector<int> R, int k) // 以基本折半查找算法为基础给出查找序列
{
    vector<int> s; // 存储查找序列
    int n = R.size();
    int low = 0, high = n - 1;
    while (low <= high) // 当前区间非空时
    {
        int mid = (low + high) / 2; // 求查找区间的中间位置
        if (k == R[mid])            // 查找成功返回其序号mid
        {
            s.push_back(k);
            ShowVector(s);
            return;
        }
        s.push_back(R[mid]);
        if (k < R[mid]) // 继续在R[low..mid-1]中查找
            high = mid - 1;
        else               // k>R[mid]
            low = mid + 1; // 继续在R[mid+1..high]中查找
    }
    cout << "Not Find" << endl; // 循环结束说明没有找到
}
int main()
{
    vector<int> R = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 有序顺序表
    OutBinSearch(R, 1);
    system("pause");
    return 0;
}