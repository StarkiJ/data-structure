/* ˼·���ο�������7.17���ڽⷨ3�Ļ����ϸĶ���ɣ����ÿ���ȣ�ȡ���ֵ */
#include "../ch7/BTree.cpp"
#include <queue>
int getWid(BTree &bt)
{
    int wid = 0;      //��������ȣ���ʼ��Ϊ0
    if (bt.r == NULL) //����ֱ�ӷ��س�ʼwid=0
        return wid;
    queue<BTNode *> qu; //����һ������qu
    qu.push(bt.r);      //��������
    while (!qu.empty()) //�Ӳ���ѭ��
    {
        int n = qu.size();          //�����ǰ�������
        wid = max(n, wid);          //ȡ�����Ϊ���������
        for (int i = 0; i < n; i++) //���ӵ�ǰ���n�����
        {
            BTNode *p = qu.front();
            qu.pop();              //����һ�����
            if (p->lchild != NULL) //������ʱ�������
                qu.push(p->lchild);
            if (p->rchild != NULL) //���Һ���ʱ�������
                qu.push(p->rchild);
        }
    }
    return wid;
}
int main()
{
    string s1 = "A(B(D(,G)),C(E,F))";
    BTree bt1;
    bt1.CreateBTree(s1);
    bt1.DispBTree();
    cout << "�Ŀ��Ϊ" << getWid(bt1) << endl;
    system("pause");
    return 0;
}