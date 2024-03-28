/*
思路: 找到子串t最后一次出现的位置，为减少前面多余的对比，
干脆基于KMP算法改为倒过来从后往前比对,即可求得结果
*/
#include "../ch4/SqString.cpp"
void GetNextval2(SqString &t, int *nextval2)
{
    int j = t.length - 1, k = t.length; //初始化j,k从后面开始
    nextval2[t.length - 1] = t.length;  //默认最后一个为t.length
    while (j >= 0)                      //从后往前循环到头
    {
        if (k == t.length || t.data[j] == t.data[k])
        {
            j--; // j,k前进一位
            k--;
            if (t.data[j] != t.data[k]) //不相等时直接赋值
                nextval2[j] = k;
            else //相等时跳过减少不必要比对
                nextval2[j] == nextval2[k];
        }
        else //与KMP算法同理，不同则k回退
            k = nextval2[k];
    }
}
int KMPval2(SqString &s, SqString &t)
{
    int i = s.length - 1, j = t.length - 1; //从最后面开始
    int *nextval2 = new int[j + 1];
    GetNextval2(t, nextval2); //求出nextval2数组
    while (i >= 0 && j >= 0)
    {
        if (j == t.length || s.data[i] == t.data[j])
        {
            i--; // j,k前进一位
            j--;
        }
        else
            j = nextval2[j];//i不变，j回退
    }
    if (j < 0)
        return i + 1;
    else
        return -1;
}
int main()
{
    SqString s1, s2, t1, t2;
    s1.StrAssign("abcdabcd");
    t1.StrAssign("abc");
    cout << "s1: ";
    s1.DispStr();
    cout << "t1: ";
    t1.DispStr();
    cout << "t1最后一次出现位置: " << KMPval2(s1, t1) << endl;

    s2.StrAssign("aaaaa");
    t2.StrAssign("aaa");
    cout << "s2: ";
    s2.DispStr();
    cout << "t2: ";
    t2.DispStr();
    cout << "t2最后一次出现位置: " << KMPval2(s2, t2) << endl;

    system("pause");
    return 0;
}