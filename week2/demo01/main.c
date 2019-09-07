#include "stdio.h"

void printMin(int a, int b)
{
    if (a < b)
        printf("%d\n", a);
    else
        printf("%d", b);
}

int main()
{
    void (*ptr)(int a, int b); // 定义函数指针
    int x = 3, y = 5;
    ptr = printMin;
    ptr(x, y);
    return 0;
}