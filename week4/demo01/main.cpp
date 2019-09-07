#include "iostream"

class Complex
{
private:
    double real, image;
public:
    Complex(double r=0.0, double i=0.0)
    {
        real = r;
        image = i;
    };

    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    ~Complex();
};

Complex::~Complex()
{
}

// 成员函数的重载
Complex Complex::operator+(const Complex &c)
{
    return Complex(real + c.real, image + c.image);
};

//  成员函数的重载
Complex Complex::operator-(const Complex &c)
{
    return Complex(real - c.real, image - c.image);
};
// // 外部函数的运算符重载
// Complex operator+(const Complex &a, const Complex &b)
// {
//     return Complex(a.real + b.real, a.image + b.image);
// }

int main(int argc, char const *argv[])
{
    Complex x, y(4.3, 8.2), z(3.3, 1.1);

    x = y + z;
    x = y - z;

    return 0;
}
