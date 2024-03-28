/*
思路：节点为空或已经到叶子结点时后面已经没路了返回0，
若只有一个孩子结点为空则只有一条路，返回孩子结点的最小枝长+1
若有左右孩子结点都不为空则取两孩子结点的最小枝长中的最小值+1
*/
#include "../ch7/BTree.cpp"
int getMinlen1(BTNode *b)
{
    if (b == NULL || (b->lchild == NULL && b->rchild == NULL)) //已经到尽头返回0
        return 0;
    if (b->lchild == NULL) //只有一条路就顺着路走，返回孩子结点的最小枝长+1
        return getMinlen1(b->rchild) + 1;
    if (b->rchild == NULL)
        return getMinlen1(b->lchild) + 1;
    //有两条路就选择更短的路，即取两孩子结点的最小枝长中的最小值+1
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
    cout << "的最小枝长为" << getMinlen(bt1) << endl;
    bt2.CreateBTree(s2);
    bt2.DispBTree();
    cout << "的最小枝长为" << getMinlen(bt2) << endl;
    system("pause");
    return 0;
}