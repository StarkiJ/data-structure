/*
author: ZhuoXin Jiang
language: c++
time: Dec. 13th, 2022
计算器（表达式计算-表达式树实现）
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct BTNode // 二叉链中结点类型
{
    string data;    // 数据元素
    BTNode *lchild; // 指向左孩子结点
    BTNode *rchild; // 指向右孩子结点
    BTNode()        // 构造函数
    {
        lchild = rchild = NULL;
    }
    BTNode(string s) // 重载构造函数
    {
        data = s;
        lchild = rchild = NULL;
    }
};
vector<string> Trans(string exp) // 将算术表达式exp转换成后缀表达式postexp
{
    vector<string> postexp;        // 为方便存放数值字符串,后缀表达式postexp设为字符串vector
    stack<char> opor;              // 运算符栈
    int i = 0, len = exp.length(); // i为exp的下标,len为exp长度
    char ch;                       // 临时存放读取到的字符
    string e(1, '0');              // 存放需要存入postexp的字符串,为方便char ch转换为string,预设一个位置
    while (i < len)                // exp表达式未扫描完时循环
    {
        ch = exp[i]; // 读取exp
        switch (ch)
        {
        case '(':          // 遇到左括号
            opor.push(ch); // 将左括号直接进栈
            break;
        case ')': // 遇到右括号
            while (!opor.empty() && opor.top() != '(')
            {
                e[0] = opor.top(); // 将栈中'('之前的运算符退栈并存入postexp
                opor.pop();
                postexp.push_back(e);
            }
            opor.pop(); // 将'('退栈
            break;
        case '+': // 遇到加号或者减号
        case '-':
            while (!opor.empty() && opor.top() != '(')
            {
                e[0] = opor.top(); // 将栈中'('之前的所有运算符退栈并存入postexp
                opor.pop();
                postexp.push_back(e);
            }
            opor.push(ch); // 再将'+'或'-'进栈
            break;
        case '*': // 遇到乘号或者除号
        case '/':
            while (!opor.empty() && opor.top() != '(' && (opor.top() == '*' || opor.top() == '/'))
            {
                e[0] = opor.top(); // 将栈中'('之前的所有'*'或'/'依次出栈并存入postexp
                opor.pop();
                postexp.push_back(e);
            }
            opor.push(ch); // 再将'*'或'/'进栈
            break;
        default:
            string d = "";
            while (ch >= '0' && ch <= '9') // 遇到数字
            {
                d += ch; // 提取所有连续的数字字符
                i++;
                if (i < len)
                    ch = exp[i];
                else
                    break;
            }
            i--;                  // 退一个字符
            postexp.push_back(d); // 将数字串存入postexp
            break;
        }
        i++; // 继续处理其他字符
    }
    while (!opor.empty()) // 此时exp扫描完毕,栈不空时循环
    {
        e[0] = opor.top();
        opor.pop(); // 将栈中所有运算符退栈并放入postexp
        postexp.push_back(e);
    }
    return postexp;
}
BTNode *GetTree(vector<string> postexp)
{
    BTNode *exptree;              // 临时构建二叉树结点
    stack<BTNode *> op;           // 临时存放二叉树结点
    int len = postexp.size();     // 后缀表达式长度
    string s;                     // 临时存放读取到的字符串
    char ch;                      // string转换为char
    for (int i = 0; i < len; i++) // 读完为止
    {
        s = postexp[i];             // 读取字符串
        ch = s[0];                  // 字符串首位
        if (ch >= '0' && ch <= '9') // 是数值字符则构建新结点后入栈
        {
            exptree = new BTNode(s);
            op.push(exptree);
        }
        else // 是运算符号则作为栈中两结点的父辈结点,连接后入栈
        {
            BTNode *T1, *T2;
            exptree = new BTNode(s);
            T1 = op.top();
            op.pop();
            T2 = op.top();
            op.pop();
            exptree->lchild = T2;
            exptree->rchild = T1;
            op.push(exptree);
        }
    }
    return op.top(); // 返回连接好的二叉树根节点指针
}
int GetValue(BTNode *exptree) // 采用表达式树来实现表达式计算结果
{
    if (exptree != NULL) // 结点不为空时可以读取
    {
        string s = exptree->data; // 存放结点中字符串
        char ch = s[0];           // 字符串首字符
        int a, b;
        a = GetValue(exptree->lchild); // 左孩子结点数值
        b = GetValue(exptree->rchild); // 右孩子结点数值
        switch (ch)                    // 根据符号运算
        {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;

        default:                              // 是数值则将string转换为int
            int d = ch - '0', len = s.size(); // 将连续的数字符转换成数值存放到d中
            for (int i = 1; i < len; i++)
            {
                ch = s[i];
                d = 10 * d + (ch - '0');
            }
            return d;
            break;
        }
    }
    return 0;
}
void All(string exp) // 整合所有需要实现的内容
{
    vector<string> postexp;
    BTNode *exptree;
    postexp = Trans(exp);
    exptree = GetTree(postexp);
    cout << exptree->data << " " << exptree->lchild->data << " " << exptree->rchild->data << endl;
    cout << GetValue(exptree) << endl;
}
int main()
{
    string exp = "";
    char c;
    while (cin >> c)
    {
        if (c == '=')
            break;
        exp += c;
    }
    All(exp);
    system("pause");
    return 0;
}