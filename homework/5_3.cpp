/*
˼·: ���׼���ȶ���ͬʱ�ݹ�getCount(s.DelStr(0, 1), t.DelStr(0, 1))
�ȶԲ�ͬʱ����t�ٵݹ�getCount(s.DelStr(0, 1), t)������Ϊ�����������ᱨ���þ�̬Ҳ��������������˷����ˡ�
��Ϊ�ȶ���ͬʱ����������һ������ͬʱ��ʼ�ݹ���ã�ֱ�����ָ�뵽�ս����жϣ�
����������˵��������������һ����ȷ���1��ֻ��p��˵������������һ�鲻�ȷ���0��
ֻ��q��˵����һ��ȶԳɹ�����1+�����ȶԵݹ顣
*/
#include "../ch4/LinkString.cpp"
int getCount0(LinkString &s, LinkString &t)
{
    int n = 0;
    LinkNode *p = s.head->next; //�ֱ�ָ��s,t���׽��
    LinkNode *q = t.head->next;
    while (p != NULL && q != NULL)
    {
        LinkNode *m = p;
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            p = m->next;
            q = t.head->next;
        }
        if (q == NULL)
        {
            n++;
            q = t.head->next;
        }
    }
    return n;
}
int getCount(LinkString &s, LinkString &t) //������ص����ִ�������
{
    LinkNode *p = s.head->next; //�ֱ�ָ��s,t���׽��
    LinkNode *q = t.head->next;
    while (p != NULL && q != NULL) // s,t�����ǿմ�ʱ��ʼѭ��
    {
        if (p->data == q->data) //����򶼺���һ�����
        {
            p = p->next;
            q = q->next;
        }
        else //�������ɾȥ���ֱȶ���s�ĵ�һ���ַ������ݹ����
        {
            s = s.DelStr(0, 1);
            return getCount(s, t);
        }
        if (p == NULL && q == NULL) //�պ�һ���������˵�����һ���Ӧ������1
        {
            cout << " 1 = ";
            return 1;
        }
        if (p == NULL) // s�ȱ�����˵�����һ�鲻��Ӧ������0
        {
            cout << " 0 = ";
            return 0;
        }
        if (q == NULL) // q����ʱ˵��ǰ��һ���Ӧ��1+�����ݹ�
        {
            cout << "1 + ";
            s = s.DelStr(0, t.length);
            return 1 + getCount(s, t);
        }
    }
    return 0; // s,t���пմ�ʱֱ�ӷ���0
}
int main()
{
    LinkString s, t;
    s.StrAssign("abababababa");
    t.StrAssign("aba");
    cout << "s: ";
    s.DispStr();
    cout << "t: ";
    t.DispStr();
    cout << "t��s�в��ص����ִ���: " << getCount(s, t) << endl;
    system("pause");
    return 0;
}