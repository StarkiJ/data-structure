#include "../ch2/CLinkList.cpp" //引用循环单链表泛型类（和书上写的一样）
template <typename T>
void Delete_duplicate(CLinkList<T> &L) //设计删除重复函数
{

    LinkNode<T> *p = L.head->next; //首先p指向首结点
    while (p != L.head)            //当p走完一个循环后结束
    {
        LinkNode<T> *q = p->next; // q指向p的后继结点
        if (p->data == q->data)   //判断相邻两节点是否相等
        {
            p->next = q->next; //删除p结点的后继结点
            delete q;          //释放空间
        }
        else
            p = p->next; // p结点与后继节点不再相同时，p后移一个结点
    }
}
int main()
{
    int a[] = {1, 1, 1, 3, 3, 5, 6, 8, 8, 8}; //设置实验数组（递增有序）
    int n = 10;
    CLinkList<int> L; //建立循环单链表对象
    L.CreateListR(a, n);
    cout << "循环单链表: ";
    L.DispList();
    Delete_duplicate(L); //使用上面的删除重复函数
    cout << "删除重复后：";
    L.DispList();
    system("pause");
    return 0;
}