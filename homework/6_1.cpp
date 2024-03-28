/*
思路：根节点为空时为空树直接返回true，比对结点都为空时也直接返回ture，都不为空则剩下利用递归实现，
左子树的左边和右子树的右边比对，左子树的右边和右子树的左边比对，当比对结构都对称时返回true
*/
#include "../ch7/BTree.cpp"
bool isSymmetric1(BTNode *l, BTNode *r) //两结点比对函数
{
    if (l == NULL && r == NULL) //都为空直接返回true
        return true;
    if (l == NULL || r == NULL) //只有一个为空返回false
        return false;
    //两边都不为空则开始递归，左子树的左边和右子树的右边比对，左子树的右边和右子树的左边比对
    return isSymmetric1(l->lchild, r->rchild) & isSymmetric1(l->rchild, r->lchild);
}
bool isSymmetric(BTree &bt) //判断二叉树的结构是否对称函数
{
    if (bt.r == NULL) //根节点为空则为空树直接返回true
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
    cout << (isSymmetric(bt1) ? "的结构是对称的" : "的结构不是对称的") << endl;
    bt2.CreateBTree(s2);
    bt2.DispBTree();
    cout << (isSymmetric(bt2) ? "的结构是对称的" : "的结构不是对称的") << endl;
    system("pause");
    return 0;
}