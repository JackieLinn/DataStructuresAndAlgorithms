#include<stdio.h>


int binarySearch(int array[], int len, int target) {
    /********* Begin *********/

    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            return mid;  // 返回找到的元素位置
        } else if (array[mid] < target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;  // 如果没找到，返回-1

    /********* End *********/
}

int main() {
    int target, len;
    scanf("%d", &target);  //输入整数并赋值给变量a
    scanf("%d", &len);  //输入整数并赋值给变量b
    int a[10];
    int i = 0;
    for (; i < len; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", binarySearch(a, len, target));
    return 0;
}
