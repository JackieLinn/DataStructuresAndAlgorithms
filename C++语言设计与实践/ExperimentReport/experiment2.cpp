#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 定义日期的结构体
struct Date {
    int year;
    int month;
    int day;
};

// 人基类
class People {
protected:
    int id;     // 编号
    string name;    // 姓名
    string sex;     // 性别
    string tel;     // 联系电话
    string e_mail;      // 邮箱
    Date bir;       // 出生日期
public:
    People(int id, string name, string sex, string tel, string e_mail, Date bir)
            : id(id), name(name), sex(sex), tel(tel), e_mail(e_mail), bir(bir) {}

    // 虚成员函数show()
    virtual void show() const {
        cout << "编号：" << id << endl;
        cout << "姓名：" << name << endl;
        cout << "性别：" << sex << endl;
        cout << "联系电话：" << tel << endl;
        cout << "邮箱：" << e_mail << endl;
        cout << "出生日期：" << bir.year << "-" << bir.month << "-" << bir.day << endl;
    }

    virtual ~People() {
        cout << "调用People的析构函数！" << endl;
    }
};

// 老师类
class Teacher : public virtual People {
private:
    string degree;      // 学位
    string dep;     // 部门
public:
    Teacher(int id, string name, string sex, string tel, string e_mail, Date bir,
            string degree, string dep)
            : People(id, name, sex, tel, e_mail, bir), degree(degree), dep(dep) {}

    // 重写基类的虚函数，显示相关信息
    void show() const override {
        People::show();
        cout << "学位：" << degree << endl;
        cout << "部门：" << dep << endl;
    }

    // 重写虚构函数
    ~Teacher() override {
        cout << "调用Teacher的析构函数！" << endl;
    }
};

// 学生类
class Student : public virtual People {
private:
    string sno;     // 学号
    string major;       // 专业
public:
    Student(int id, string name, string sex, string tel, string e_mail, Date bir,
            string sno, string major)
            : People(id, name, sex, tel, e_mail, bir), sno(sno), major(major) {}

    // 重写基类的虚函数，显示相关信息
    void show() const override {
        People::show();
        cout << "学号：" << sno << endl;
        cout << "专业：" << major << endl;
    }

    // 重写虚构函数
    ~Student() override {
        cout << "调用Student的析构函数！" << endl;
    }
};

// 课程信息结构体
struct CourseInfo {
    string name;    // 课程名称
    int id;     // 课程id
    vector<Student> students;   // 利用容器vector，可变数组。对内存管理更加灵活
    Teacher teacher;
};

// 课程类
class Course : public Teacher, public Student {
private:
    CourseInfo cinfo;
public:
    Course(int pid, string pname, string psex, string ptel, string pe_mail, Date pbir,
           string tdegree, string tdep, string ssno, string smajor,
           CourseInfo cinfo)
            : People(pid, pname, psex, ptel, pe_mail, pbir),
              Teacher(pid, pname, psex, ptel, pe_mail, pbir, tdegree, tdep),
              Student(pid, pname, psex, ptel, pe_mail, pbir, ssno, smajor), cinfo(cinfo) {}

    // 重写基类的虚函数，显示相关信息
    void show() const override {
        Teacher::show();
        Student::show();
        cout << "==============================" << endl;
        cout << "课程相关信息：" << endl;
        cout << "课程名称：" << cinfo.name << "\n"
             << "课程id： " << cinfo.id << "\n"
             << "任课老师： \n";
        cinfo.teacher.show();
        cout << "班级学生：\n";
        for (const auto &student: cinfo.students) {
            student.show();
        }
    }

    // 重写虚构函数
    ~Course() override {
        cout << "调用Course的析构函数！" << endl;
    }
};

int main() {
    // 定义需要数量的出生日期
    Date birthDate1 = {1979, 5, 20};
    Date birthDate2 = {2004, 2, 14};
    Date birthDate3 = {2004, 3, 16};
    Date birthDate4 = {1986, 7, 17};
    // 定义一个老师并展示数据
    Teacher teacher1(1, "张三老师", "男", "12345678910", "Zhangsan@163.com",
                     birthDate1, "博士", "软件学院");
    teacher1.show();
    // 定义学生并展示数据
    Student student1(2, "小明", "男", "98765432100", "Xiaoming@163.com",
                     birthDate2, "S001", "软件工程");
    student1.show();
    Student student2(3, "小红", "女", "55556667777", "Xiaohong@163.com",
                     birthDate3, "S002", "网络空间安全");
    student2.show();

    cout << "==============================" << endl;
    // 定义课程信息，把之前定义的老师和学生加进去
    CourseInfo courseInfo = {"数据结构与算法", 101, {student1, student2}, teacher1};
    // 定义一门课程
    Course course(4, "李四老师", "女", "11222333444", "Lisi@163.com", birthDate4, "博士",
                  "信息学院", "S003", "人工智能", courseInfo);
    course.show();
    return 0;
}