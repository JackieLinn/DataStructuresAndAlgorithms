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
    // 构造函数
    Stack(int s = 10) : size(s), top(-1) {
        if (size <= 0) {
            throw invalid_argument("内存不足，分配空间失败！");
        }
        space = new T[size];
    }

    // 析构函数
    ~Stack() {
        delete[] space;
    }

    // 入栈操作
    bool push(const T &item) {
        if (IsFull()) {
            throw overflow_error("栈已满，无法进行入栈操作！");
        }
        space[++top] = item;
        return true;
    }

    // 出栈操作
    T pop() {
        if (IsEmpty()) {
            throw underflow_error("栈已空，无法进行出栈操作！");
        }
        return space[top--];
    }

    // 判空
    bool IsEmpty() const {
        return top == -1;
    }

    // 判满
    bool IsFull() const {
        return top == size - 1;
    }
};

int main() {
    try {
        // 名字栈及其相关操作
        Stack<string> nameStack(10);
        nameStack.push("yi");
        nameStack.push("Xiao");
        nameStack.push("Lin");
        nameStack.push("毅 ");
        nameStack.push("晓");
        nameStack.push("林");
        cout << "名字为：" << endl;
        while (!nameStack.IsEmpty()) {
            cout << nameStack.pop();
        }
        cout << endl;

        // 学号栈及其相关操作
        Stack<int> idStack(5);
        idStack.push(76);
        idStack.push(11200);
        idStack.push(2022);
        cout << "学号为：" << endl;
        while (!idStack.IsEmpty()) {
            cout << idStack.pop();
        }
        cout << endl;
        // 测试学号栈栈空的出栈操作，是否抛出异常
        idStack.pop();
    } catch (const exception &e) {
        cout << "相关异常：" << e.what() << endl;
    }
    return 0;
}