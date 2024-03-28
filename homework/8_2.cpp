/*
思路：无序时用顺序查找法一个个比对，有序时可以利用折半法提高效率
顺序查找法 ASL(成功)=(n+1)/2=6; 折半查找法 ASL(成功)=3
*/
#include <iostream>
#include <vector>
using namespace std;
int SeqSearch(vector<int> R, int k) // 无序时用顺序查找法一个个比对
{
    int n = R.size();
    R.push_back(k); // 末尾添加一个哨兵
    int i = 0;
    while (R[i] != k)
        i++; // 从表头往后找
    if (i == n)
        return -1; // 未找到返回-1
    else
        return i; // 找到后返回其序号i
}
int BinSearch(vector<int> R, int k) // 有序时可使用拆半查找法
{
    int n = R.size();
    int low = 0, high = n - 1;
    while (low <= high) // 当前区间非空时
    {
        int mid = (low + high) / 2; // 求查找区间的中间位置
        if (k == R[mid])            // 查找成功返回其序号mid
            return mid;
        if (k < R[mid]) // 继续在R[low..mid-1]中查找
            high = mid - 1;
        else               // k>R[mid]
            low = mid + 1; // 继续在R[mid+1..high]中查找
    }
    return -1; // 当前查找区间空时返回-1
}
int main()
{
    vector<int> R1 = {2, 0, 6, 9, 5, 8, 1, 10, 3, 7, 4}; // 无序顺序表
    vector<int> R2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 有序顺序表
    cout << "k1: " << SeqSearch(R1, 6) << endl;
    cout << "k2: " << BinSearch(R2, 6) << endl;
    system("pause");
    return 0;
}