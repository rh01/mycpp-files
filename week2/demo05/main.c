#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char const *argv[])
{
    // & 实例
    printf("%d\n", 23 & 21);

    // & 实例
    printf("%d\n", 23 & 21);

    // 将n的低8位权为0，其余位不变
    printf("%d\n", 100 & 0xffffff00);

    // 如果n的类型是short类型的，那么此时需要怎么做呢？
    printf("%d\n", 100 & 0xff00);

    // |按位或运算 ^按位异或
    // << 左移 有符号（short, int, long, char）(前面补符号位即补充最高位)和无符号 >> 右移

    return 0;
}
