#include <iostream>
using namespace std;

class CStudent
{
public:
    int nAge;
};

ostream & operator<<(ostream & o, const CStudent c) {
    o << c.nAge;
    return o;
}

// 刘插入与流提取运算符

int main()
{
    CStudent s;
    s.nAge = 5;
    cout << s << "hello";
    return 0;
}

