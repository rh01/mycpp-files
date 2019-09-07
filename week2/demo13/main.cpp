#include "iostream"

class Man
{
private:
    int nAge;        // 私有成员
    char szName[20]; // 私有成员
public:
    Man(/* args */);
    ~Man();
    void SetName(char * szName);
};

void Man::SetName(char *Name){
    strcpy(szName, Name);
}

Man::Man(/* args */)
{
}

Man::~Man()
{
}

int main(int argc, char const *argv[])
{
    // 类访问的可访问范围
    // private：只能在成员函数内部访问
    // public: 可以在任何地方被访问
    // protected: 受保护的成员

    // 缺省为私有成员

    return 0;
}
