/*
思路: 用一个临时字符串储存逆置后的字符串，字符串长度n为1时直接赋给临时字符串，
长度n大于1时，变成最后一个字符+前n-1个字符的逆置进行递归
*/
#include <iostream>
using namespace std;
string Reverse(string s, int n) //设计逆置递归函数
{
    string re;     //建立临时字符串用来储存逆置后的字符串
    if (n == 1)    //长度n==1时直接将唯一一个字符赋给re并返回
        re = s[0]; //注意这里不能"re = s;"，否则n > 1时会出错
    else           // n > 1时递归处理，大问题变成最后一个字符+前n-1个字符的逆置
        re = s[n - 1] + Reverse(s, n - 1);
    return re; //最后返回逆置后的字符串
}
int main()
{
    string s = "abcdefg";
    int n = s.length();
    cout << "原字符串s: " << s << endl;
    cout << "被逆置后为: " << Reverse(s, n) << endl;
    system("pause");
    return 0;
}