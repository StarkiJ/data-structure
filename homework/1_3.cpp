#include "../ch2/DLinkList.cpp" //����˫�������ࣨ������д��һ����
template <typename T>
void insert(DLinkList<T> &L, int i, T x) //��Ʋ��뺯��
{
    if (i < 1)
        cout << "i=" << i << " ����" << endl; //�ж�i�Ƿ���ȷ
    else
    {
        DLinkNode<T> *p = L.dhead; //����pָ��ͷ���
        int j = 0;                 // j��Ϊ0����ͷ�����Ϊ��0�����
        while (j < i && p != NULL) //ָ��pָ���i�����
        {
            j++;
            p = p->next;
        }
        DLinkNode<T> *s = new DLinkNode<T>(x); //�����½��s
        if (p != NULL)                         //�ҵ��˵�i�����
        {
            s->prior = p->prior; // s���ǰ��ָ���i-1�����
            s->next = p;         // s���ĺ��ָ���i�����
            p->prior->next = s;  // p����ԭǰ�����ĺ��ָ��s
            p->prior = s;        // p����ǰ��ָ��s
            cout << "�����: ";
            L.DispList();
        }
        else
            cout << "�����ڵ�" << i << "�����" << endl;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //����ʵ������
    int n = 9;
    DLinkList<int> L; //����˫������󣨷ǿգ�
    L.CreateListR(a, n);
    cout << "˫����: ";
    L.DispList();
    int i = 1, x = 0;
    cout << "�����ڵ� " << i << " �����֮ǰ����һ��ֵΪ " << x << " �Ľ��" << endl;
    insert(L, i, x); //ʹ������Ĳ��뺯��
    system("pause");
    return 0;
}