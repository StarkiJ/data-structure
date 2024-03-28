/*
author: ZhuoXin Jiang
language: c++
time: Dec. 11th, 2022
*/
#include <iostream>
using namespace std;
struct ListNode // 带头结点的单链表结点类型
{
    int val;
    ListNode *next;
    ListNode() : next(NULL) {} // 构造函数
    ListNode(int x) : val(x), next(NULL) {}
};
void DispList(ListNode *head) // 输出单链表所有结点值
{
    ListNode *p = head->next;
    while (p != NULL) // p不为NULL,输出p结点的val域
    {
        cout << p->val << " ";
        p = p->next; // p移向下一个结点
    }
    cout << endl;
}
void CombinedLList(ListNode *head1, ListNode *head2)
{
    ListNode *ans, *r1, *r2, *ra, *ta;
    ans = new ListNode();
    r1 = head1->next, r2 = head2->next, ra = ans;
    while (r1 != NULL && r2 != NULL)
    {
        int x; // 临时存储将放入ans的值
        if (r1->val < r2->val)
        {
            x = r1->val;
            r1 = r1->next;
        }
        else if (r1->val > r2->val)
        {
            x = r2->val;
            r2 = r2->next;
        }
        else // if (r1->val == r2->val)
        {
            x = r1->val;
            r1 = r1->next;
            r2 = r2->next;
        }
        if (x != ra->val)
        {
            ta = new ListNode(x);
            ra->next = ta;
            ra = ta;
        }
    }
    if (r1 != NULL)
    {
        while (r1 != NULL && ra->val == r1->val)
            r1 = r1->next;
        ra->next = r1;
    }
    else
    {
        while (r2 != NULL && ra->val == r2->val)
            r2 = r2->next;
        ra->next = r2;
    }
    DispList(ans);
}
int main()
{
    ListNode *head1, *head2;
    ListNode *t, *r;
    head1 = new ListNode(); // head为头结点不放东西
    head2 = new ListNode();
    r = head1;       // 不能放到前面了，前面head还是空，会出现段错误
    int x, line = 0; // x存储输入数值,line判断是否输入完毕
    while (cin >> x) // 读取一行数据尾插法加到单链表后面
    {

        t = new ListNode(x);
        r->next = t;
        r = t;
        char i = getchar(); // 再读一个整数后的符号，是空格则读下一个整数进下一个循环
        if (i != ' ')       // 读到换行则说明已经读完一行
        {
            r->next = NULL;
            r = head2;
            if (line == 1)
                break;
            line++;
        }
    }
    // DispList(head1);
    // DispList(head2);
    CombinedLList(head1, head2);
    system("pause");
    return 0;
}