/*
思路：完全二叉树最多只有最下面两层的结点的度数可以小于2，
并且最下面一层的叶子结点都依次排列在该层最左边的位置上，
所以除了最后一层应该都排满结点，且最后一层若有空结点应该在右边
因此如果按层次遍历，当出现空结点时，后面应该也全部为空，否则不满足条件
*/
#include "../ch7/BTree.cpp"
#include <queue>
bool isCombt(BTree &bt)
{
    if (bt.r == NULL) //若根节点为空则为空树，直接返回true
        return true;
    queue<BTNode *> qu; //定义一个队列qu
    qu.push(bt.r);
    while (!qu.empty()) //先利用队列层次遍历直到到出现空结点或把二叉树遍历完
    {
        BTNode *p = qu.front();
        qu.pop();      //出队一个结点
        if (p == NULL) //出现空结点则跳出
            break;
        qu.push(p->lchild); //将结点的左右孩子结点放进队列用于后续判断是否为空
        qu.push(p->rchild);
    }
    while (!qu.empty()) //如果上面循环是因为出现空结点而结束则开始检查后面是否全为空
    {
        BTNode *p = qu.front();
        qu.pop();
        if (p != NULL) //空结点后续仍有空结点则不是完全二叉树，返回false
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
    cout << (isCombt(bt1) ? "是二叉树" : "不是二叉树") << endl;
    bt2.CreateBTree(s2);
    bt2.DispBTree();
    cout << (isCombt(bt2) ? "是二叉树" : "不是二叉树") << endl;
    system("pause");
    return 0;
}