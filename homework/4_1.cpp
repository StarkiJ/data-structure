/* ˼·: ��ͷ��β�������飬������ǰ��Сֵ����±굽����min�У���󷵻�min */
#include <iostream>
using namespace std;
int getLastMin(int a[], int n) //��������һ����Сֵ�±꺯��
{
    int min = 0;                       //����±�Ĭ��Ϊ0
    for (int i = 1; i <= (n - 1); i++) //��ͷ��β��������
    {
        if (a[i] <= a[min]) //���������ǰ��Сס�ͼ�ס�±�
            min = i;
    }
    return min; //��󷵻����һ����Сֵ�±�
}
int main()
{
    int a[] = {0, 9, 1, 6, 8, 2, 0, 1, 5, 6, 0};
    int n = sizeof(a) / sizeof(a[0]);
    cout << getLastMin(a, n) << endl;
    system("pause");
    return 0;
}