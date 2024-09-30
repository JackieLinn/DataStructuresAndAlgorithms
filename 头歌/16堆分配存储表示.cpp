#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* a1 = NULL;
    char* a2 = NULL;
    a1 = (char*)malloc(10 * sizeof(char));
    strcpy(a1, "Hello"); // 将字符串 "Hello" 复制给 a1
    a2 = (char*)malloc(10 * sizeof(char));
    strcpy(a2, "World");
    int lengthA1 = strlen(a1); // a1 串的长度
    int lengthA2 = strlen(a2); // a2 串的长度

    /**** 请在下方补全代码 ****/
    /************* begin ************/

    // 为连接后的字符串分配足够的内存（包括 '\0'）
    char* result = (char*)malloc((lengthA1 + lengthA2 + 1) * sizeof(char));

    // 将 a1 和 a2 连接到 result 中
    strcpy(result, a1);
    strcat(result, a2);

    // 释放 a1 和 a2 的内存
    free(a1);
    free(a2);

    // 将 a1 指向 result
    a1 = result;

    /************* end **************/

    printf("%s", a1);

    // 用完动态数组要立即释放
    free(a1);

    return 0;
}
