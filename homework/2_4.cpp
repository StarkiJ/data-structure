#include "../ch3/LinkStack.cpp" //引用链栈类(和书上写的一样)
template <typename T>
bool Outk(LinkStack<T> &st, int k) //设计出栈从栈顶开始第k个结点
{
    T e[k];    //建立数组用来暂存取出元素
    int i = 0; //数组e下标
    while (i < k)
    {
        if (st.empty()) //防止空栈
            return false;
        st.pop(e[i]); //将从栈顶开始前k个元素全部提出到数组e中
        i++;
    }
    cout << e[k - 1] << endl; //输出第k个元素
    i -= 2;                   //从第k-1个元素开始放回
    while (i >= 0)
    {
        st.push(e[i]);
        i--;
    }
    return true;
}
int main()
{
    LinkStack<int> st;
    cout << "元素 5 4 3 2 1 入栈" << endl;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    cout << "先后出栈第2,4个元素:" << endl;
    Outk(st, 2);
    Outk(st, 4);
    system("pause");
    return 0;
}