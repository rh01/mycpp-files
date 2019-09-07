#include "iostream"

class String
{
private:
    char *p;

public:
    String()
    {
        p = new char[10];
    };
    ~String()
    { // 析构函数
        delete[] p;
    };
};

class Ctest
{
private:
    /* data */
public:
    Ctest(/* args */);
    ~Ctest();
};

Ctest::Ctest(/* args */)
{
}

Ctest::~Ctest()
{
    std::cout << "析构函数被调用" << std::endl;
}

int main(int argc, char const *argv[])
{
    /**
     * 一个类最多只能有一个析构函数。
     * 
     * 名字与类名相同
     * 在前面加 ~
     * 没有参数和返回值
     * 
     * 对象消亡，析构函数自动调用
     * 如果定义类时，编译器生成缺省的析构函数
     * 
     * 对于对象数组的生命期结束时，对象数组的每一个元素都会被调用。
     * 
     * delete运算符会导致析构函数的调用
     */
    // Ctest array[2];
    std::cout << "step1" << std::endl;
    Ctest *pTest;
    pTest = new Ctest;
    delete pTest;
    std::cout << "step2" << std::endl;
    pTest = new Ctest[4];
    delete []pTest;

    return 0;
}
