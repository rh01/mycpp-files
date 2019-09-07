#include "iostream"

class Location
{
private:
    int x, y;

public:
    Location(/* args */);
    ~Location();
    void Init(int x = 0, int y = 0);   // 带有缺省参数的成员函数
    void valueX(int val) { x = val; }; // 重载函数
    // void valueX(int val=0) { x = val; }; // 重载函数 避免缺省参数带来的二义性，这个例子会带来错误
    int valueX() { return x; } // 重载函数
};

void Location::Init(int X, int y)
{
    x = X;
    y = y;
}

Location::Location(/* args */)
{
}

Location::~Location()
{
}

int main(int argc, char const *argv[])
{
    Location A;
    A.Init(5);
    A.valueX(4);
    std::cout << A.valueX() << std::endl;
    return 0;
}
