#include "../ch2/DLinkList.cpp" //引用双链表泛型类（和书上写的一样）
template <typename T>
void insert(DLinkList<T> &L, int i, T x) //设计插入函数
{
    if (i < 1)
        cout << "i=" << i << " 错误" << endl; //判断i是否正确
    else
    {
        DLinkNode<T> *p = L.dhead; //首先p指向头结点
        int j = 0;                 // j置为0，将头结点视为第0个结点
        while (j < i && p != NULL) //指针p指向第i个结点
        {
            j++;
            p = p->next;
        }
        DLinkNode<T> *s = new DLinkNode<T>(x); //建立新结点s
        if (p != NULL)                         //找到了第i个结点
        {
            s->prior = p->prior; // s结点前驱指向第i-1个结点
            s->next = p;         // s结点的后继指向第i个结点
            p->prior->next = s;  // p结点的原前驱结点的后继指向s
            p->prior = s;        // p结点的前驱指向s
            cout << "插入后: ";
            L.DispList();
        }
        else
            cout << "不存在第" << i << "个结点" << endl;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //设置实验数组
    int n = 9;
    DLinkList<int> L; //建立双链表对象（非空）
    L.CreateListR(a, n);
    cout << "双链表: ";
    L.DispList();
    int i = 1, x = 0;
    cout << "尝试在第 " << i << " 个结点之前插入一个值为 " << x << " 的结点" << endl;
    insert(L, i, x); //使用上面的插入函数
    system("pause");
    return 0;
}