#include <stdio.h>
#include "iostream"

// swap函数，使用引用
void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int n1 = 4;
int &SetValue() { return n1; }

int main(int argc, char const *argv[])
{
    // 变量的引用，等价于这个引用，相当于该变量的一个别名
    // 一定要初始化
    // 从一而终
    // 只能引用变量，不能引用其他的值或者表达式
    // Error: int n = 4; int & r = n * 4;
    int n = 4;
    int &r = n;
    r = 5;
    std::cout << r << std::endl;
    std::cout << n << std::endl;
    n = 7;
    std::cout << r << std::endl;
    std::cout << n << std::endl;

    // demo2
    double a = 4, b = 5;
    double &r1 = a;
    double &r2 = b;
    r2 = 10;
    std::cout << a << std::endl; // 输出10
    r1 = b;                      // r1并没有引用b。这里是赋值操作
    std::cout << a << std::endl;

    // 引用作为函数调用的返回值，可以对函数进行赋值操作
    SetValue() = 40; // 此时n1将会改变
    std::cout << n1 << std::endl;

    // 常引用，const关键字,不能通过常引用去修改其引用的内容
    int n3;
    const int & r3 = n3; // 此时r3是一个常引用，r3的类型是const int &
    // Error;
    // r3 = 100; 

    // 常引用与非常引用的转换
    // const T & 和 T &是不同的类型。
    // T & 类型的引用或者T类型的变量可以用来初始化const T &类型的引用
    // const T 类型的常变量和const T & 类型的引用则不能用来初始化 T & 类型的引用，除非使用强制类型转换。

    return 0;
}
