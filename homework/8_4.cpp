/*
思路：以查找函数为基础改动，建立层数变量depth用于存储当前层数，
查找指针p不为空则循环，循环内找到则返回depth，没找到则返回-1
*/
#include "../ch9/BST.cpp" //包含二叉排序树基本运算算法
#include <iomanip>
template <typename T1, typename T2>
int DepthOfK(BSTClass<T1, T2> &bst, T1 k)
{
    int depth = 1; // 存储当前层数
    BSTNode<T1, T2> *p = bst.r;
    while (p != NULL)
    {
        if (k == p->key) // 找到则返回当前层数
            return depth;
        if (k < p->key) // k小于该节点关键字则到左子树里面找
            p = p->lchild;
        else // 大于则到右子树里面找
            p = p->rchild;
        depth++; // 每次层数+1
    }
    return -1; // 没找到则返回-1
}
int main()
{
    vector<int> a = {25, 18, 46, 2, 53, 39, 32, 4, 74, 67, 60, 11};
    vector<int> b = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = a.size();
    cout << " (1)关键字序列(不考虑值)" << endl;
    for (int i = 0; i < n; i++)
        cout << " " << a[i];
    cout << endl;
    BSTClass<int, int> bst;
    cout << " (2)创建BSTbst" << endl;
    bst.CreateBST(a, b);
    cout << " (3)输出BST" << endl;
    cout << "    BST: ";
    bst.DispBST();
    cout << endl;
    cout << " (4)输出关键字层数" << endl;
    for (int i = 0; i < n; i++)
        cout << " 关键字" << setw(2) << a[i] << "的层数: " << DepthOfK(bst, a[i]) << endl;
    system("pause");
    return 0;
}