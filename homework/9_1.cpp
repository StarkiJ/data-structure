/*˼·���ڻ����ļ�ѡ������Ļ����������Ķ���ֻѡ����С����ǰm��*/
#include <iostream>
#include <vector>
using namespace std;
void disp(vector<int> &R, int low, int high)
{
    for (int i = low; i <= high; i++)
        cout << R[i] << " ";
    cout << endl;
}
void SelectMinm(vector<int> &R, int n, int m)
{
    if (m < 0 || m >= n) // m������Ҫ���򱨴�
    {
        cout << "false: m ������ \"0 < m << n\" " << endl;
        return;
    }
    for (int i = 0; i < m; i++) // ����i������
    {
        int minj = i;
        for (int j = i + 1; j < n; j++) // �ڵ�ǰ������R[i..n-1]��ѡ��СԪ��R[minj]
            if (R[j] < R[minj])
                minj = j;        // minj����Ŀǰ�ҵ�����СԪ�ص�λ��
        if (minj != i)           // ��R[minj]������������Ԫ��
            swap(R[i], R[minj]); // ����R[i]��R[minj]
    }
    cout << "��С����˳��ǰ" << m << "��:" << endl;
    disp(R, 0, m - 1);
}
int main()
{
    vector<int> R = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = R.size(), m = 5;
    cout << "ԭ����:" << endl;
    disp(R, 0, n - 1);
    SelectMinm(R, n, m);
    system("pause");
    return 0;
}