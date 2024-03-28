/* 思路: 如题所述设计递归，为达到截取数组的效果，设立左右边界变量 */
#include <iostream>
using namespace std;
int getMax(int a[], int l, int r) //设计取二分法数组最大值函数
{
    if (l == r)      //左右边界相等即只有一个整数
        return a[l]; //动点脑子，不能直接就把题目里的a[0]打上去了!
    else
    {
        int mid = l + (r - l) / 2,        //取中间位置mid
            max1 = getMax(a, l, mid),     // mid作为前半部分的右边界
            max2 = getMax(a, mid + 1, r); // mid + 1作为前半部分的左边界
        return max(max1, max2);           //返回最大值
    }
}
int main()
{
    int a[] = {0, 8, 5, 6, 8, 1, 4, 2, 4, 5, 0, 2, 7, 6, 9};
    int r = sizeof(a) / sizeof(a[0]) - 1; //数组长度-1即数组最后一个元素下标
    cout << getMax(a, 0, r) << endl;
    system("pause");
    return 0;
}