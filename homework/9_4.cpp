/*思路：参考基数排序法即可*/
#include <iostream>
#include <vector>
using namespace std;
struct Student // 构造学生结点
{
    string name;
    int classnum;
    Student *next;
    Student() : next(NULL) {}          // 构造函数
    Student(string name, int classnum) // 重载构造函数
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
    Student *front[c], *rear[c]; // 每个班级单独列链表
    Student *p, *t;              // 遍历用指针
    for (int i = 0; i < c; i++)  // 初始化各链队首、尾指针
        front[i] = rear[i] = NULL;
    p = school->next;
    t = school;
    while (p != NULL) // 将学生分入各个班级
    {
        int k = p->classnum;
        if (front[k] == NULL) // 第一个同学直接给front
        {
            front[k] = p;
            rear[k] = p;
        }
        else // 后面的同学跟在班里上一个同学后面
        {
            rear[k]->next = p;
            rear[k] = p;
        }
        p = p->next;
    }
    for (int i = 0; i < c; i++) // 把各班同学连起来
    {
        if (front[i] != NULL)//班里有学生则将班级加到学校名单后面
        {
            t->next = front[i];
            t = rear[i];
        }
    }
    t->next = NULL;//最后指向NULL
}
int main()
{
    vector<Student> sch;
    sch.push_back(Student("小明", 5));
    sch.push_back(Student("小红", 5));
    sch.push_back(Student("小军", 5));
    sch.push_back(Student("雯雯", 4));
    sch.push_back(Student("乐乐", 4));
    sch.push_back(Student("猛虎王", 3));
    sch.push_back(Student("狂野猩", 3));
    sch.push_back(Student("超人强", 2));
    sch.push_back(Student("小呆呆", 0));
    int n = sch.size();
    Student *school = new Student();
    Student *r = school;        // r始终指向尾结点,开始时指向头结点
    for (int i = 0; i < n; i++) // 循环建立数据结点
    {
        r->next = &sch[i];
        r = &sch[i];
    }
    r->next = NULL; // 将尾结点的next域置为NULL
    cout << "初始学生名单序列：" << endl;
    disp(school);
    SortTimen(school, 6);
    cout << "排序后的学生名单：" << endl;
    disp(school);
    system("pause");
    return 0;
}