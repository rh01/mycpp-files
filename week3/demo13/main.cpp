#include "iostream"

class A
{
    int i;
public:
    void Hello() { std::cout << "hello" << std::endl; }
};
int main()
{
    A *p = NULL;
    p->Hello(); //结果会怎样?
}

