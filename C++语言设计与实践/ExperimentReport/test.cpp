#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template<class T>
class Stack {
private:
    int size;  // 栈空间大小
    int top;   // 栈指针
    T *space;  // 动态数组指针

public:
    Stack(int s = 10) : size(s), top(-1) {
        if (size <= 0) {
            throw invalid_argument("Stack size must be positive");
        }
        space = new T[size];
    }

    ~Stack() {
        delete[] space;
    }

    bool push(const T &item) {
        if (IsFull()) {
            throw overflow_error("Stack is full");
        }
        space[++top] = item;
        return true;
    }

    T pop() {
        if (IsEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return space[top--];
    }

    bool IsEmpty() const {
        return top == -1;
    }

    bool IsFull() const {
        return top == size - 1;
    }

    T peek() const {
        if (IsEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return space[top];
    }
};

// 测试程序
int main() {
    try {
        // 保存名字拼音的栈对象
        Stack<string> nameStack(5);
        nameStack.push("z");
        nameStack.push("h");
        nameStack.push("a");
        nameStack.push("n");
        nameStack.push("g");

        cout << "Name stack:" << endl;
        while (!nameStack.IsEmpty()) {
            cout << nameStack.pop() << " ";
        }
        cout << endl;

        // 保存学号的栈对象
        Stack<int> idStack(5);
        idStack.push(1);
        idStack.push(2);
        idStack.push(3);
        idStack.push(4);
        idStack.push(5);

        cout << "ID stack:" << endl;
        while (!idStack.IsEmpty()) {
            cout << idStack.pop() << " ";
        }
        cout << endl;

        // 测试异常处理
        idStack.pop();  // 试图从空栈中弹出，应该抛出异常

    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

学号： 1
姓名：小明
        课程1名称：计算机组成原理
        课程1成绩：85
课程2名称：数据结构与算法
        课程2成绩：92
课程3名称：离散数学
        课程3成绩：95
课程4名称：数据库概论
        课程4成绩：83
-----------------------------
学号： 2
姓名：小红
        课程1名称：计算机组成原理
        课程1成绩：76
课程2名称：数据结构与算法
        课程2成绩：89
课程3名称：离散数学
        课程3成绩：90
课程4名称：数据库概论
        课程4成绩：92
-----------------------------
学号： 3
姓名：小华
        课程1名称：计算机组成原理
        课程1成绩：86
课程2名称：数据结构与算法
        课程2成绩：75
课程3名称：离散数学
        课程3成绩：89
课程4名称：数据库概论
        课程4成绩：93
-----------------------------
学号： 4
姓名：小芳
        课程1名称：计算机组成原理
        课程1成绩：83
课程2名称：数据结构与算法
        课程2成绩：98
课程3名称：离散数学
        课程3成绩：90
课程4名称：数据库概论
        课程4成绩：86
-----------------------------
学号： 5
姓名：小天
        课程1名称：计算机组成原理
        课程1成绩：82
课程2名称：数据结构与算法
        课程2成绩：87
课程3名称：离散数学
        课程3成绩：94
课程4名称：数据库概论
        课程4成绩：90
-----------------------------
学号： 0
姓名：小强
        课程1名称：计算机组成原理
        课程1成绩：75
课程2名称：数据结构与算法
        课程2成绩：78
课程3名称：离散数学
        课程3成绩：87
课程4名称：数据库概论
        课程4成绩：79
