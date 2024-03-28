#include "../ch3/SqStack.cpp" //����˳��ջ��(������д��һ��)
bool isMatch(string str)
{
    SqStack<char> st; //����˳��ջ
    int i = 0;        //�����±�
    char e;
    while (i < str.length()) //����whileѭ����˳���ȡ���������
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') //������Ϊ������ʱ�Ƚ�ջ����
            st.push(str[i]);
        else
        {
            if (str[i] == ')') //��ȡ��')'
            {
                if (st.empty()) //ջ��ʱû����������������ƥ�䣬����false
                    return false;
                st.pop(e);    //ջ���ж���ʱ��ջ��ȡ�����ж�
                if (e != '(') //���ջ������'('��ƥ�䣬����false
                    return false;
            }
            if (str[i] == ']') //��ȡ��']'
            {
                if (st.empty()) //ջ��ʱû����������������ƥ�䣬����false
                    return false;
                st.pop(e);    //ջ���ж���ʱ��ջ��ȡ�����ж�
                if (e != '[') //���ջ������'['��ƥ�䣬����false
                    return false;
            }
            if (str[i] == '}') //��ȡ��'}'
            {
                if (st.empty()) //ջ��ʱû����������������ƥ�䣬����false
                    return false;
                st.pop(e);    //ջ���ж���ʱ��ջ��ȡ�����ж�
                if (e != '{') //���ջ������'{'��ƥ�䣬����false
                    return false;
            }
        }
        i++; //�±�+1����ȡ��һ������ķ���
    }
    return st.empty(); //ȫ����ȡ���
}

int main()
{
    cout << "��������������(����q�˳�):" << endl;
    while (1)
    {
        string str;
        cin >> str;
        if (str == "q")
        {
            cout << "�˳�����" << endl;
            break;
        }
        if (isMatch(str))
            cout << "����ƥ��" << endl;
        else
            cout << "���Ų�ƥ��" << endl;
    }
    system("pause");
    return 0;
}