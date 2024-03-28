#include "../ch2/CLinkList.cpp" //����ѭ�����������ࣨ������д��һ����
template <typename T>
void Delete_duplicate(CLinkList<T> &L) //���ɾ���ظ�����
{

    LinkNode<T> *p = L.head->next; //����pָ���׽��
    while (p != L.head)            //��p����һ��ѭ�������
    {
        LinkNode<T> *q = p->next; // qָ��p�ĺ�̽��
        if (p->data == q->data)   //�ж��������ڵ��Ƿ����
        {
            p->next = q->next; //ɾ��p���ĺ�̽��
            delete q;          //�ͷſռ�
        }
        else
            p = p->next; // p������̽ڵ㲻����ͬʱ��p����һ�����
    }
}
int main()
{
    int a[] = {1, 1, 1, 3, 3, 5, 6, 8, 8, 8}; //����ʵ�����飨��������
    int n = 10;
    CLinkList<int> L; //����ѭ�����������
    L.CreateListR(a, n);
    cout << "ѭ��������: ";
    L.DispList();
    Delete_duplicate(L); //ʹ�������ɾ���ظ�����
    cout << "ɾ���ظ���";
    L.DispList();
    system("pause");
    return 0;
}