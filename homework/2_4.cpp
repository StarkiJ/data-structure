#include "../ch3/LinkStack.cpp" //������ջ��(������д��һ��)
template <typename T>
bool Outk(LinkStack<T> &st, int k) //��Ƴ�ջ��ջ����ʼ��k�����
{
    T e[k];    //�������������ݴ�ȡ��Ԫ��
    int i = 0; //����e�±�
    while (i < k)
    {
        if (st.empty()) //��ֹ��ջ
            return false;
        st.pop(e[i]); //����ջ����ʼǰk��Ԫ��ȫ�����������e��
        i++;
    }
    cout << e[k - 1] << endl; //�����k��Ԫ��
    i -= 2;                   //�ӵ�k-1��Ԫ�ؿ�ʼ�Ż�
    while (i >= 0)
    {
        st.push(e[i]);
        i--;
    }
    return true;
}
int main()
{
    LinkStack<int> st;
    cout << "Ԫ�� 5 4 3 2 1 ��ջ" << endl;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    cout << "�Ⱥ��ջ��2,4��Ԫ��:" << endl;
    Outk(st, 2);
    Outk(st, 4);
    system("pause");
    return 0;
}