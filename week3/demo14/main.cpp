#include "iostream"
using namespace std;

class CTest
{
private:
    int n;

public:
    CTest() { n = 1; }
    int GetValue() const { return n; } // 常引用的重载
    int GetValue() { return 2 * n; }
};

class Sample
{
public:
    int value;
    void GetValue() const;
    void func(){};
    Sample() {}
};
void Sample::GetValue() const
{
    // value = 0; // wrong
    // func(); //wrong
}

int main()
{
    /**
     * 两个成员函数，名字和参数表都一样，但是一个 是const,一个不是，算重载。
     */
    const CTest objTest1;
    CTest objTest2;
    cout << objTest1.GetValue() << "," << objTest2.GetValue() << endl;

    /**
     * 在类的成员函数说明后面可以加const关键字，则 该成员函数成为常量成员函数。
     * 常量成员函数执行期间不应修改其所作用的对象 。
     * 
     * 如果不希望某个对象的值被改变，则定义该对象的 时候可以在前面加const关键字。
     * 因此，在常量成员函数中不能修改成员变量的值 (静态成员变量除外)，也不能调用同类的非常量 成员函数(静态成员函数除外)。
     */
    const Sample o;
    // o.value = 100; //err.常量对象不可被修改
    // o.func();      //err.常量对象上面不能执行非常量成员函数
    o.GetValue();  //ok,常量对象上可以执行常量成员函数
    return 0;
}
