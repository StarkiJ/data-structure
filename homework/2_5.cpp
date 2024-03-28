#include "../ch3/SqStack.cpp" //引用顺序栈类(和书上写的一样)
string Reorder(int *a, int n) //设计重新排序函数
{
    string op, ans; //输出用字符串
    char e;
    int i = 0, j = 0; //数组的俩下标
    SqStack<char> st; //建立顺序栈
    while (i < n)     //依次将数组元素压入栈
    {
        st.push(a[i]);
        op += " 进栈"; //将产生操作加入字符串op
        if (a[i] % 2)  //如果是奇数就出栈
        {
            st.pop(e);
            op += " 出栈";    //将产生操作加入字符串op
            ans += (e + '0'); //加入字符串ans
        }
        i++;
    }
    while (!st.empty()) //把留在栈中的元素取出
    {
        st.pop(e);        //出栈
        op += " 出栈";    //将产生操作加入字符串op
        ans += (e + '0'); //出栈数加入字符串ans
    }
    cout << "op: " << op << endl;
    cout << "ans: " << ans << endl;
    return ans;
}
int main()
{
    int n = 8;
    int a[n - 1] = {1, 2, 3, 4, 5, 6, 7, 8}; //建立实验数组
    cout << "实验数组: ";
    for (int m = 0; m < n; m++)
        cout << a[m];
    cout << endl;
    cout << "重新排序..." << endl;
    Reorder(a, n);
    system("pause");
    return 0;
}