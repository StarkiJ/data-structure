/*
˼·���Բ��Һ���Ϊ�����Ķ���������������depth���ڴ洢��ǰ������
����ָ��p��Ϊ����ѭ����ѭ�����ҵ��򷵻�depth��û�ҵ��򷵻�-1
*/
#include "../ch9/BST.cpp" //�����������������������㷨
#include <iomanip>
template <typename T1, typename T2>
int DepthOfK(BSTClass<T1, T2> &bst, T1 k)
{
    int depth = 1; // �洢��ǰ����
    BSTNode<T1, T2> *p = bst.r;
    while (p != NULL)
    {
        if (k == p->key) // �ҵ��򷵻ص�ǰ����
            return depth;
        if (k < p->key) // kС�ڸýڵ�ؼ�����������������
            p = p->lchild;
        else // ������������������
            p = p->rchild;
        depth++; // ÿ�β���+1
    }
    return -1; // û�ҵ��򷵻�-1
}
int main()
{
    vector<int> a = {25, 18, 46, 2, 53, 39, 32, 4, 74, 67, 60, 11};
    vector<int> b = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = a.size();
    cout << " (1)�ؼ�������(������ֵ)" << endl;
    for (int i = 0; i < n; i++)
        cout << " " << a[i];
    cout << endl;
    BSTClass<int, int> bst;
    cout << " (2)����BSTbst" << endl;
    bst.CreateBST(a, b);
    cout << " (3)���BST" << endl;
    cout << "    BST: ";
    bst.DispBST();
    cout << endl;
    cout << " (4)����ؼ��ֲ���" << endl;
    for (int i = 0; i < n; i++)
        cout << " �ؼ���" << setw(2) << a[i] << "�Ĳ���: " << DepthOfK(bst, a[i]) << endl;
    system("pause");
    return 0;
}