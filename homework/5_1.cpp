/*
˼·: ��һ����ʱ�ַ����������ú���ַ������ַ�������nΪ1ʱֱ�Ӹ�����ʱ�ַ�����
����n����1ʱ��������һ���ַ�+ǰn-1���ַ������ý��еݹ�
*/
#include <iostream>
using namespace std;
string Reverse(string s, int n) //������õݹ麯��
{
    string re;     //������ʱ�ַ��������������ú���ַ���
    if (n == 1)    //����n==1ʱֱ�ӽ�Ψһһ���ַ�����re������
        re = s[0]; //ע�����ﲻ��"re = s;"������n > 1ʱ�����
    else           // n > 1ʱ�ݹ鴦�������������һ���ַ�+ǰn-1���ַ�������
        re = s[n - 1] + Reverse(s, n - 1);
    return re; //��󷵻����ú���ַ���
}
int main()
{
    string s = "abcdefg";
    int n = s.length();
    cout << "ԭ�ַ���s: " << s << endl;
    cout << "�����ú�Ϊ: " << Reverse(s, n) << endl;
    system("pause");
    return 0;
}