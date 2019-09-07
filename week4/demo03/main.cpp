#include "iostream"

class Complex
{
    double real, imag;

public:
    Complex(double r, double i) : real(r), imag(i){};
    Complex operator+(double r);
    friend Complex operator+(double r, const Complex & c);
};
Complex Complex::operator+(double r)
{ //能解释 c+5
    return Complex(real + r, imag);
}

// 普通函数作为友元函数来访问私有成员变量或者函数
Complex operator+(double r, const Complex & c){
    return Complex(r + c.real, c.imag); 
};

int main(int argc, char const *argv[])
{
    Complex c1(2,4);
    c1 + 5; // 这个执行成员变量的
    5 + c1; // 这个执行友元函数
    return 0;
}
