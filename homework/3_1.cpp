/*
˼·������whileѭ�������ַ�������ǰ�����ַ���ͬʱƽ̨����+1��
��ͬʱ��˵��������һ��ƽ̨�����¿�ʼ����ƽ̨���ȡ�
���ñ���m���浱ǰƽ̨���ȣ�����n����Ŀǰ���ƽ̨���ȣ���󷵻�n
*/
#include "../ch4/LinkString.cpp"
int LongestSame(LinkString &lst) //������ƽ̨���Ⱥ���
{
    LinkNode *p = lst.head->next; //ָ����׽�㿪ʼ
    int m = 1, n = 1;
    while (p->next != NULL) //�����ַ���
    {
        if (p->data == p->next->data) //ǰ�����ַ����ʱm����
            m++;
        else //���ֲ�ͬʱnȡ���ֵ��m��1
        {
            n = max(m, n);
            m = 1;
        }
        p = p->next; // pָ����һ��Ԫ��
    }
    n = max(m, n); //��ֹ���һ��ƽ̨������©��
    return n;
}
int main()
{
    LinkString s;                  //������������
    s.StrAssign("abbcdddeefgggg"); //���������ô�
    s.DispStr();                   //�����
    cout << "�ƽ̨����: " << LongestSame(s) << endl;
    system("pause");
    return 0;
}