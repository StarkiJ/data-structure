#include <iostream>
using namespace std;
const int MaxSize = 100; //���е�����
template <typename T>
class CSqQueue2 //ѭ���Ӷ�����ģ��
{
public:
    T *data;    //��Ŷ���Ԫ��
    int rear;   //��βָ��
    int count;  //����Ԫ�ظ���
    CSqQueue2() //���캯��
    {
        data = new T[MaxSize]; //Ϊdata��������ΪMaxSize�Ŀռ�
        rear = 0;              //��βָ���ó�ֵ
        count = 0;             //Ԫ�ظ����ó�ֵ
    }
    ~CSqQueue2() //��������
    {
        delete[] data;
    }
    //----------ѭ���ӻ��������㷨-----------------
    bool empty() //�жӿ�����
    {
        return count == 0;
    }
    bool push(T e) //����������
    {
        if (count == MaxSize) //���������
            return false;
        rear = (rear + 1) % MaxSize;
        data[rear] = e;
        count++; //Ԫ�ظ�����1
        return true;
    }
    bool pop(T &e) //����������
    {
        if (count == 0) //�ӿ������
            return false;
        int front1 = (rear - count) % MaxSize; //�����
        front1 = (front1 + 1) % MaxSize;
        e = data[front1];
        count--; //Ԫ�ظ�������1
        return true;
    }
    bool gethead(T &e) //ȡ��ͷ����
    {
        if (count == 0) //�ӿ������
            return false;
        int head = (rear - count + 1) % MaxSize;
        e = data[head];
        return true;
    }
};
int main()
{
    CSqQueue2<char> sq; //����һ���ַ�˳���sq
    char e;
    cout << "����һ���ն�sq" << endl;
    cout << "��sq" << (sq.empty() ? "��" : "����") << endl;
    cout << "Ԫ��a,b,c,d,e����" << endl;
    sq.push('a');
    sq.push('b');
    sq.push('c');
    sq.push('d');
    sq.push('e');
    cout << "��sq" << (sq.empty() ? "��" : "����") << endl;
    cout << "����Ԫ�س��Ӵ���:";
    while (!sq.empty()) //�Ӳ���ѭ��
    {
        sq.pop(e);        //����Ԫ��e
        cout << e << " "; //���Ԫ��e
    }
    cout << endl;
    cout << "���ٶ�sq" << endl;
    system("pause");
    return 0;
}