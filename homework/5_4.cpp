/*
˼·: �Ȳο���ͷ���ĵ������๹������ͷ���ĵ�������(�̲�Դ��û��)
��ָ���׽���ָ��һ���̶��ϴ���ͷ���Ĺ��ܣ�ʹ���������鷳һ��
���bool���ͺ���delx(p,x)���еݹ飬������Ϊ��ʱֱ�Ӵ��󷵻�false
��Ϊ���������Ѿ���Ϊ(p,x)���ܴӲ������ֵݹ飬���þ�̬���ָ��t,s�������
����ͷ���ĵ������迼��x���׽�������������⴦�����ⶪʧ�׽��
ʣ�·����ֽ��: �ҵ�ֵΪx�Ľ�㲢ɾ�����Ҳ���ֵΪx�Ľ�㣬��Ϊ�ݹ��һ��
֮����еݹ���ã�ÿ�ε���ǰt,sͬ������һ�����ﵽ�ݹ�Ч��
*/
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
        l = new LinkNode<T>(a[0]);
        for (int i = 1; i < n; i++) //ѭ���������ݽ��
        {
            LinkNode<T> *s = new LinkNode<T>(a[i]); //�������ݽ��s
            s->next = l;                            //�����s�������׽��Lǰ��
            l = s;                                  //�׽����s
        }
    }
    void CreateListR(T a[], int n) //β�巨����������
    {
        LinkNode<T> *s, *r;                   // rʼ��ָ��β���,��ʼʱָ���׽��
        l = new LinkNode<T>(a[0]); //�����һ��Ԫ��ʱ������Ϊ�գ�ֱ�ӷ���Ԫ��
        r = l;
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
bool delx(LinkList<int> &p, int x)
{
    if (p.l == NULL) //������ʱ���󷵻�false
        return false;
    if (p.l->data == x) //�׽��Ϊx���⴦����ΪҪŲ�׽��ָ��
    {
        LinkNode<int> *q = p.l->next;
        delete p.l;
        p.l = q;
        return true;
    }
    static LinkNode<int> *t = p.l; //���þ�̬�ﵽ�ݹ�Ч��
    static LinkNode<int> *s = t->next;
    if (s == NULL)    //�ݹ鲿�ֿ�ʼ: �׽��洢Ԫ�ز�Ϊx�Һ���Ϊ��ʱ���󷵻�false
        return false; //��ʱ������delxֱ�ӷ���false������Ի���к������ĳ�ʼ�����˴������ʼ��
    if (s->data == x) // s�д洢Ԫ��Ϊxʱɾȥx
    {
        t->next = s->next;
        delete s;
    }
    else //������ת��Ϊt,s����һ������С����
    {
        t = s;
        s = s->next; // t,sͬ������һ�����
        delx(p, x);  //С����:�Ӻ�һλ��ʼ��x
    }
    t = p.l; //�������ֶ���ʼ��Ϊ��һ�ε�����׼��
    s = t->next;
    return true;
}
int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //��������������
    int n = sizeof(a) / sizeof(a[0]);         //���������鳤��
    LinkList<int> p;                          //��������ͷ���ĵ�����p
    p.CreateListR(a, n);                      //β�巨��������ͷ���ĵ�����
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