#include "../ch3/SqStack.cpp" //引用顺序栈类(和书上写的一样)
void Show(int *a, int n)      //显示数组函数
{
    for (int m = 0; m < n; m++)
    {
        cout << a[m] << " ";
    }
    cout << endl;
}
void Reorder(int *a, int n) //设计重新排序函数
{
    int i = 0, j = 0; //数组的俩下标
    SqStack<int> st;  //建立顺序栈
    while (i < n)     //依次将数组元素压入栈
    {
        st.push(a[i]);
        if (!(a[i] % 2)) //如果是偶数就出栈按顺序放入数组中
        {
            st.pop(a[j]);
            Show(a, n);
            j++;
        }
        i++;
    }
    while (i > j) //把留在栈中的数组元素从后往前放回数组(此时i和j都最后多+1了不用再调整!!!)
    {
        st.pop(a[i - 1]);
        Show(a, n);
        i--;
    }
}
int main()
{
    int n = 8;
    int a[n - 1] = {1, 2, 3, 4, 5, 6, 7, 8}; //建立实验数组
    cout << "实验数组: " << endl;
    Show(a, n);
    cout << "重新排序: " << endl;
    Reorder(a, n);
    system("pause");
    return 0;
}