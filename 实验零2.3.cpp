//
//  main.cpp
//  数据结构个人实验
//
//  Created by 沈博南 on 2017/12/13.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Course {
public:
    Course(const string &Id="", const string &Name="", int Credit=0)
    : id(Id), name(Name), credit(Credit) {}
    friend ostream & operator<<(ostream &out, const Course &c) {
        out << c.id << '\t' << setw(20)<< left << c.name
        << '\t' << c.credit;
        return out; }
private:
    string id, name; int credit;
};

class Student {
public:
    // 课程编号、课程名称 // 课程的学分
    Student(const string &Id="", const string &Name="", int Num=0, const Course *array=NULL); // 1 构造函数
    Student(const Student &s); // 2 拷贝构造函数
    virtual ~Student(); // 3 析构函数
    void Set(const string &Id, const string &Name);
    // 4 设置(修改)学生的学号、姓名
    void Set(int Num, const Course *array, const double *Score); // 5 设置(修改)学生所选课程、各课程成绩
    Student & operator=(const Student &s) // 赋值运算符函数
    {
        if(&s==this) return *this;
        if(course!=NULL) delete [] course; if(score!=NULL) delete [] score;
        id = s.id;
        name = s.name;
        if(s.num==0 || s.course==NULL || s.score==NULL) {
            num = 0;
            course = NULL;
            score = NULL;
        }
        else
        {
            num = s.num;
            course = new Course[num]; score = new double[num]; for(int i=0; i<num; i++) {
                course[i] = s.course[i];
                score[i] = s.score[i];
            }
        }
        return *this; }
    friend ostream & operator<<(ostream &out, const Student
                                &s) {
        // 重载输出运算符(友元)函数
        out << "学号: " << s.id << ", 姓名: " << s.name << endl; for(int i=0; i<s.num; i++)
            out << s.course[i] << '\t' << s.score[i] << '\t' <<
            endl;
        return out;
    } private:
    string id, name; int num;
    Course *course; double *score;
};

Student::Student(const string &Id, const string &Name, int Num, const Course *array)
:id(Id),name(Name),num(Num),course(NULL),score(NULL)
{
    if(num==0){
        ;
    }
    else
    {
        course = new Course[num];
        score = new double[num];
        for(int i=0; i<num; i++) {
            course[i] = array[i];
            score[i] = 0;
        }
    }
}

Student::Student(const Student &s)
{
    *this = s;
}

Student::~Student()
{
    if(course!=NULL) delete [] course;
    if(score!=NULL) delete [] score;
}

void Student::Set(const string &Id, const string &Name)
{
    id = Id;
    name = Name;
}


void Student::Set(int Num, const Course *array, const double *Score)
{
    if(course!=NULL) delete [] course;
    if(score!=NULL) delete [] score;
    if(Num==0 || array==NULL || Score==NULL) {
        num = 0;
        course = NULL;
        score = NULL;
    }
    else
    {
        num = Num;
        course = new Course[num];
        score = new double[num];
        for(int i=0; i<num; i++) {
            course[i] = array[i];
            score[i] = Score[i];
        }
    }
}

int main() {
    // 学生的学号、姓名
    // 本学期所选课程数量
    // 具体的课程信息所占资源空间的地址 // 各课程的成绩
    Course array[] = {Course("08305121", "面向对象程序设计", 5), Course("08305071", "数字逻辑 A", 5),
        Course("08305072", "数字逻辑实验", 1), Course("01034119", "大学物理(3)", 4),
        
        Course("03004403", "大学英语 D 级(4)",4)};
        double score[] = {90, 85, 80, 75, 80};
        int n = sizeof(array)/sizeof(*array);
        Student Zhang("16123721", "张三", n, array), Li;
        cout << Zhang << '\n' << Li << "===========" << endl; Zhang.Set(n, array, score);
        Li.Set("16127890", "李四");
        Li.Set(3, array, score);
        cout << Zhang << '\n' << Li << endl;
        return 0;
    
}
