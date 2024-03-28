/*
思路：利用while循环遍历字符串，当前后两字符相同时平台长度+1，
不同时则说明到了下一个平台，重新开始计算平台长度。
利用变量m储存当前平台长度，变量n储存目前最大平台长度，最后返回n
*/
#include "../ch4/LinkString.cpp"
int LongestSame(LinkString &lst) //设计最大平台长度函数
{
    LinkNode *p = lst.head->next; //指针从首结点开始
    int m = 1, n = 1;
    while (p->next != NULL) //遍历字符串
    {
        if (p->data == p->next->data) //前后两字符相等时m增加
            m++;
        else //出现不同时n取最大值，m归1
        {
            n = max(m, n);
            m = 1;
        }
        p = p->next; // p指向下一个元素
    }
    n = max(m, n); //防止最后一个平台是最大的漏记
    return n;
}
int main()
{
    LinkString s;                  //建立链串对象
    s.StrAssign("abbcdddeefgggg"); //创建测试用串
    s.DispStr();                   //输出串
    cout << "最长平台长度: " << LongestSame(s) << endl;
    system("pause");
    return 0;
}