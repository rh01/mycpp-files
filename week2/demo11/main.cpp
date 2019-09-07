#include "iostream"


void func(int x1, int x2 = 2, int x3 =3){}

int main(int argc, char const *argv[])
{
    // 函数参数，在于提高程序的可扩充性。
    func(10);
    func(10,8);
    // func(10,,8); // 编译错误，只能最右边的连续若干个参数缺省
    return 0;
}
