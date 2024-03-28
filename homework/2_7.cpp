#include <iostream>
using namespace std;
#define MaxSize 5 //队列的容量
template <typename T>
class CSqQueue //循环队队列类模板
{
public:
    T *data;              //存放队中元素
    int front, rear, tag; //队头和队尾指针还有标志
    CSqQueue()            //构造函数
    {
        data = new T[MaxSize];  //为data分配容量为MaxSize的空间
        front = rear = tag = 0; //队头队尾指针和标志置初值
    }
    ~CSqQueue() //析构函数
    {
        delete[] data;
    }
    //----------循环队基本运算算法-----------------
    bool empty() //判队空运算
    {
        return ((front == rear) && (tag == 0));
    }
    bool push(T e) //进队列运算
    {
        if ((rear == front) && (tag == 1)) //队满上溢出
            return false;
        rear = (rear + 1) % MaxSize;
        tag = 1; //一旦有入队里面就有元素，也就可能满，tag为1
        data[rear] = e;
        return true;
    }
    bool pop(T &e) //出队列运算
    {
        if (empty()) //队空下溢出
            return false;
        front = (front + 1) % MaxSize;
        tag = 0; //一旦有出队里面就会少元素，也就可能空，tag为0
        e = data[front];
        return true;
    }
    bool gethead(T &e) //取队头运算
    {
        if (empty()) //队空下溢出
            return false;
        int head = (front + 1) % MaxSize;
        e = data[head];
        return true;
    }
    int getlength() //返回队中元素个数
    {
        return (rear - front + MaxSize) % MaxSize;
    }
};
int main()
{
    CSqQueue<int> sq; //建立循环队列
    sq.push(0);       //进队
    sq.push(1);
    sq.push(2);
    sq.push(3);
    sq.push(4);
    sq.push(5);
    for (int i = 0; i < MaxSize; i++) //输出队列中的元素
        cout << sq.data[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}