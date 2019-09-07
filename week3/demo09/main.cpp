#include "iostream"

class CRectangle
{
private:
    int w, h;
    static int nTotalArea;
    static int nTotalNumber;

public:
    CRectangle(int w_, int h_);
    CRectangle(CRectangle &r);
    ~CRectangle();
    static void PrintTotal();
};

CRectangle::CRectangle(int w_, int h_)
{
    w = w_;
    h = h_;
    nTotalNumber++;
    nTotalArea += w * h;
}
CRectangle::~CRectangle()
{
    nTotalNumber--;
    nTotalArea -= w * h;
}
void CRectangle::PrintTotal()
{
    std::cout << nTotalNumber << "," << nTotalArea << std::endl;
}

CRectangle ::CRectangle(CRectangle &r)
{
    w = r.w;
    h = r.h;
    nTotalNumber++;
    nTotalArea += w * h;
}

// 必须在定义类的文件中对静态成员变量进行一次说明
// 或初始化。否则编译能通过，链接不能通过。
int CRectangle::nTotalNumber = 0;
int CRectangle::nTotalArea = 0;

int main(int argc, char const *argv[])
{
    /**
     * 普通成员变量每个对象有各自的一份，而静态成员变 量一共就一份，为所有对象共享。
     * sizeof 运算符不会计算静态成员变量。
     * 普通成员函数必须具体作用于某个对象，而静态成员 函数并不具体作用与某个对象。因此静态成员不需要通过对象就能访问。
     * 
     * ***********************************
     * 如何访问静态成员
     * 1) 类名::成员名
     * CRectangle::PrintTotal();
     * 2) 对象名.成员名
     * CRectangle r; r.PrintTotal(); 
     * 3) 指针->成员名
     * CRectangle * p = &r; p->PrintTotal(); 
     * 4) 引用.成员名
     * CRectangle & ref = r; int n = ref.nTotalNumber;
     * 
     *  静态成员变量本质上是全局变量，哪怕一个对象都不存在，类 的静态成员变量也存在。
     *  静态成员函数本质上是全局函数。
     *  设置静态成员这种机制的目的是将和某些类紧密相关的全局变量和函数写到类里面，看上去像一个整体，易于维护和理解。
     * 
     */

    CRectangle c1(3, 4);
    // std::cout << CRectangle::nTotalNumber÷ << std::endl; // Wrong, 私有
    c1.PrintTotal();
    /**
     * 在静态成员函数中，不能访问非静态成员变量， 也不能调用非静态成员函数。
     * 因为解释不通所调用的费静态成员函数属于哪一个对象的。
     * 
     * 在使用CRectangle类时，有时会调用复制构造函数 生成临时的隐藏的CRectangle对象
     * 调用一个以CRectangle类对象作为参数的函数时， 调用一个以CRectangle类对象作为返回值的函数时
     * 临时对象在消亡时会调用析构函数，减少nTotalNumber 和 nTotalArea的值，可是这些临时对象在生成时却没有增加 nTotalNumber 和 nTotalArea的值。
     */
    return 0;
}
