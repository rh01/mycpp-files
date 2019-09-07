#include "iostream"

class CCar; //提前声明 CCar类, 以便后面CDriver类使用
class CDriver
{
public:
    void ModifyCar(CCar *pCar); //改装汽车
};
class CCar
{
private:
    int price;

public:
    friend int MostExpensiveCar(CCar cars[], int total); //声明友元,我们可以声明一个外部函数是这个类的友元函数，以便可以访问该类的私有成员或成员函数
    friend void CDriver::ModifyCar(CCar *pCar);          //声明友元，这个声明一个外部类的成员函数为该类的右元函数
};

void CDriver::ModifyCar(CCar *pCar)
{
    pCar->price += 1000; // 汽车改装后的价格
}

int MostExpensiveCar(CCar cars[], int total)
{ // 求最贵的汽车的价格
    int tmpMax = -1;
    for (int i = 0; i < total; ++i)
        if (cars[i].price > tmpMax)
            tmpMax = cars[i].price;
    return tmpMax;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


// Note:
// 友元类之间的关系 不能传递, 不能继承