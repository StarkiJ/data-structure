/*思路：利用堆排序求得前k个最大数，从小到大输出*/
#include <iostream>
#include <vector>
using namespace std;
void disp(vector<int> &R, int low, int high)
{
    for (int i = low; i <= high; i++)
        cout << R[i] << " ";
    cout << endl;
}
void siftDown(vector<int> &R, int low, int high) // R[low..high]的自顶向下筛选
{
    int i = low;
    int j = 2 * i + 1; // R[j]是R[i]的左孩子
    int tmp = R[i];    // tmp临时保存根结点
    while (j <= high)  // 只对R[low..high]的元素进行筛选
    {
        if (j < high && R[j] < R[j + 1])
            j++;        // 若右孩子较大,把j指向右孩子
        if (tmp < R[j]) // tmp的孩子较大
        {
            R[i] = R[j]; // 将R[j]调整到双亲位置上
            i = j;
            j = 2 * i + 1; // 修改i和j值,以便继续向下筛选
        }
        else
            break; // 若孩子较小，则筛选结束
    }
    R[i] = tmp; // 原根结点放入最终位置
}
void HeapSortGetMaxk(vector<int> &R, int n, int k) // 堆排序
{
    for (int i = n / 2 - 1; i >= 0; i--) // 从最后一个分支结点开始循环建立初始堆
        siftDown(R, i, n - 1);           // 对R[i..n-1]进行筛选
    for (int i = n - 1; i >= n - k; i--) // 进行k趟排序,每一趟排序后无序区元素个数减1
    {
        swap(R[0], R[i]);      // 将无序区中最后一个元素与R[0]交换，有序区为R[i..n-1]
        siftDown(R, 0, i - 1); // 对无序区R[0..i-1]继续筛选
    }
    cout << "从小到大前" << k << "个最大的元素:" << endl; // 顺序输出最后k个元素即为所求
    disp(R, n - k, n - 1);
}
int main()
{
    vector<int> R = {6, 8, 7, 9, 0, 1, 3, 2, 4, 5};
    int n = R.size();
    cout << "初始无序序列:" << endl;
    disp(R, 0, n - 1);
    HeapSortGetMaxk(R, n, 5);
    system("pause");
    return 0;
}