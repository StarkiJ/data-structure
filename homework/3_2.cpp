/*
˼·: ��3_1ͬ������forѭ�������ַ�������ǰ�����ַ���ͬʱ��ֵ�Ӵ�����+1��
��ͬʱ��˵��������һ����ֵ�Ӵ������¿�ʼ�����ֵ�Ӵ����ȡ�
���ñ���m���浱ǰ��ֵ�Ӵ����ȣ�t���浱ǰ��ĵ�ֵ�Ӵ�
��ͬ��������Ϊ�˱��ⳤ��Ϊ1��������������t�ĸ�ֵ��else�Ƶ�if���棬ֻ�д��ڵ�ֵ�Ӵ�ʱ�Żḳֵ
*/
#include "../ch4/SqString.cpp"
SqString &Longestst(SqString &s) //������ֵ�Ӵ�������ע�ⲻҪ©����"&"��ǰ��©�˺���"="�����⣬����©�˻��ظ�����
{
    int m = 1;                             //��ֵ�Ӵ�����(m=1ʱû�е�ֵ�Ӵ�)
    static SqString t;                     //��Ȼ��֪��Ϊʲô�����ǲ��þ�̬�ᱨ��
    t.StrAssign("");                       //ֻ���Ⱦ�̬���ֶ���ʼ��
    for (int i = 0; i < s.length - 1; i++) //�����ַ���
    {
        if (s.data[i] == s.data[i + 1]) //�������ַ����ʱ���ڵ�ֵ�Ӵ�
        {
            m++;              //��ֵ�Ӵ�����+1
            if (m > t.length) //ͨ����ǰ��ֵ�Ӵ�����m��t�ĳ��ȱȽ��ж��Ƿ���ҪΪt��ֵ
                t = s.SubStr(i + 2 - m, m);
        }
        else //��ͬ��m��1
            m = 1;
    }
    return t;
}
int main()
{
    SqString s1, s2, s3, s4;        //����˳�򴮶���
    s1.StrAssign("abbcdddeefgggg"); //�������ַ���1���������ֵ�Ӵ�
    s1.DispStr();
    cout << "���ֵ�Ӵ�: ";
    s2 = Longestst(s1);
    s2.DispStr();
    s3.StrAssign("abcdefg"); //�������ַ���2�����ؿմ�
    s3.DispStr();
    cout << "���ֵ�Ӵ�: ";
    s4 = Longestst(s3);
    s4.DispStr();
    system("pause");
    return 0;
}