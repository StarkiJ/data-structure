/*
˼·: �ҵ��Ӵ�t���һ�γ��ֵ�λ�ã�Ϊ����ǰ�����ĶԱȣ�
�ɴ����KMP�㷨��Ϊ�������Ӻ���ǰ�ȶ�,������ý��
*/
#include "../ch4/SqString.cpp"
void GetNextval2(SqString &t, int *nextval2)
{
    int j = t.length - 1, k = t.length; //��ʼ��j,k�Ӻ��濪ʼ
    nextval2[t.length - 1] = t.length;  //Ĭ�����һ��Ϊt.length
    while (j >= 0)                      //�Ӻ���ǰѭ����ͷ
    {
        if (k == t.length || t.data[j] == t.data[k])
        {
            j--; // j,kǰ��һλ
            k--;
            if (t.data[j] != t.data[k]) //�����ʱֱ�Ӹ�ֵ
                nextval2[j] = k;
            else //���ʱ�������ٲ���Ҫ�ȶ�
                nextval2[j] == nextval2[k];
        }
        else //��KMP�㷨ͬ����ͬ��k����
            k = nextval2[k];
    }
}
int KMPval2(SqString &s, SqString &t)
{
    int i = s.length - 1, j = t.length - 1; //������濪ʼ
    int *nextval2 = new int[j + 1];
    GetNextval2(t, nextval2); //���nextval2����
    while (i >= 0 && j >= 0)
    {
        if (j == t.length || s.data[i] == t.data[j])
        {
            i--; // j,kǰ��һλ
            j--;
        }
        else
            j = nextval2[j];//i���䣬j����
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
    cout << "t1���һ�γ���λ��: " << KMPval2(s1, t1) << endl;

    s2.StrAssign("aaaaa");
    t2.StrAssign("aaa");
    cout << "s2: ";
    s2.DispStr();
    cout << "t2: ";
    t2.DispStr();
    cout << "t2���һ�γ���λ��: " << KMPval2(s2, t2) << endl;

    system("pause");
    return 0;
}