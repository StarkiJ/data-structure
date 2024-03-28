/*
author: ZhuoXin Jiang
language: c++
time: Dec. 15th, 2022
小型图书管理系统（综合）:比实现功能更难的是解决希冀
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Book // 建立结构体Book存储图书信息
{
    string title, author, publisher, date;
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
                return true;
            if (title[i] > s.title[i])
                return false;
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

void LibrarySystem()
{
    vector<Book> Library;                  // 建立vector存储Book信息
    string title, author, publisher, date; // 书名，作者，出版社，出版日期

    ifstream fin; // 希冀好像不认freopen("CON", "r", stdin),改用"扁豆"同学分享的方法
    fin.open("books.txt", ios::in);

    /* ofstream outfile;
    outfile.open("ordered.txt"); */

    // freopen("books.txt", "r", stdin); // 从当前目录下的books.txt中读取原始的图书信息（原始书库）
    // freopen("ordered.txt", "w", stdout);
    while (fin >> title)
    {
        fin >> author >> publisher >> date;
        Library.push_back(Book(title, author, publisher, date));
    }
    sort(Library.begin(), Library.end());

    fin.close();
    // fclose(stdin);
    // cin.clear();
    // freopen("CON", "r", stdin);

    Book book;
    int x, len = Library.size();

    while (cin >> x)
    {
        // outfile << "x: " << x << endl;
        switch (x)
        {
        case 1: // 录入
        {
            cin >> title >> author >> publisher >> date;
            // outfile << "title: " << title << endl;
            Library.push_back(Book(title, author, publisher, date));
            sort(Library.begin(), Library.end());
            len++;
            break;
        }
        case 2: // 查找
        {
            cin >> title;
            // outfile << "title: " << title << endl;
            for (int i = 0; i < len; i++)
            {
                book = Library[i];
                if (book.KMPval(title))
                {
                    book.Show();
                }
            }
            break;
        }
        case 3: // 删除
        {
            cin >> title;
            // outfile << "title: " << title << endl;
            for (int i = 0; i < len;)
            {
                // outfile << "i: " << i << " ";
                book = Library[i];
                if (book.KMPval(title))
                {
                    // outfile << "find ";
                    Library.erase(Library.begin() + i);
                    len--;
                }
                else // 这里i++写进for会导致遇到需要连续删除的情况有漏网之鱼
                {
                    i++;
                }
            }
            // outfile << endl;
            break;
        }
        case 0: // 将已更新的图书信息保存到书库中并退出程序
        {
            ofstream outfile; // 虽然希冀认识freopen("ordered.txt", "w", stdout);但为了配套还是改了
            outfile.open("ordered.txt");
            // freopen("ordered.txt", "w", stdout);
            for (int i = 0; i < len; i++)
            {
                book = Library[i];
                // book.Show();
                outfile << left;
                outfile << setw(50) << book.title << setw(20) << book.author << setw(30) << book.publisher << setw(10) << book.date << endl;
            }
            outfile.close();
            // freopen("CON", "w", stdout);
            return;
        }

        default: // 输入无效指令
            cout << "Undefined operation !" << endl;
            break;
        }
    }
}
int main()
{
    LibrarySystem();
    // cout << "You have saved the file and exited the system" << endl;
    system("pause");
    return 0;
}
