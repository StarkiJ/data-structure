/* ˼·: ����������Ƶݹ飬Ϊ�ﵽ��ȡ�����Ч�����������ұ߽���� */
#include <iostream>
using namespace std;
int getMax(int a[], int l, int r) //���ȡ���ַ��������ֵ����
{
    if (l == r)      //���ұ߽���ȼ�ֻ��һ������
        return a[l]; //�������ӣ�����ֱ�ӾͰ���Ŀ���a[0]����ȥ��!
    else
    {
        int mid = l + (r - l) / 2,        //ȡ�м�λ��mid
            max1 = getMax(a, l, mid),     // mid��Ϊǰ�벿�ֵ��ұ߽�
            max2 = getMax(a, mid + 1, r); // mid + 1��Ϊǰ�벿�ֵ���߽�
        return max(max1, max2);           //�������ֵ
    }
}
int main()
{
    int a[] = {0, 8, 5, 6, 8, 1, 4, 2, 4, 5, 0, 2, 7, 6, 9};
    int r = sizeof(a) / sizeof(a[0]) - 1; //���鳤��-1���������һ��Ԫ���±�
    cout << getMax(a, 0, r) << endl;
    system("pause");
    return 0;
}