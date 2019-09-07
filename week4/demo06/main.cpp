 #include <iostream> 
 #include <string> 
 #include <cstdlib>
 
using namespace std;

class Complex
{
private:
    double real, image;

public:
    Complex(/* args */);
    ~Complex();
    friend ostream &operator<<(ostream &o, const Complex &c);
    friend istream &operator>>(istream &o, Complex &c);
};

Complex::Complex(/* args */)
{
}

Complex::~Complex()
{
}

ostream &operator<<(ostream &o, const Complex &c)
{
    o << c.real << "+" << c.image << "i";
    return o;
};

istream &operator>>(istream &is, Complex &c)
{
    string s;
    is >> s; //将"a+bi"作为字符串读入, “a+bi” 中间不能有空格
    int pos = s.find("+", 0);
    string sTmp = s.substr(0, pos);                 //分离出代表实部的字符串
    c.real = atof(sTmp.c_str());                    //atof库函数能将const char*指针指向的内容转换成float
    sTmp = s.substr(pos + 1, s.length() - pos - 2); //分离出代表虚部的字符串 c.imag = atof(sTmp.c_str());
    return is;
};

int main()
{
    Complex c;
    int n;
    cin >> c >> n;
    cout << c << "," << n;
    return 0;
}
