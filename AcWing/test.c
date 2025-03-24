#include<stdio.h>

typedef struct {
    int a[2];
    double b ;
} struct_t;

double fun(int i){
    volatile struct_t s;
    s.b = 3.14;
    s.a[i] = 1073741824; // 0x40000000
    return s.b;
}

int main(){
    int i;
    scanf("%d",&i);
    printf("fun(%d):%lf",i,fun(i));
    return 0;
}