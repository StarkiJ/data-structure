/*
思路: 由于单链表只能从前往后遍历而不能倒过来遍历，
只好先求出两字符串长度并设法向后对齐之后，
再从对齐位置向后遍历找到第一个相同元素位置即位置p
测试时创造三个单链表分别存放"load""be""ing"并将"ing"首结点连接到前两者后面
最后测试完毕后需要手动把"ing"再拆下来，否则后面析构会出问题
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
    int l1 = str1.Getlength(), //两字符串长度
        l2 = str2.Getlength();
    LinkNode<char> *p1 = str1.head->next; //指向首结点
    LinkNode<char> *p2 = str2.head->next;
    while (l1 > l2) //使两字符串向后对齐
    {
        p1 = p1->next;
        l1--;
    }
    while (l1 < l2)
    {
        p2 = p2->next;
        l2--;
    }
    while (p1 != p2) //开始向后遍历寻找共同后缀
    {
        if (p1->next == NULL) //找到头都没有就返回空
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
    LinkNode<char> *p, *r1, *r2; //共同后缀起始位置结点p，str1与str2的尾结点r1,r2
    r1 = str1.head;              //分辨找到r1,r2并在后面接上str3的首结点
    while (r1->next != NULL)
        r1 = r1->next;
    r1->next = str3.head->next;
    r2 = str2.head;
    while (r2->next != NULL)
        r2 = r2->next;
    r2->next = str3.head->next;
    str1.DispList(); //显示拼接效果
    str2.DispList();
    p = Findp(str1, str2);
    r1->next = NULL; //用完之后得手动把str3拆下来，不然待会儿析构要出问题
    r2->next = NULL;
    if (p != NULL)
    {
        cout << "共同后缀的起始位置: " << p << endl;
        cout << "共同后缀起始: " << p->data << endl;
    }
    else
        cout << "没有相同后缀" << endl;
    system("pause");
    return 0;
}