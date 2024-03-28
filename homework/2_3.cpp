#include "../ch3/SqStack.cpp" //引用顺序栈类(和书上写的一样)
string Trans(int d, int r)
{
    string str; //输出用字符串
    char e;
    char m[20] = {"0123456789ABCDEF"};
    SqStack<char> st; //建立顺序栈
    while (d != 0)    //将进制转换得数压入栈中
    {
        st.push(m[d % r]);
        d /= r;
    }
    while (!st.empty())
    {
        st.pop(e); //将进制转换得数从栈中取出放入字符串
        str += e;  //冷知识:string可以直接 + char
    }
    return str;
}
int main()
{
    cout << "请输入十进制整数d与所需转换进制数r(2 <= r <= 16) (输入r为0退出程序):" << endl;
    while (1)
    {
        int d, r;
        cin >> d >> r;
        if (r == 0)
        {
            cout << "退出程序" << endl;
            break;
        }
        cout << "10进制 " << d << " 的 " << r << "进制为: ";
        cout << Trans(d, r) << endl;
    }
    system("pause");
    return 0;
}