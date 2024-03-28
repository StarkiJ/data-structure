/*
思路: 先参考带头结点的单链表类构建不带头结点的单链表类(教材源码没给)
用指向首结点的指针一定程度上代替头结点的功能，使用起来会麻烦一点
设计bool类型函数delx(p,x)进行递归，单链表为空时直接错误返回false
因为函数参数已经定为(p,x)不能从参数入手递归，设置静态结点指针t,s辅助完成
不带头结点的单链表需考虑x在首结点的特殊情况特殊处理，避免丢失首结点
剩下分两种结果: 找到值为x的结点并删除，找不到值为x的结点，作为递归第一步
之后进行递归调用，每次调用前t,s同步后移一个结点达到递归效果
*/
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
        l = new LinkNode<T>(a[0]);
        for (int i = 1; i < n; i++) //循环建立数据结点
        {
            LinkNode<T> *s = new LinkNode<T>(a[i]); //创建数据结点s
            s->next = l;                            //将结点s插入在首结点L前面
            l = s;                                  //首结点变成s
        }
    }
    void CreateListR(T a[], int n) //尾插法建立单链表
    {
        LinkNode<T> *s, *r;                   // r始终指向尾结点,开始时指向首结点
        l = new LinkNode<T>(a[0]); //插入第一个元素时单链表为空，直接放入元素
        r = l;
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
bool delx(LinkList<int> &p, int x)
{
    if (p.l == NULL) //空链表时错误返回false
        return false;
    if (p.l->data == x) //首结点为x特殊处理，因为要挪首结点指针
    {
        LinkNode<int> *q = p.l->next;
        delete p.l;
        p.l = q;
        return true;
    }
    static LinkNode<int> *t = p.l; //利用静态达到递归效果
    static LinkNode<int> *s = t->next;
    if (s == NULL)    //递归部分开始: 首结点存储元素不为x且后面为空时错误返回false
        return false; //此时最深层的delx直接返回false，外层仍会进行函数最后的初始化，此处无需初始化
    if (s->data == x) // s中存储元素为x时删去x
    {
        t->next = s->next;
        delete s;
    }
    else //大问题转换为t,s后移一个结点加小问题
    {
        t = s;
        s = s->next; // t,s同步后移一个结点
        delx(p, x);  //小问题:从后一位开始找x
    }
    t = p.l; //结束后手动初始化为下一次调用做准备
    s = t->next;
    return true;
}
int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //建立测试用数组
    int n = sizeof(a) / sizeof(a[0]);         //测试用数组长度
    LinkList<int> p;                          //建立不带头结点的单链表p
    p.CreateListR(a, n);                      //尾插法建立不带头结点的单链表
    p.DispList();
    delx(p, 9);
    p.DispList();
    delx(p, 10);
    p.DispList();
    delx(p, 3);
    p.DispList();
    delx(p, 0);
    p.DispList();
    delx(p, 6);
    p.DispList();
    system("pause");
    return 0;
}