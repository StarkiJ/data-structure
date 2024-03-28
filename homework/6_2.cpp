/*
˼·���ڵ�Ϊ�ջ��Ѿ���Ҷ�ӽ��ʱ�����Ѿ�û·�˷���0��
��ֻ��һ�����ӽ��Ϊ����ֻ��һ��·�����غ��ӽ�����С֦��+1
�������Һ��ӽ�㶼��Ϊ����ȡ�����ӽ�����С֦���е���Сֵ+1
*/
#include "../ch7/BTree.cpp"
int getMinlen1(BTNode *b)
{
    if (b == NULL || (b->lchild == NULL && b->rchild == NULL)) //�Ѿ�����ͷ����0
        return 0;
    if (b->lchild == NULL) //ֻ��һ��·��˳��·�ߣ����غ��ӽ�����С֦��+1
        return getMinlen1(b->rchild) + 1;
    if (b->rchild == NULL)
        return getMinlen1(b->lchild) + 1;
    //������·��ѡ����̵�·����ȡ�����ӽ�����С֦���е���Сֵ+1
    return (min(getMinlen1(b->lchild), getMinlen1(b->rchild)) + 1); 
}
int getMinlen(BTree &bt)
{
    return getMinlen1(bt.r);
}
int main()
{
    string s1 = "A(B(D(,G)),C(E,F))",
           s2 = "A(B(D(,F),),)";
    BTree bt1, bt2;
    bt1.CreateBTree(s1);
    bt1.DispBTree();
    cout << "����С֦��Ϊ" << getMinlen(bt1) << endl;
    bt2.CreateBTree(s2);
    bt2.DispBTree();
    cout << "����С֦��Ϊ" << getMinlen(bt2) << endl;
    system("pause");
    return 0;
}