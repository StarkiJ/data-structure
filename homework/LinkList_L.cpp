#include <iostream>
using namespace std;
template <typename T>
struct LinkNode //单链表结点类型(不带头结点)
{
    T data;                                //存放数据元素
    LinkNode<T> *next;                     //指向下一个结点的域
    LinkNode() : next(NULL) {}             //构造函数
    LinkNode(T d) : data(d), next(NULL) {} //重载构造函数
};

template <typename T>
class LinkList //单链表类
{
public:
    LinkNode<T> *l; //单链表首结点(代替头结点)
    LinkList()      //构造函数,创建一个空单链表
    {
        l = NULL;
    }
    ~LinkList() //析构函数,销毁单链表
    {
        LinkNode<T> *pre, *p;
        pre = l;
        p = pre->next;
        while (p != NULL) //用p遍历结点并释放其前驱结点
        {
            delete pre; //释放pre结点
            pre = p;
            p = p->next; // pre,p同步后移一个结点
        }
        delete pre; // p为空时pre指向尾结点,此时释放尾结点
    }
    void CreateListF(T a[], int n) //头插法建立单链表
    {
        for (int i = 0; i < n; i++) //循环建立数据结点
        {
            LinkNode<T> *s = new LinkNode<T>(a[i]); //创建数据结点s
            s->next = l;                            //将结点s插入在首结点L前面
            l = s;                                  //首结点变成s
        }
    }
    void CreateListR(T a[], int n) //尾插法建立单链表
    {
        LinkNode<T> *s, *r;
        r = l;                     // r始终指向尾结点,开始时指向首结点
        s = new LinkNode<T>(a[0]); //插入第一个元素时单链表为空，直接放入元素
        l = s;
        r = s;
        for (int i = 1; i < n; i++) //循环建立数据结点
        {
            s = new LinkNode<T>(a[i]); //创建数据结点s
            r->next = s;               //将结点s插入结点r之后
            r = s;
        }
        r->next = NULL; //将尾结点的next域置为NULL
    }
    void DispList() //输出单链表所有结点值
    {
        LinkNode<T> *p;
        p = l;            // p指向首结点
        while (p != NULL) // p不为NULL,输出p结点的data域
        {
            cout << p->data << " ";
            p = p->next; // p移向下一个结点
        }
        cout << endl;
    }
};

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    LinkList<int> L;
    L.CreateListR(a, n); //尾插法建立单链表
    L.DispList();
    static LinkNode<int> *s = L.l->next;
    cout << s->data << endl;
    system("pause");
    return 0;
}