/* 思路：参考书上例7.17，在解法3的基础上改动完成，求出每层宽度，取最大值 */
#include "../ch7/BTree.cpp"
#include <queue>
int getWid(BTree &bt)
{
    int wid = 0;      //二叉树宽度，初始化为0
    if (bt.r == NULL) //空树直接返回初始wid=0
        return wid;
    queue<BTNode *> qu; //定义一个队列qu
    qu.push(bt.r);      //根结点进队
    while (!qu.empty()) //队不空循环
    {
        int n = qu.size();          //求出当前层结点个数
        wid = max(n, wid);          //取最大宽度为二叉树宽度
        for (int i = 0; i < n; i++) //出队当前层的n个结点
        {
            BTNode *p = qu.front();
            qu.pop();              //出队一个结点
            if (p->lchild != NULL) //有左孩子时将其进队
                qu.push(p->lchild);
            if (p->rchild != NULL) //有右孩子时将其进队
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
    cout << "的宽度为" << getWid(bt1) << endl;
    system("pause");
    return 0;
}