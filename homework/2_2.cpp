#include <iostream>
using namespace std;
const int MaxSize = 100; //队列的容量
template <typename T>
class CSqQueue2 //循环队队列类模板
{
public:
    T *data;    //存放队中元素
    int rear;   //队尾指针
    int count;  //队中元素个数
    CSqQueue2() //构造函数
    {
        data = new T[MaxSize]; //为data分配容量为MaxSize的空间
        rear = 0;              //队尾指针置初值
        count = 0;             //元素个数置初值
    }
    ~CSqQueue2() //析构函数
    {
        delete[] data;
    }
    //----------循环队基本运算算法-----------------
    bool empty() //判队空运算
    {
        return count == 0;
    }
    bool push(T e) //进队列运算
    {
        if (count == MaxSize) //队满上溢出
            return false;
        rear = (rear + 1) % MaxSize;
        data[rear] = e;
        count++; //元素个数增1
        return true;
    }
    bool pop(T &e) //出队列运算
    {
        if (count == 0) //队空下溢出
            return false;
        int front1 = (rear - count) % MaxSize; //求队首
        front1 = (front1 + 1) % MaxSize;
        e = data[front1];
        count--; //元素个数减少1
        return true;
    }
    bool gethead(T &e) //取队头运算
    {
        if (count == 0) //队空下溢出
            return false;
        int head = (rear - count + 1) % MaxSize;
        e = data[head];
        return true;
    }
};
int main()
{
    CSqQueue2<char> sq; //定义一个字符顺序队sq
    char e;
    cout << "建立一个空队sq" << endl;
    cout << "队sq" << (sq.empty() ? "空" : "不空") << endl;
    cout << "元素a,b,c,d,e进队" << endl;
    sq.push('a');
    sq.push('b');
    sq.push('c');
    sq.push('d');
    sq.push('e');
    cout << "队sq" << (sq.empty() ? "空" : "不空") << endl;
    cout << "所有元素出队次序:";
    while (!sq.empty()) //队不空循环
    {
        sq.pop(e);        //出队元素e
        cout << e << " "; //输出元素e
    }
    cout << endl;
    cout << "销毁队sq" << endl;
    system("pause");
    return 0;
}