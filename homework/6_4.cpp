/*
˼·����ȫ���������ֻ������������Ľ��Ķ�������С��2��
����������һ���Ҷ�ӽ�㶼���������ڸò�����ߵ�λ���ϣ�
���Գ������һ��Ӧ�ö�������㣬�����һ�����пս��Ӧ�����ұ�
����������α����������ֿս��ʱ������Ӧ��Ҳȫ��Ϊ�գ�������������
*/
#include "../ch7/BTree.cpp"
#include <queue>
bool isCombt(BTree &bt)
{
    if (bt.r == NULL) //�����ڵ�Ϊ����Ϊ������ֱ�ӷ���true
        return true;
    queue<BTNode *> qu; //����һ������qu
    qu.push(bt.r);
    while (!qu.empty()) //�����ö��в�α���ֱ�������ֿս���Ѷ�����������
    {
        BTNode *p = qu.front();
        qu.pop();      //����һ�����
        if (p == NULL) //���ֿս��������
            break;
        qu.push(p->lchild); //���������Һ��ӽ��Ž��������ں����ж��Ƿ�Ϊ��
        qu.push(p->rchild);
    }
    while (!qu.empty()) //�������ѭ������Ϊ���ֿս���������ʼ�������Ƿ�ȫΪ��
    {
        BTNode *p = qu.front();
        qu.pop();
        if (p != NULL) //�ս��������пս��������ȫ������������false
            return false;
    }
    return true;
}
int main()
{
    string s1 = "A(B(D(G,H)),C(E(I),F))",
           s2 = "A(B(D),C(E,F(H)))";
    BTree bt1, bt2;
    bt1.CreateBTree(s1);
    bt1.DispBTree();
    cout << (isCombt(bt1) ? "�Ƕ�����" : "���Ƕ�����") << endl;
    bt2.CreateBTree(s2);
    bt2.DispBTree();
    cout << (isCombt(bt2) ? "�Ƕ�����" : "���Ƕ�����") << endl;
    system("pause");
    return 0;
}