#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Book // 建立结构体Book存储图书信息
{
    string title, author, publisher;
    string date;
    Book(){};                                                        // 默认构造函数
    Book(string title, string author, string publisher, string date) // 构造函数
    {
        this->title = title;
        this->author = author;
        this->publisher = publisher;
        this->date = date;
    }
    bool operator<(const Book &s) const // 重载<运算符
    {
        int n = title.size(), m = s.title.size();
        int len = min(n, m);
        for (int i = 0; i < len; i++)
        {
            if (title[i] < s.title[i])
                return 1;
        }
        return n < m;
    }
    void GetNextval(string t, int *nextval) // 由模式串t求出nextval值
    {
        int j = 0, k = -1;
        int max = t.size() - 1;
        nextval[0] = -1;
        while (j < max)
        {
            if (k == -1 || t[j] == t[k]) // k为-1或比较的字符相等时
            {
                j++;
                k++;
                if (t[j] != t[k]) // 两个字符不相等时
                    nextval[j] = k;
                else
                    nextval[j] = nextval[k];
            }
            else                // 比较的字符不相等时
                k = nextval[k]; // k回退
        }
    }
    bool KMPval(string t) // 改进的KMP算法进行搜索判断
    {
        int n = title.size(), m = t.size();
        int *nextval = new int[m];
        GetNextval(t, nextval); // 求出nextval数组
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (j == -1 || title[i] == t[j])
            {
                i++; // i,j各增1
                j++;
            }
            else
                j = nextval[j]; // i不变,j回退
        }
        if (j >= m)
            return true;
        else
            return false;
    }
    void Show()
    {
        cout << left;
        cout << setw(50) << title << setw(20) << author << setw(30) << publisher << setw(10) << date << endl;
    }
};

bool Shunxu(string s, string t)
{
    int n = s.size(), m = t.size();
    int len = min(n, m);
    for (int i = 0; i < len; i++)
    {
        if ((int)s[i] < (int)t[i])
        {
            cout << s[i] << " " << t[i] << endl;
            cout << "num: " << i << " " << (int)s[i] << " " << (int)t[i] << endl;
            return 1;
        }
        else
        {
            cout << s[i] << " " << t[i] << endl;
            cout << "xxnum: " << i << " " << (int)s[i] << " " << (int)t[i] << endl;
        }
    }
    return n < m;
}
int main()
{
     freopen("books.txt", "r", stdin); // 从当前目录下的books.txt中读取原始的图书信息（原始书库）
     freopen("ordered.txt", "w", stdout);
    string st;
    vector<string> Li;
    while (cin >> st)
        Li.push_back(st);
    cin.clear();
    freopen("CON", "r", stdin);
    int x;
    cin >> x;
    cout << x;

    system("pause");
    return 0;
}