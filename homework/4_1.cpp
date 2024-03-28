/* 思路: 从头到尾遍历数组，遇到当前最小值则记下标到变量min中，最后返回min */
#include <iostream>
using namespace std;
int getLastMin(int a[], int n) //设计求最后一个最小值下标函数
{
    int min = 0;                       //最初下标默认为0
    for (int i = 1; i <= (n - 1); i++) //从头到尾遍历数组
    {
        if (a[i] <= a[min]) //如果遇到当前最小住就记住下标
            min = i;
    }
    return min; //最后返回最后一个最小值下标
}
int main()
{
    int a[] = {0, 9, 1, 6, 8, 2, 0, 1, 5, 6, 0};
    int n = sizeof(a) / sizeof(a[0]);
    cout << getLastMin(a, n) << endl;
    system("pause");
    return 0;
}