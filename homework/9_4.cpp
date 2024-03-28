/*˼·���ο��������򷨼���*/
#include <iostream>
#include <vector>
using namespace std;
struct Student // ����ѧ�����
{
    string name;
    int classnum;
    Student *next;
    Student() : next(NULL) {}          // ���캯��
    Student(string name, int classnum) // ���ع��캯��
    {
        this->name = name;
        this->classnum = classnum;
        next = NULL;
    }
    void Show()
    {
        cout << classnum << " " << name << endl;
    }
};
void disp(Student *school)
{
    Student *p = school->next;
    while (p != NULL)
    {
        p->Show();
        p = p->next;
    }
}
void SortTimen(Student *school, int c)
{
    Student *front[c], *rear[c]; // ÿ���༶����������
    Student *p, *t;              // ������ָ��
    for (int i = 0; i < c; i++)  // ��ʼ���������ס�βָ��
        front[i] = rear[i] = NULL;
    p = school->next;
    t = school;
    while (p != NULL) // ��ѧ����������༶
    {
        int k = p->classnum;
        if (front[k] == NULL) // ��һ��ͬѧֱ�Ӹ�front
        {
            front[k] = p;
            rear[k] = p;
        }
        else // �����ͬѧ���ڰ�����һ��ͬѧ����
        {
            rear[k]->next = p;
            rear[k] = p;
        }
        p = p->next;
    }
    for (int i = 0; i < c; i++) // �Ѹ���ͬѧ������
    {
        if (front[i] != NULL)//������ѧ���򽫰༶�ӵ�ѧУ��������
        {
            t->next = front[i];
            t = rear[i];
        }
    }
    t->next = NULL;//���ָ��NULL
}
int main()
{
    vector<Student> sch;
    sch.push_back(Student("С��", 5));
    sch.push_back(Student("С��", 5));
    sch.push_back(Student("С��", 5));
    sch.push_back(Student("����", 4));
    sch.push_back(Student("����", 4));
    sch.push_back(Student("�ͻ���", 3));
    sch.push_back(Student("��Ұ��", 3));
    sch.push_back(Student("����ǿ", 2));
    sch.push_back(Student("С����", 0));
    int n = sch.size();
    Student *school = new Student();
    Student *r = school;        // rʼ��ָ��β���,��ʼʱָ��ͷ���
    for (int i = 0; i < n; i++) // ѭ���������ݽ��
    {
        r->next = &sch[i];
        r = &sch[i];
    }
    r->next = NULL; // ��β����next����ΪNULL
    cout << "��ʼѧ���������У�" << endl;
    disp(school);
    SortTimen(school, 6);
    cout << "������ѧ��������" << endl;
    disp(school);
    system("pause");
    return 0;
}