#include "iostream"

//轮胎类
class CTyre
{
private:
    int radius; //半径
    int width;  //宽度
public:
    CTyre(int r, int w) : radius(r), width(w) {}
};

//引擎类
class CEngine
{
};

//汽车类 -> 封闭类
class CCar
{
private:
    int price; //价格
    CTyre tyre;
    CEngine engine;

public:
    CCar(int p, int tr, int tw);
};

// 封闭类构造函数的初始化
CCar::CCar(int p, int tr, int w) : price(p), tyre(tr, w){};

int main(int argc, char const *argv[])
{
    CCar car(20000, 17, 225);
    return 0;
}
