#include "iostream"

class Complex
{
private:
    /* data */
public:
    double real, image;
    Complex(int r)
    { // 类型转换构造函数
        std::cout << "构造函数被调用" << std::endl;
        real = r;
        image = 0;
    };
    Complex(double r, double i)
    {
        real = r;
        image = i;
    }
    ~Complex();
};

Complex::~Complex()
{
}

int main(int argc, char const *argv[])
{
    // 类型转换构造函数只有一个参数，另外不是复制构造函数，当使用类型转换构造函数的时候，编译系统会自动调用转换构造函数。
    Complex c1(7, 8);
    Complex c2 = 12; // 初始化，不是转换
    c1 = 9;          // 9被自动转换为一个临时的complex对象
    std::cout << c1.real << "," << c1.image << std::endl;
    return 0;
}
