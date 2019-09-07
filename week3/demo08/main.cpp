#include "iostream"

class Demo
{
private:
    int id;

public:
    Demo(int i)
    {
        id = i;
        std::cout << "id=" << id << " Constructed" << std::endl;
    };
    ~Demo()
    {
        std::cout << "id=" << id << " Deconstructed" << std::endl;
    };
};

Demo d1(1); // 全局对象最后消亡 > static

void Func()
{
    static Demo d2(2); // 静态变量的消亡会在整个程序结束的时候
    Demo d3(3);
    // Demo d7(7); // 按照栈的顺序
    std::cout << "Func" << std::endl;
}

int main(int argc, char const *argv[])
{
    Demo d4(4);
    d4 = 6;
    std::cout << "main" << std::endl;

    {
        Demo d5(5);
    }

    Func();
    std::cout << "main ends" << std::endl;
    return 0;
}
