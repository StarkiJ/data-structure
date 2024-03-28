#include "../ch3/SqStack.cpp" //引用顺序栈类(和书上写的一样)
bool isMatch(string str)
{
    SqStack<char> st; //建立顺序栈
    int i = 0;        //数组下标
    char e;
    while (i < str.length()) //利用while循环按顺序读取输入的括号
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') //当输入为左括号时先进栈存着
            st.push(str[i]);
        else
        {
            if (str[i] == ')') //读取到')'
            {
                if (st.empty()) //栈空时没有左括号与右括号匹配，返回false
                    return false;
                st.pop(e);    //栈里有东西时把栈顶取出来判断
                if (e != '(') //如果栈顶不是'('则不匹配，返回false
                    return false;
            }
            if (str[i] == ']') //读取到']'
            {
                if (st.empty()) //栈空时没有左括号与右括号匹配，返回false
                    return false;
                st.pop(e);    //栈里有东西时把栈顶取出来判断
                if (e != '[') //如果栈顶不是'['则不匹配，返回false
                    return false;
            }
            if (str[i] == '}') //读取到'}'
            {
                if (st.empty()) //栈空时没有左括号与右括号匹配，返回false
                    return false;
                st.pop(e);    //栈里有东西时把栈顶取出来判断
                if (e != '{') //如果栈顶不是'{'则不匹配，返回false
                    return false;
            }
        }
        i++; //下标+1，读取下一个输入的符号
    }
    return st.empty(); //全部读取完毕
}

int main()
{
    cout << "请输入括号序列(输入q退出):" << endl;
    while (1)
    {
        string str;
        cin >> str;
        if (str == "q")
        {
            cout << "退出程序" << endl;
            break;
        }
        if (isMatch(str))
            cout << "括号匹配" << endl;
        else
            cout << "括号不匹配" << endl;
    }
    system("pause");
    return 0;
}