#include<iostream>
#include <cstring>

using namespace std;

class Person {
private:
    char name[8];   // 姓名
    char sex[5];   // 性别
    char birth[10]; // 生日

public:
    Person() {}

    Person(char name[], char sex[], char birth[]) {
        strncpy(this->name, name, 7);
        this->name[7] = '\0';
        strncpy(this->sex, sex, 4);
        this->name[4] = '\0';
        strncpy(this->birth, birth, 9);
        this->birth[9] = '\0';
    }

    void Show() {   //显示姓名和生日
        cout << "Name: " << name << ", Birth: " << birth << endl;
    }
};

class Student : public Person {
private:
    char sclass[10];    // 班级
    int no; //学号
    char major[10];  // 专业
    float eng, math;    // 英语、数学成绩

public:
    Student() {}

    Student(char name[], char sex[], char birth[], char sclass[], int no, char major[], float eng, float math)
            : Person(name, sex, birth) {
        strncpy(this->sclass, sclass, 9);
        this->sclass[9] = '\0';
        strncpy(this->major, major, 9);
        this->major[9] = '\0';
        this->no = no;
        this->eng = eng;
        this->math = math;
    }

    void Print() {   //调用Show()显示姓名和生日，输出班级和专业；
        Show();
        cout << "Class: " << sclass << ", Major: " << major << endl;
    }
};

class Employee : public Person {
private:
    char department[10];    // 部门
    char title[10]; // 头衔
    float salary;   // 薪水

public:
    Employee() {}

    Employee(char name[], char sex[], char birth[], char department[10], char title[10], float salary)
            : Person(name, sex, birth) {
        strncpy(this->department, department, 9);
        this->department[9] = '\0';
        strncpy(this->title, title, 9);
        this->title[9] = '\0';
        this->salary = salary;
    }

    void Print() {  //调用Show()显示姓名和生日，输出部门和头衔；
        Show();
        cout << "Department: " << department << ", Title: " << title << endl;
    }
};

int main() {
    int no;
    char name[8], sex[5], birth[10], major[10], class1[10], department[10], title[10];
    float eng, math, salary;
    Student *s;
    Employee *e;

    cout << "Input a student data" << '\n';
    cin >> name >> sex >> birth >> class1 >> no >> major >> eng >> math;
    s = new Student(name, sex, birth, class1, no, major, eng, math);
    cout << "The student information:\n";
    s->Print();

    cout << "Input an employee data" << '\n';
    cin >> name >> sex >> birth >> department >> title >> salary;
    e = new Employee(name, sex, birth, department, title, salary);
    cout << "The employee information:\n";
    e->Print();

    return 0;
}

// 张三 男 2004-3-4 一班 1001 计算机 90.2 92.4
// 李四 男 2000-1-2 办公室 职员 4076.98