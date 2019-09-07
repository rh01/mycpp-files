#include "iostream"

class CSample
{
private:
    /* data */
public:
    CSample();
    CSample(int x);
    ~CSample();
};

CSample::CSample()
{
    std::cout << "第一个构造函数被调用" << std::endl;
}

CSample::CSample(int x)
{
    std::cout << "第二个构造函数被调用" << std::endl;
}

CSample::~CSample()
{
}

int main(int argc, char const *argv[])
{
    CSample array1[2]; // 此时调用的是无参的构造函数
    std::cout << "step1" << std::endl;
    CSample array2[2] = {4, 5}; // 此时数组对象的所有元素调用的都是有参数的构造函数
    std::cout << "step2" << std::endl;
    CSample array3[2] = {4}; // 此时对象数组中只有第一个对象调用的是有参数的构造函数
    std::cout << "step3" << std::endl;
    CSample *array4 = new CSample[2]; // 调用无参的构造函数， 如果未初始化是不会生成对象的，就是说不会调用构造函数的。
    delete[] array4;
    return 0;
}
