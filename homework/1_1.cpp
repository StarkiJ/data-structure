#include "../ch2/SqList.cpp" //����˳�������(������д��һ��)
template <typename T>
void Upside_down(SqList<T> &L) // ��Ƶߵ�������Ҫ�ǵ���"&"
{
    int i = 0;
    while (i < (L.length - 1) / 2) // ͨ��i�Ƿ�������ж��Ƿ񽻻����
    {
        int temp_a, j = L.length - 1 - i; // temp_aΪ��ʱ������������i���ڽ���,jΪi��Ӧ�Ľ���λ��
        temp_a = L.data[i];               // ͨ��temo_a�ĸ������н���
        L.data[i] = L.data[j];
        L.data[j] = temp_a;
        i++;
    }
}

int main()
{
    int n = 5;
    int a[] = {1, 2, 3, 4, 5}; // ����ʵ������
    SqList<int> L;             // ����˳������
    L.CreateList(a, n);
    cout << "˳���: ";
    L.DispList();
    Upside_down(L); // ʹ������ĵߵ���������˳���
    cout << "���ú�: ";
    L.DispList();
    system("pause");
    return 0;
}