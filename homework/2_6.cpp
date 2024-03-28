#include "../ch3/SqStack.cpp" //����˳��ջ��(������д��һ��)
void Show(int *a, int n)      //��ʾ���麯��
{
    for (int m = 0; m < n; m++)
    {
        cout << a[m] << " ";
    }
    cout << endl;
}
void Reorder(int *a, int n) //�������������
{
    int i = 0, j = 0; //��������±�
    SqStack<int> st;  //����˳��ջ
    while (i < n)     //���ν�����Ԫ��ѹ��ջ
    {
        st.push(a[i]);
        if (!(a[i] % 2)) //�����ż���ͳ�ջ��˳�����������
        {
            st.pop(a[j]);
            Show(a, n);
            j++;
        }
        i++;
    }
    while (i > j) //������ջ�е�����Ԫ�شӺ���ǰ�Ż�����(��ʱi��j������+1�˲����ٵ���!!!)
    {
        st.pop(a[i - 1]);
        Show(a, n);
        i--;
    }
}
int main()
{
    int n = 8;
    int a[n - 1] = {1, 2, 3, 4, 5, 6, 7, 8}; //����ʵ������
    cout << "ʵ������: " << endl;
    Show(a, n);
    cout << "��������: " << endl;
    Reorder(a, n);
    system("pause");
    return 0;
}