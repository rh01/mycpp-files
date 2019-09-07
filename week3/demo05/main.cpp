#include "iostream"

class Complex
{
private:
    double real, image;
public:
    Complex(/* args */);
    Complex(Complex & c){
        real = c.real;
        image = c.image;
        std::cout << "拷贝构造函数被调用" << std::endl;
    }
    ~Complex();
};

Complex::Complex(/* args */)
{
}

Complex::~Complex()
{
}

void Func(Complex a1) {

}

int main(int argc, char const *argv[])
{
    /**
     * 拷贝构造函数
     * 只有一个参数，参数为对同类对象的引用。
     * 比如 X::X(X &) 或者 X::X(const X &)
     * 
     * 如果没有定义拷贝构造函数，那么编译器将自动生成默认的拷贝构造函数。 
     * 完成复制的功能。
     * 
     * 如果定义自己的拷贝构造函数，那么默认的拷贝构造函数将不复存在
     */

    Complex c1;
    Complex c2(c1); // 此时的初始化使用了拷贝构造函数，将c2初始化成和c1一样。

    /**
     * 复制构造函数的三个应用场景
     * 1. 使用一个对象去初始化同类的另一个对象
     * 2. 当一个函数的参数为一个类A对象，此时若调用该函数，那么类A的拷贝构造函数将会被调用。
     * 3. 如果函数的返回值是类A的对象是，则函数返回时，A的复制构造函数被调用
     */

    // 情况2.
    Complex a2;
    Func(a2); // 此时将会调用Complex对象的拷贝构造函数, 此时Func中的形参a1就会等于a2
    // std::cout << a2.real << std::endl;

    return 0;
}

