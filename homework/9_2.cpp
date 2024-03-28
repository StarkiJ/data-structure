/*思路：根据大根堆定义进行判断即可*/
#include <iostream>
#include <vector>
using namespace std;
void disp(vector<int> &R, int low, int high)
{
    for (int i = low; i <= high; i++)
        cout << R[i] << " ";
    cout << endl;
}
bool IfMaxHeap(vector<int> &R, int n)
{
    int max = n / 2 - 1; // 叶子节点的前一个节点
    for (int i = 0; i <= max; i++)
    {
        if (R[i] < R[2 * i + 1] || R[i] < R[2 * i + 2])
            return false;
    }
    return true;
}
int main()
{
    vector<int> R1 = {9, 8, 7, 6, 5, 1, 3, 2, 4, 0};
    vector<int> R2 = {9, 8, 7, 6, 0, 1, 3, 2, 4, 5};
    int n1 = R1.size(), n2 = R2.size();
    disp(R1, 0, n1 - 1);
    cout << (IfMaxHeap(R1, n1) ? "是大根堆" : "不是大根堆") << endl;
    disp(R2, 0, n2 - 1);
    cout << (IfMaxHeap(R2, n2) ? "是大根堆" : "不是大根堆") << endl;
    system("pause");
    return 0;
}