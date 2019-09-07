#include <iostream>

class Complex
{
private:
    double real, image;
public:
    Complex(double r, double i);
    Complex(double r); // 一个类可以有多个构造函数， 构造函数之间是重载的关系
    ~Complex();
};

Complex::Complex(double r, double i)
{
    real = r; image = i;
}

Complex::~Complex()
{
}


int main(int argc, char const *argv[])
{
    /**
     * 构造函数知识点；
     * 只要有对象生成，构造函数就会自动调用，对象一旦生成，就再也不能在其上执行构造函数
     * 一个类可以有多个构造函数
     * 
     * 构造函数：执行必要的初始化工作
     * 
     */

    // Complex c1; // 缺少构造函数的参数
    // Complex * pc = new Complex; // error， 没有参数
    Complex c1(2); // correct
    Complex c2(2, 4); // correct
    return 0;
}
