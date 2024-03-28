/*˼·�����ö��������ǰk�����������С�������*/
#include <iostream>
#include <vector>
using namespace std;
void disp(vector<int> &R, int low, int high)
{
    for (int i = low; i <= high; i++)
        cout << R[i] << " ";
    cout << endl;
}
void siftDown(vector<int> &R, int low, int high) // R[low..high]���Զ�����ɸѡ
{
    int i = low;
    int j = 2 * i + 1; // R[j]��R[i]������
    int tmp = R[i];    // tmp��ʱ��������
    while (j <= high)  // ֻ��R[low..high]��Ԫ�ؽ���ɸѡ
    {
        if (j < high && R[j] < R[j + 1])
            j++;        // ���Һ��ӽϴ�,��jָ���Һ���
        if (tmp < R[j]) // tmp�ĺ��ӽϴ�
        {
            R[i] = R[j]; // ��R[j]������˫��λ����
            i = j;
            j = 2 * i + 1; // �޸�i��jֵ,�Ա��������ɸѡ
        }
        else
            break; // �����ӽ�С����ɸѡ����
    }
    R[i] = tmp; // ԭ������������λ��
}
void HeapSortGetMaxk(vector<int> &R, int n, int k) // ������
{
    for (int i = n / 2 - 1; i >= 0; i--) // �����һ����֧��㿪ʼѭ��������ʼ��
        siftDown(R, i, n - 1);           // ��R[i..n-1]����ɸѡ
    for (int i = n - 1; i >= n - k; i--) // ����k������,ÿһ�������������Ԫ�ظ�����1
    {
        swap(R[0], R[i]);      // �������������һ��Ԫ����R[0]������������ΪR[i..n-1]
        siftDown(R, 0, i - 1); // ��������R[0..i-1]����ɸѡ
    }
    cout << "��С����ǰ" << k << "������Ԫ��:" << endl; // ˳��������k��Ԫ�ؼ�Ϊ����
    disp(R, n - k, n - 1);
}
int main()
{
    vector<int> R = {6, 8, 7, 9, 0, 1, 3, 2, 4, 5};
    int n = R.size();
    cout << "��ʼ��������:" << endl;
    disp(R, 0, n - 1);
    HeapSortGetMaxk(R, n, 5);
    system("pause");
    return 0;
}