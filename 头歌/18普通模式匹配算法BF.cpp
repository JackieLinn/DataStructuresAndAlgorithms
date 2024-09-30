#include <stdio.h>
#include <string.h>

int mate(char *B, char *A) {
    int lenB = strlen(B);
    int lenA = strlen(A);
    int count = 0, sum = 0;

    for (int i = 0; i <= lenB - lenA; i++) {
        int j;
        for (j = 0; j < lenA; j++) {
            if (B[i + j] != A[j]) {
                sum++;
                break;
            }
        }

        if (j == lenA) {
            sum--;
            count++;
        }
    }

    return sum - 1;
}

int main() {
    int number = mate("ababcabcacbab", "abcac");
    printf("%d", number);
    return 0;
}
