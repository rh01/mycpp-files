#include "iostream"

int main(int argc, char const *argv[])
{
    // 动态内存分配
    // C malloc
    // C++ new运算符实现动态内存分配
    // P = new T;
    // P 是类型为T*的指针。
    int *pn1;
    pn1 = new int;
    *pn1 = 5;

    // 2. 分配一个数组
    int * pn2;
    int i = 5;
    pn2 = new int[i * 2];
    pn2[1] = 10;
    // pn2[100] = 20; // 编译没有问题，运行时导致数组越界
    return 0;

    // new运算符的返回值类型
    // new T
    // new T[N]
    // 这两个的返回值的类型都是 T *

    // 动态分配的内存空间，需要使用delete运算符进行释放
    int *p = new int;
    *p = 5;
    delete p;
    // delete p; // 导致异常，一片空间不能被delete多次

    // 释放动态分配的数组, delete []p
    int *pp = new int[20];
    pp[0] =1;
    delete []pp;
}
