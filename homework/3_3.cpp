/*
˼·: ���ڵ�����ֻ�ܴ�ǰ������������ܵ�����������
ֻ����������ַ������Ȳ��跨������֮��
�ٴӶ���λ���������ҵ���һ����ͬԪ��λ�ü�λ��p
����ʱ��������������ֱ���"load""be""ing"����"ing"�׽�����ӵ�ǰ���ߺ���
��������Ϻ���Ҫ�ֶ���"ing"�ٲ�������������������������
*/
/*
#include "../ch4/LinkString.cpp"
LinkNode *Findp(LinkString &str1, LinkString &str2)
{
    int l1 = str1.length,
        l2 = str2.length;
    LinkNode *p1 = str1.head->next;
    LinkNode *p2 = str2.head->next;
    while (l1 > l2)
    {
        p1 = p1->next;
        l1--;
    }
    while (l1 < l2)
    {
        p2 = p2->next;
        l2--;
    }
    while (p1 != p2)
    {
        if (p1->next == NULL)
            return NULL;
        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return p1;
}*/
#include "../ch2/LinkList.cpp"
LinkNode<char> *Findp(LinkList<char> &str1, LinkList<char> &str2)
{
    int l1 = str1.Getlength(), //���ַ�������
        l2 = str2.Getlength();
    LinkNode<char> *p1 = str1.head->next; //ָ���׽��
    LinkNode<char> *p2 = str2.head->next;
    while (l1 > l2) //ʹ���ַ���������
    {
        p1 = p1->next;
        l1--;
    }
    while (l1 < l2)
    {
        p2 = p2->next;
        l2--;
    }
    while (p1 != p2) //��ʼ������Ѱ�ҹ�ͬ��׺
    {
        if (p1->next == NULL) //�ҵ�ͷ��û�оͷ��ؿ�
            return NULL;
        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return p1;
}
int main()
{
    /*
    LinkString str1, str2, str3;
    str1.StrAssign("load");
    str2.StrAssign("be");
    str3.StrAssign("ing");
    LinkNode *p;
    p = str1.head->next;
    while (p->next != NULL)
        p = p->next;
    p->next = str3.head->next;
    p = str2.head->next;
    while (p->next != NULL)
        p = p->next;
    p->next = str3.head->next;
    str1.DispStr();
    str2.DispStr();*/
    LinkList<char> str1, str2, str3;
    char a1[] = {'l', 'o', 'a', 'd'},
         a2[] = {'b', 'e'},
         a3[] = {'i', 'n', 'g'};
    int n1 = sizeof(a1),
        n2 = sizeof(a2),
        n3 = sizeof(a3);
    str1.CreateListR(a1, n1);
    str2.CreateListR(a2, n2);
    str3.CreateListR(a3, n3);
    LinkNode<char> *p, *r1, *r2; //��ͬ��׺��ʼλ�ý��p��str1��str2��β���r1,r2
    r1 = str1.head;              //�ֱ��ҵ�r1,r2���ں������str3���׽��
    while (r1->next != NULL)
        r1 = r1->next;
    r1->next = str3.head->next;
    r2 = str2.head;
    while (r2->next != NULL)
        r2 = r2->next;
    r2->next = str3.head->next;
    str1.DispList(); //��ʾƴ��Ч��
    str2.DispList();
    p = Findp(str1, str2);
    r1->next = NULL; //����֮����ֶ���str3����������Ȼ���������Ҫ������
    r2->next = NULL;
    if (p != NULL)
    {
        cout << "��ͬ��׺����ʼλ��: " << p << endl;
        cout << "��ͬ��׺��ʼ: " << p->data << endl;
    }
    else
        cout << "û����ͬ��׺" << endl;
    system("pause");
    return 0;
}