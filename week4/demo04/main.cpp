#include "iostream"
using namespace std;

class CArray
{
private:
    int size; // 数组元素的个数
    int *ptr; // 指向动态分配的数组
public:
    CArray(int s=0);
    CArray(CArray &a); // 拷贝构造函数
    ~CArray();
    void push_back(const int v);
    int length() { return size; }
    CArray operator=(const CArray &a); // 重载运算符=,用于对象之间的赋值，深拷贝
    int &operator[](int i)
    { //用以支持根据下标访问数组元素，
        // 如n = a[i] 和a[i] = 4; 这样的语句
        return ptr[i];
    }; // 重载运算符[],支持下标访问数组元素
};

CArray::CArray(int s) : size(s)
{
    if (s == 0)
        ptr = NULL;
    else
        ptr = new int[s];
}

CArray::CArray(CArray &a)
{
    if (!a.ptr)
    { // 如果传入的为空
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
};

CArray CArray::operator=(const CArray &a)
{
    //赋值号的作用是使“=”左边对象里存放的数组，大小和内容都和右边的对象一样
    if (ptr == a.ptr) //防止a=a这样的赋值导致出错
        return *this;
    if (a.ptr == NULL)
    { //如果a里面的数组是空的
        if (ptr)
            delete[] ptr;
        ptr = NULL;
        size = 0;
        return *this;
    };
    if (size < a.size)
    { //如果原有空间够大，就不用分配新的空间
        if (ptr)
            delete[] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return *this;
}; // CArray & CArray::operator=( const CArray & a)

void CArray::push_back(const int v)
{
    //在数组尾部添加一个元素
    if (ptr)
    {
        int *tmpPtr = new int[size + 1]; //重新分配空间 memcpy(tmpPtr,ptr,sizeof(int)*size); //拷贝原数组内容 delete [] ptr;
        ptr = tmpPtr;
    }
    else //数组本来是空的
        ptr = new int[1];
    ptr[size++] = v; //加入新的数组元素
};

CArray::~CArray()
{
    if (ptr)
        delete[] ptr;
}

int main()
{

    CArray a; //开始里的数组是空的
    for (int i = 0; i < 5; ++i)
        a.push_back(i);
    CArray a2, a3;
    a2 = a;
    for (int i = 0; i < a.length(); ++i)
        cout << a2[i] << " ";
    a2 = a3; //a2是空的

    for (int i = 0; i < a2.length(); ++i) //a2.length()返回0
        cout << a2[i] << " ";
    cout << endl;
    a[3] = 100;
    CArray a4(a);
    for (int i = 0; i < a4.length(); ++i)
        cout << a4[i] << " ";
    return 0;
}
