#include "../ch3/SqStack.cpp" //����˳��ջ��(������д��һ��)
string Trans(int d, int r)
{
    string str; //������ַ���
    char e;
    char m[20] = {"0123456789ABCDEF"};
    SqStack<char> st; //����˳��ջ
    while (d != 0)    //������ת������ѹ��ջ��
    {
        st.push(m[d % r]);
        d /= r;
    }
    while (!st.empty())
    {
        st.pop(e); //������ת��������ջ��ȡ�������ַ���
        str += e;  //��֪ʶ:string����ֱ�� + char
    }
    return str;
}
int main()
{
    cout << "������ʮ��������d������ת��������r(2 <= r <= 16) (����rΪ0�˳�����):" << endl;
    while (1)
    {
        int d, r;
        cin >> d >> r;
        if (r == 0)
        {
            cout << "�˳�����" << endl;
            break;
        }
        cout << "10���� " << d << " �� " << r << "����Ϊ: ";
        cout << Trans(d, r) << endl;
    }
    system("pause");
    return 0;
}