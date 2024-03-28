/*
思路: 最初准备比对相同时递归getCount(s.DelStr(0, 1), t.DelStr(0, 1))
比对不同时重置t再递归getCount(s.DelStr(0, 1), t)，但因为不引用析构会报错，用静态也报错等问题解决不了放弃了。
改为比对相同时正常继续下一个，不同时开始递归调用，直到最后指针到空进行判断：
若都到空了说明遍历完毕且最后一组相等返回1，只有p空说明遍历完毕最后一组不等返回0，
只有q空说明这一组比对成功返回1+后续比对递归。
*/
#include "../ch4/LinkString.cpp"
int getCount0(LinkString &s, LinkString &t)
{
    int n = 0;
    LinkNode *p = s.head->next; //分别指向s,t的首结点
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
int getCount(LinkString &s, LinkString &t) //设计求不重叠出现次数函数
{
    LinkNode *p = s.head->next; //分别指向s,t的首结点
    LinkNode *q = t.head->next;
    while (p != NULL && q != NULL) // s,t都不是空串时开始循环
    {
        if (p->data == q->data) //相等则都后移一个结点
        {
            p = p->next;
            q = q->next;
        }
        else //不相等则删去这轮比对中s的第一个字符继续递归调用
        {
            s = s.DelStr(0, 1);
            return getCount(s, t);
        }
        if (p == NULL && q == NULL) //刚好一起遍历完则说明最后一组对应，返回1
        {
            cout << " 1 = ";
            return 1;
        }
        if (p == NULL) // s先遍历完说明最后一组不对应，返回0
        {
            cout << " 0 = ";
            return 0;
        }
        if (q == NULL) // q到空时说明前面一组对应，1+后续递归
        {
            cout << "1 + ";
            s = s.DelStr(0, t.length);
            return 1 + getCount(s, t);
        }
    }
    return 0; // s,t中有空串时直接返回0
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
    cout << "t在s中不重叠出现次数: " << getCount(s, t) << endl;
    system("pause");
    return 0;
}