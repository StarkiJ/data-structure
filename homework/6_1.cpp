/*
˼·�����ڵ�Ϊ��ʱΪ����ֱ�ӷ���true���ȶԽ�㶼Ϊ��ʱҲֱ�ӷ���ture������Ϊ����ʣ�����õݹ�ʵ�֣�
����������ߺ����������ұ߱ȶԣ����������ұߺ�����������߱ȶԣ����ȶԽṹ���Գ�ʱ����true
*/
#include "../ch7/BTree.cpp"
bool isSymmetric1(BTNode *l, BTNode *r) //�����ȶԺ���
{
    if (l == NULL && r == NULL) //��Ϊ��ֱ�ӷ���true
        return true;
    if (l == NULL || r == NULL) //ֻ��һ��Ϊ�շ���false
        return false;
    //���߶���Ϊ����ʼ�ݹ飬����������ߺ����������ұ߱ȶԣ����������ұߺ�����������߱ȶ�
    return isSymmetric1(l->lchild, r->rchild) & isSymmetric1(l->rchild, r->lchild);
}
bool isSymmetric(BTree &bt) //�ж϶������Ľṹ�Ƿ�Գƺ���
{
    if (bt.r == NULL) //���ڵ�Ϊ����Ϊ����ֱ�ӷ���true
        return true;
    return isSymmetric1(bt.r->lchild, bt.r->rchild);
}
int main()
{
    string s1 = "A(B(D(,G)),C(E,F))",
           s2 = "A(B(D(,F),),C(,E(G,)))";
    BTree bt1, bt2;
    bt1.CreateBTree(s1);
    bt1.DispBTree();
    cout << (isSymmetric(bt1) ? "�Ľṹ�ǶԳƵ�" : "�Ľṹ���ǶԳƵ�") << endl;
    bt2.CreateBTree(s2);
    bt2.DispBTree();
    cout << (isSymmetric(bt2) ? "�Ľṹ�ǶԳƵ�" : "�Ľṹ���ǶԳƵ�") << endl;
    system("pause");
    return 0;
}