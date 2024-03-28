#include <iostream>
using namespace std;
#define MaxSize 5 //���е�����
template <typename T>
class CSqQueue //ѭ���Ӷ�����ģ��
{
public:
    T *data;              //��Ŷ���Ԫ��
    int front, rear, tag; //��ͷ�Ͷ�βָ�뻹�б�־
    CSqQueue()            //���캯��
    {
        data = new T[MaxSize];  //Ϊdata��������ΪMaxSize�Ŀռ�
        front = rear = tag = 0; //��ͷ��βָ��ͱ�־�ó�ֵ
    }
    ~CSqQueue() //��������
    {
        delete[] data;
    }
    //----------ѭ���ӻ��������㷨-----------------
    bool empty() //�жӿ�����
    {
        return ((front == rear) && (tag == 0));
    }
    bool push(T e) //����������
    {
        if ((rear == front) && (tag == 1)) //���������
            return false;
        rear = (rear + 1) % MaxSize;
        tag = 1; //һ��������������Ԫ�أ�Ҳ�Ϳ�������tagΪ1
        data[rear] = e;
        return true;
    }
    bool pop(T &e) //����������
    {
        if (empty()) //�ӿ������
            return false;
        front = (front + 1) % MaxSize;
        tag = 0; //һ���г�������ͻ���Ԫ�أ�Ҳ�Ϳ��ܿգ�tagΪ0
        e = data[front];
        return true;
    }
    bool gethead(T &e) //ȡ��ͷ����
    {
        if (empty()) //�ӿ������
            return false;
        int head = (front + 1) % MaxSize;
        e = data[head];
        return true;
    }
    int getlength() //���ض���Ԫ�ظ���
    {
        return (rear - front + MaxSize) % MaxSize;
    }
};
int main()
{
    CSqQueue<int> sq; //����ѭ������
    sq.push(0);       //����
    sq.push(1);
    sq.push(2);
    sq.push(3);
    sq.push(4);
    sq.push(5);
    for (int i = 0; i < MaxSize; i++) //��������е�Ԫ��
        cout << sq.data[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}