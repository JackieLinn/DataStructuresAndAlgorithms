#include <iostream>
#include <algorithm>  // for std::find

using namespace std;

class intSet {
public:
    intSet() : ElementNum(0) {}  // 构造0个元素的空整数集合对象

    intSet(int a[], int size) : ElementNum(size) {  // 构造size个元素的整数集合对象
        for (int i = 0; i < size; ++i) {
            element[i] = a[i];
        }
    }

    void Clear() {  // 清空整数集合元素
        ElementNum = 0;
    }

    bool IsEmpty() const {  // 判断整数集合是否为空
        return ElementNum == 0;
    }

    bool IsMemberOf(int a) const {  // 判断元素a是否在整数集合中
        return std::find(element, element + ElementNum, a) != element + ElementNum;
    }

    intSet &operator+(int a) {  // 往集合中增加一个元素
        if (!IsMemberOf(a) && ElementNum < 100) {
            element[ElementNum++] = a;
        }
        return *this;
    }

    intSet &operator-(int a) {  // 从集合中删除一个元素
        for (int i = 0; i < ElementNum; ++i) {
            if (element[i] == a) {
                for (int j = i; j < ElementNum - 1; ++j) {
                    element[j] = element[j + 1];
                }
                --ElementNum;
                break;
            }
        }
        return *this;
    }

    intSet &operator=(const intSet &set) {  // 整数集合对象间赋值
        if (this != &set) {
            ElementNum = set.ElementNum;
            for (int i = 0; i < ElementNum; ++i) {
                element[i] = set.element[i];
            }
        }
        return *this;
    }

    void display() const {  // 显示整数集合元素
        for (int i = 0; i < ElementNum; ++i) {
            cout << element[i] << " ";
        }
        cout << endl;
    }

private:
    int element[100];  // 整数集合数组
    int ElementNum;    // 整数集合元素个数
};

int main() {
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int b[6] = {5, 6, 7, 8, 9, 0};
    intSet s1(a, 7), s2, s3;
    s1.display();
    s2 = s1 + 8;
    s2.display();
    s3 = s1 - 3;
    s3.display();

    return 0;
}
