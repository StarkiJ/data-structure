/*
思路: 和3_1同理，利用for循环遍历字符串，当前后两字符相同时等值子串长度+1，
不同时则说明到了下一个等值子串，重新开始计算等值子串长度。
利用变量m储存当前等值子串长度，t储存当前最长的等值子串
不同在于这里为了避免长度为1的情况被输出，将t的赋值从else移到if里面，只有存在等值子串时才会赋值
*/
#include "../ch4/SqString.cpp"
SqString &Longestst(SqString &s) //设计最长等值子串函数，注意不要漏掉俩"&"，前者漏了后面"="出问题，后者漏了会重复析构
{
    int m = 1;                             //等值子串长度(m=1时没有等值子串)
    static SqString t;                     //虽然不知道为什么，但是不用静态会报错
    t.StrAssign("");                       //只好先静态再手动初始化
    for (int i = 0; i < s.length - 1; i++) //遍历字符串
    {
        if (s.data[i] == s.data[i + 1]) //相邻两字符相等时存在等值子串
        {
            m++;              //等值子串长度+1
            if (m > t.length) //通过当前等值子串长度m与t的长度比较判断是否需要为t赋值
                t = s.SubStr(i + 2 - m, m);
        }
        else //不同则m归1
            m = 1;
    }
    return t;
}
int main()
{
    SqString s1, s2, s3, s4;        //建立顺序串对象
    s1.StrAssign("abbcdddeefgggg"); //测试用字符串1，返回最长等值子串
    s1.DispStr();
    cout << "最长等值子串: ";
    s2 = Longestst(s1);
    s2.DispStr();
    s3.StrAssign("abcdefg"); //测试用字符串2，返回空串
    s3.DispStr();
    cout << "最长等值子串: ";
    s4 = Longestst(s3);
    s4.DispStr();
    system("pause");
    return 0;
}