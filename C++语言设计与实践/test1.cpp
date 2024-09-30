#include<iostream>
#include<cstring>

using namespace std;

class Person {
private:
    char name[8];   // 姓名
    char sex;   // 性别
    char birth[10]; // 生日

public:
    Person() {}

    Person(const char name[], char sex, const char birth[]) {
        strncpy(this->name, name, 7);
        this->name[7] = '\0';  // Ensure null termination
        this->sex = sex;
        strncpy(this->birth, birth, 9);
        this->birth[9] = '\0';  // Ensure null termination
    }

    void Show() const {    //显示姓名和生日
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
    Student() : Person() {}

    Student(const char name[], char sex, const char birth[], const char sclass[], int no, const char major[], float eng,
            float math)
            : Person(name, sex, birth), no(no), eng(eng), math(math) {
        strncpy(this->sclass, sclass, 9);
        this->sclass[9] = '\0';  // Ensure null termination
        strncpy(this->major, major, 9);
        this->major[9] = '\0';  // Ensure null termination
    }

    void Print() const {   //调用Show()显示姓名和生日，输出班级和专业；
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
    Employee() : Person() {}

    Employee(const char name[], char sex, const char birth[], const char department[], const char title[], float salary)
            : Person(name, sex, birth), salary(salary) {
        strncpy(this->department, department, 9);
        this->department[9] = '\0';  // Ensure null termination
        strncpy(this->title, title, 9);
        this->title[9] = '\0';  // Ensure null termination
    }

    void Print() const {   //调用Show()显示姓名和生日，输出部门和头衔；
        Show();
        cout << "Department: " << department << ", Title: " << title << endl;
    }
};

int main() {
    int no;
    char name[8], sex, birth[10], major[10], class1[10], department[10], title[10];
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

    delete s;
    delete e;

    return 0;
}
