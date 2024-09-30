#include <stdio.h>
#include <stdlib.h>

/*
1 0 1 0 0 0
1 1 1 0 0 0
0 0 1 1 1 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 1
*/

typedef int T;

struct SeqStack {
    T *row; // 行
    T *col; //列
    int top; // 栈顶元素编号
    int max; // 最大节点数
};

/*创建一个栈*/
SeqStack *SS_Create(int maxlen) {
    SeqStack *ss = (SeqStack *) malloc(sizeof(SeqStack));
    ss->col = (T *) malloc(maxlen * sizeof(T));
    ss->row = (T *) malloc(maxlen * sizeof(T));
    ss->top = -1;
    ss->max = maxlen;
    return ss;
}

/*释放一个栈*/
void SS_Free(SeqStack *ss) {
    free(ss->row);
    free(ss->col);
    free(ss);
}

/*清空一个栈*/
void SS_MakeEmpty(SeqStack *ss) {
    ss->top = -1;
}

bool SS_IsFull(SeqStack *ss)
// 判断栈是否为满。为满返回true，否则返回false。
{

    return ss->top + 1 >= ss->max;

}

bool SS_IsEmpty(SeqStack *ss)
// 判断栈是否为空。为空返回true，否则返回false。
{

    return ss->top < 0;
}

int SS_Length(SeqStack *ss)
// 获取栈元素个数
{
    return ss->top + 1;
}

bool SS_Push(SeqStack *ss, T x, T y)
// 将元素x进栈，若满栈则无法进栈，返回false，否则返回true
{
    // 请在这里补充代码，完成本关任务
    if (SS_IsFull(ss)) {
        return false;
    }
    ss->top++;

    ss->row[ss->top] = x;
    ss->col[ss->top] = y;
    return true;
}

bool SS_Pop(SeqStack *ss, T &x, T &y)
// 出栈的元素放入item。若出栈成功(栈不为空)，则返回true；否则(空栈)，返回false。
{
    if (SS_IsEmpty(ss)) {
        return false;
    }
    x = ss->row[ss->top];
    y = ss->row[ss->top];
    ss->top--;
    return true;
}

/*获取栈顶元素放入item中,空栈则返回false*/
bool SS_Top(SeqStack *ss, T &x, T &y) {
    if (SS_IsEmpty(ss)) {
        return false;
    }
    x = ss->row[ss->top];
    y = ss->col[ss->top];
    return true;
}

/*从栈底到栈顶打印出所有元素*/
void SS_Print(SeqStack *ss) {
    if (SS_IsEmpty(ss)) {
        printf("stack data: Empty!\n");
        return;
    }

    int curr = 0;
    while (curr <= ss->top) {
        printf("(%d,%d)", ss->row[curr], ss->col[curr]);
        curr++;
    }
}

//得到迷宫路径,maze为迷宫地图,1表示通路,0表示墙
void GetPath(SeqStack *ss, int maze[][6]) {

    /****begin*******/

    int dx[] = {1, 0, -1, 0}; // 右，下，左，上
    int dy[] = {0, 1, 0, -1};
    int startX = 0, startY = 0;
    int endX = 5, endY = 5;
    // 起始位置入栈
    SS_Push(ss, startX, startY);

    while (!SS_IsEmpty(ss)) {
        int currentX, currentY;
        SS_Top(ss, currentX, currentY);

        if (currentX == endX && currentY == endY) {
            // 寻找路径
            SS_Print(ss);
            return;
        }

        bool found = false;
        for (int i = 0; i < 4; i++) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];

            if (newX >= 0 && newX < 6 && newY >= 0 && newY < 6 && maze[newX][newY] == 1) {
                maze[newX][newY] = 0; // 已走过的进行标记
                SS_Push(ss, newX, newY);
                found = true;
                break;
            }
        }

        if (!found) {
            // 没有可走的路
            SS_Pop(ss, currentX, currentY);
        }
    }

    /*******end******/
    SS_Print(ss);
}

int main() {
    int maze[6][6];
    SeqStack *ss = SS_Create(10);
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            scanf("%d", &maze[i][j]);
    GetPath(ss, maze);
    return 0;
}