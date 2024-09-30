#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct course {
    char name[20];    // 课程名
    float score;      // 课程成绩
};

struct stu {
    int num;          // 学号
    char name[20];    // 姓名
    course score[4];  // 课程成绩
};

// 函数的声明
// 添加学生数据
void addStudent();

// 显示学生数据
void showStudent();

// 修改学生数据
void modifyStudent();

// 统计并显示成绩
void calculateScore();

int main() {
    int choice;     // 选择相应的操作
    do {
        cout << "=========================" << endl;
        cout << "0. 退出" << endl;
        cout << "1. 录入学生数据" << endl;
        cout << "2. 显示学生数据" << endl;
        cout << "3. 修改学生数据" << endl;
        cout << "4. 统计并显示成绩" << endl;
        cout << "请选择需要的操作：";
        cin >> choice;
        cout << "=========================" << endl;

        switch (choice) {
            case 0:
                cout << "感谢使用，欢迎下次再来！" << endl;
                break;
            case 1:
                addStudent();
                break;
            case 2:
                showStudent();
                break;
            case 3:
                modifyStudent();
                break;
            case 4:
                calculateScore();
                break;
            default:
                cout << "本次选择无效，请重新输入!" << endl;
        }
    } while (choice != 0);

    return 0;
}

void addStudent() {
    ofstream outfile("student.dat", ios::binary | ios::app);
    if (!outfile) {
        cerr << "无法打开文件！" << endl;
        return;
    }

    int n;      // 表示需要录入的学生的数量
    cout << "请输入需要录入学生的数量：";
    cin >> n;

    for (int i = 0; i < n; i++) {
        stu student{};
        cout << "请输入第" << i + 1 << "个学生的学号：";
        cin >> student.num;
        cout << "请输入第" << i + 1 << "个学生的姓名：";
        cin >> student.name;
        for (int j = 0; j < 4; j++) {
            cout << "请输入课程" << j + 1 << "名称：";
            cin >> student.score[j].name;
            cout << "请输入课程" << j + 1 << "成绩：";
            cin >> student.score[j].score;
        }
        outfile.write(reinterpret_cast<char *>(&student), sizeof(stu));
    }
    outfile.close();
    cout << "学生数据录入完成！" << endl;
}

void showStudent() {
    ifstream infile("student.dat", ios::binary);
    if (!infile) {
        cerr << "无法打开文件！" << endl;
        return;
    }

    stu student{};
    while (infile.read(reinterpret_cast<char *>(&student), sizeof(stu))) {
        cout << "学号： " << student.num << endl;
        cout << "姓名：" << student.name << endl;
        for (int j = 0; j < 4; ++j) {
            cout << "课程" << j + 1 << "名称：" << student.score[j].name << endl;
            cout << "课程" << j + 1 << "成绩：" << student.score[j].score << endl;
        }
        cout << "-----------------------------" << endl;
    }
    infile.close();
}

void modifyStudent() {
    fstream file("student.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cerr << "无法打开文件！" << endl;
        return;
    }

    int num;
    cout << "输入要修改的学生学号：";
    cin >> num;

    stu student{};
    bool isFound = false;
    streampos position;
    while (file.read(reinterpret_cast<char *>(&student), sizeof(stu))) {
        if (student.num == num) {
            isFound = true;
            position = file.tellg() - static_cast<streampos>(sizeof(stu));
            break;
        }
    }

    if (isFound) {
        cout << "请输入学生新的姓名：";
        cin >> student.name;
        for (int j = 0; j < 4; j++) {
            cout << "请输入新的课程" << j + 1 << "名称：";
            cin >> student.score[j].name;
            cout << "请输入新的课程" << j + 1 << "成绩：";
            cin >> student.score[j].score;
        }
        file.seekp(position);
        file.write(reinterpret_cast<char *>(&student), sizeof(stu));
        cout << "学生数据修改完成！" << endl;
    } else {
        cout << "未找到该学生，请检查输入是否正确！" << endl;
    }
    file.close();
}

void calculateScore() {
    ifstream infile("student.dat", ios::binary);
    if (!infile) {
        cerr << "无法打开文件！" << endl;
        return;
    }

    vector<stu> students;
    stu s{};
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(stu))) {
        students.push_back(s);
    }

    infile.close();

    if (students.empty()) {
        cout << "没有学生数据" << endl;
        return;
    }

    // 每个学生的平均分、最低分和最高分
    for (const auto &student: students) {
        float total = 0, minScore = student.score[0].score, maxScore = student.score[0].score;
        for (const auto &course: student.score) {
            total += course.score;
            if (course.score < minScore) minScore = course.score;
            if (course.score > maxScore) maxScore = course.score;
        }
        float avg = total / 4;
        cout << "学号：" << student.num << ", 姓名：" << student.name << endl;
        cout << "平均分：" << avg << ", 最低分：" << minScore << ", 最高分：" << maxScore << endl;
        cout << "-----------------------------" << endl;
    }

    // 每门课程的平均分、最低分和最高分
    float totalScores[4] = {0}, minScores[4], maxScores[4];
    for (int i = 0; i < 4; ++i) {
        minScores[i] = students[0].score[i].score;
        maxScores[i] = students[0].score[i].score;
    }

    for (const auto &student: students) {
        for (int i = 0; i < 4; ++i) {
            totalScores[i] += student.score[i].score;
            if (student.score[i].score < minScores[i]) minScores[i] = student.score[i].score;
            if (student.score[i].score > maxScores[i]) maxScores[i] = student.score[i].score;
        }
    }

    cout << "课程统计：" << endl;
    for (int i = 0; i < 4; ++i) {
        float avg = totalScores[i] / students.size();
        cout << "课程" << i + 1 << " 平均分: " << avg << ", 最低分: " << minScores[i] << ", 最高分: " << maxScores[i]
             << endl;
    }
}