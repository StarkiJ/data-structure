#include "../ch2/SqList.cpp" //引用顺序表泛型类(和书上写的一样)
template <typename T>
void Upside_down(SqList<T> &L) // 设计颠倒函数，要记得用"&"
{
    int i = 0;
    while (i < (L.length - 1) / 2) // 通过i是否过半来判断是否交换完毕
    {
        int temp_a, j = L.length - 1 - i; // temp_a为临时参数用来储存i便于交换,j为i对应的交换位置
        temp_a = L.data[i];               // 通过temo_a的辅助进行交换
        L.data[i] = L.data[j];
        L.data[j] = temp_a;
        i++;
    }
}

int main()
{
    int n = 5;
    int a[] = {1, 2, 3, 4, 5}; // 设置实验数组
    SqList<int> L;             // 建立顺序表对象
    L.CreateList(a, n);
    cout << "顺序表: ";
    L.DispList();
    Upside_down(L); // 使用上面的颠倒函数逆置顺序表
    cout << "逆置后: ";
    L.DispList();
    system("pause");
    return 0;
}