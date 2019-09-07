#include "iostream"

class Rectangle
{
private:
    int w;
    int h;

public:
    Rectangle();
    ~Rectangle();
    void Init(int w_, int h_)
    { // 内联成员函数1
        w = w_;
        h = h_;
    };
    inline int Area(); // 内联成员函数2
    int Perimeter()
    {
        return 2 * (w + h);
    }
};

Rectangle::Rectangle() {}

Rectangle::~Rectangle()
{
}

int Rectangle::Area()
{
    return w * h;
}

void PrintRectangle(Rectangle &r)
{
    std::cout << r.Area() << "," << r.Perimeter() << std::endl;
}

int main(int argc, char const *argv[])
{
    Rectangle r;
    int w, h;
    std::cin >> w >> h;
    r.Init(w, h);
    std::cout << r.Area() << std::endl
              << r.Perimeter() << std::endl;
    // 访问类的成员变量和成员函数有三种方法
    Rectangle r1, r2;
    r1.Init(3, 4); // 对象名.成员名

    Rectangle *p1 = &r1;
    Rectangle *p2 = &r2;
    p1->Init(3, 4); // 指针->成员名

    Rectangle &rr = r2;
    rr.Init(3, 4); // 引用名.成员名

    PrintRectangle(r2);
    return 0;
}
