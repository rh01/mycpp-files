#include "iostream"

class String
{
private:
    char *str;

public:
    String() : str(NULL){}; // 构造函数，初始化str为NULL 初始化成员列表
    const char *c_str() { return str; }
    String(String &s)
    {
        if (s.str)
        {
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        else
            str = NULL;
    };
    char *operator=(const char *s);
    // 深拷贝
    String &operator=(const String &s)
    {
        if (str == s.str)
            return *this;
        if (str)
            delete[] str;
        if (s.str)
        { //s.str不为NULL才会执行拷贝
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        else
            str = NULL;
        return *this;
    };
    ~String();
    
};

char *String::operator=(const char *s)
{
    if (str)
        delete[] str;
    if (s)
    {
        str = new char[strlen(s) + 1]; // +1 表示\0
        strcpy(str, s);
    }
    else
        str = NULL;
    return str;
};

String::~String()
{
    if (str)
        delete[] str;
}

int main(int argc, char const *argv[])
{
    String s;
    s = "Good Luck";
    std::cout << s.c_str() << std::endl;
    // String s2 = "hello!" // error，这时一个构造函数
    s = "Shenzhou 8!";
    std::cout << s.c_str() << std::endl;
    /**
     * S1 = S2
     * 浅复制/浅拷贝
     * 执行逐个字节的复制工作
     * 
     * 深复制/深拷贝
     * • 将一个对象中指针变量指向的内容,
     *  复制到另一个对象中指针成员对象指向的地方
     */

    return 0;
}
