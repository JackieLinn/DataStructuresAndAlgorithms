#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    const int id;       // 学生学号
    string name;        // 学生姓名
    int age;        // 学生年龄
    bool sex;       // 学生性别，true为男，false为女
    const string school = "云南大学";   // 学生所在学校，默认为云南大学
    static int studentNumber;       // 学生数量
public:
    // 默认构造函数，定义学生名字为xxx、年龄为0、学号为学生数量自加1
    Student() : name("xxx"), age(0), sex(true), id(++studentNumber) {
        cout << "调用了默认构造函数！" << endl;
    }

    // 具有默认值的参数化构造函数
    Student(string name, int age = 18, bool sex = true) : name(name), age(age), sex(sex), id(++studentNumber) {
        cout << "调用了具有默认值参数的构造函数！" << endl;
    }

    // 拷贝构造函数，从另一个学生对象复制数据，且学号也会自增
    Student(const Student &other) : name(other.name), age(other.age), sex(other.sex), id(++studentNumber) {
        cout << "调用拷贝构造函数！" << endl;
    }

    // 自定义析构函数，并输出销毁的学生的ID
    ~Student() {
        cout << "调用析构函数，销毁的学生的学号为：" << id << endl;
    }

    // 获取学生数量的函数
    static int getStudentNumber() {
        return studentNumber;
    }

    // 修改名字的函数
    void setName(const string &newName) {
        name = newName;
    }

    // 修改年龄的函数
    void setAge(int newAge) {
        age = newAge;
    }

    // 设置友元函数，显示学生信息
    friend void show(const Student &student);
};

int Student::studentNumber = 0;

// 友元函数定义
void show(const Student &student) {
    cout << "学生信息如下：" << endl;
    cout << "学号：" << student.id << endl;
    cout << "姓名：" << student.name << endl;
    if (student.sex) cout << "性别：" << "男" << endl;
    else cout << "性别：" << "女" << endl;
    cout << "年龄：" << student.age << endl;
    cout << "学校：" << student.school << endl;
}

int main() {
    // 测试默认构造函数
    Student student1;
    show(student1);

    // 测试具有默认值的参数化构造函数
    Student student2("Alice", 20, false);
    show(student2);

    // 测试拷贝构造函数
    Student student3 = student2;
    show(student3);

    // 测试修改名字和年龄的函数
    Student student4("ABC", 16, true);
    show(student4);
    student4.setName("Mike");
    student4.setAge(19);
    show(student4);

    // 测试静态成员方法来获取学生数量
    cout << "学生的数量为：" << Student::getStudentNumber() << endl;
    return 0;
}