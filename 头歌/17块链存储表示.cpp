#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define linkNum 3

typedef struct Link {
    char a[linkNum];
    struct Link *next;
} link;

link *initLink(link *head, char *str);
void displayLink(link *head);

int main() {
    link *head = NULL;
    head = initLink(head, "hello.world");
    displayLink(head);
    return 0;
}

link *initLink(link *head, char *str) {
    int length = strlen(str);
    int num = length / linkNum;
    if (length % linkNum) {
        num++;
    }

    link *temp = NULL;
    link *current = NULL;

    for (int i = 0; i < num; i++) {
        link *newLink = (link *)malloc(sizeof(link));
        for (int j = 0; j < linkNum; j++) {
            if (*str != '\0') {
                newLink->a[j] = *str;
                str++;
            } else {
                newLink->a[j] = '\0';
            }
        }
        newLink->next = NULL;
        if (temp == NULL) {
            temp = newLink;
            head = temp;
        } else {
            temp->next = newLink;
            temp = newLink;
        }
    }

    return head;
}

void displayLink(link *head) {
    link *temp = head;
    while (temp) {
        for (int i = 0; i < linkNum; i++) {
            if (temp->a[i] != '\0') {
                printf("%c", temp->a[i]);
            }
        }
        temp = temp->next;
    }

    // 在输出的最后添加 #
    printf("#\n");
}
