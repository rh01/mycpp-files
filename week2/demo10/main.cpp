#include "iostream"


inline int Max(int a, int b){
    if (a >b) return a;
    return b;
}

// 重载
inline int Max(double a, double b){
    if (a >b) return a;
    return b;
}


// 这个是重复定义
// inline double Max(double a, double b){
//     if (a >b) return a;
//     return b;
// }


int main(int argc, char const *argv[])
{
    // 内联函数
    // 为了减少函数调用的开销，把整个函数的代码插入到调用语句处，而不产生调用函数的语言
    // 在函数定义前面加inline关键字，即可定义内联函数

    int x = 3, y =4;
    int k = Max(x, y);
    std::cout << k << std::endl;


    double x1 = 4.0, x2 = 5.4444;
    double x3 = Max(x1, x2);
    std::cout << x3 << std::endl;


    // 函数重载
    // 函数名相同，参数个数或者类型不同，若返回值不同，这个不是重载，而是重新定义


    return 0;
}
