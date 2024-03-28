#include <iostream>
using namespace std;
template <typename T>
struct LinkNode //������������(����ͷ���)
{
    T data;                                //�������Ԫ��
    LinkNode<T> *next;                     //ָ����һ��������
    LinkNode() : next(NULL) {}             //���캯��
    LinkNode(T d) : data(d), next(NULL) {} //���ع��캯��
};

template <typename T>
class LinkList //��������
{
public:
    LinkNode<T> *l; //�������׽��(����ͷ���)
    LinkList()      //���캯��,����һ���յ�����
    {
        l = NULL;
    }
    ~LinkList() //��������,���ٵ�����
    {
        LinkNode<T> *pre, *p;
        pre = l;
        p = pre->next;
        while (p != NULL) //��p������㲢�ͷ���ǰ�����
        {
            delete pre; //�ͷ�pre���
            pre = p;
            p = p->next; // pre,pͬ������һ�����
        }
        delete pre; // pΪ��ʱpreָ��β���,��ʱ�ͷ�β���
    }
    void CreateListF(T a[], int n) //ͷ�巨����������
    {
        for (int i = 0; i < n; i++) //ѭ���������ݽ��
        {
            LinkNode<T> *s = new LinkNode<T>(a[i]); //�������ݽ��s
            s->next = l;                            //�����s�������׽��Lǰ��
            l = s;                                  //�׽����s
        }
    }
    void CreateListR(T a[], int n) //β�巨����������
    {
        LinkNode<T> *s, *r;
        r = l;                     // rʼ��ָ��β���,��ʼʱָ���׽��
        s = new LinkNode<T>(a[0]); //�����һ��Ԫ��ʱ������Ϊ�գ�ֱ�ӷ���Ԫ��
        l = s;
        r = s;
        for (int i = 1; i < n; i++) //ѭ���������ݽ��
        {
            s = new LinkNode<T>(a[i]); //�������ݽ��s
            r->next = s;               //�����s������r֮��
            r = s;
        }
        r->next = NULL; //��β����next����ΪNULL
    }
    void DispList() //������������н��ֵ
    {
        LinkNode<T> *p;
        p = l;            // pָ���׽��
        while (p != NULL) // p��ΪNULL,���p����data��
        {
            cout << p->data << " ";
            p = p->next; // p������һ�����
        }
        cout << endl;
    }
};

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    LinkList<int> L;
    L.CreateListR(a, n); //β�巨����������
    L.DispList();
    static LinkNode<int> *s = L.l->next;
    cout << s->data << endl;
    system("pause");
    return 0;
}