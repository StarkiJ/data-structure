#include "../ch3/SqStack.cpp" //����˳��ջ��(������д��һ��)
string Reorder(int *a, int n) //�������������
{
    string op, ans; //������ַ���
    char e;
    int i = 0, j = 0; //��������±�
    SqStack<char> st; //����˳��ջ
    while (i < n)     //���ν�����Ԫ��ѹ��ջ
    {
        st.push(a[i]);
        op += " ��ջ"; //���������������ַ���op
        if (a[i] % 2)  //����������ͳ�ջ
        {
            st.pop(e);
            op += " ��ջ";    //���������������ַ���op
            ans += (e + '0'); //�����ַ���ans
        }
        i++;
    }
    while (!st.empty()) //������ջ�е�Ԫ��ȡ��
    {
        st.pop(e);        //��ջ
        op += " ��ջ";    //���������������ַ���op
        ans += (e + '0'); //��ջ�������ַ���ans
    }
    cout << "op: " << op << endl;
    cout << "ans: " << ans << endl;
    return ans;
}
int main()
{
    int n = 8;
    int a[n - 1] = {1, 2, 3, 4, 5, 6, 7, 8}; //����ʵ������
    cout << "ʵ������: ";
    for (int m = 0; m < n; m++)
        cout << a[m];
    cout << endl;
    cout << "��������..." << endl;
    Reorder(a, n);
    system("pause");
    return 0;
}