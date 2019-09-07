#include "iostream"

int main(int argc, char const *argv[])
{
    // 常量指针
    // 表示不能通过常量指针修改其指向的内容
    int n, m;
    const int *p = &n;

    // Error
    // *p = 5;

    n = 4;  // ok
    p = &m; // 这是可以，可以允许常量指针的指向发生变化

    // 需要注意的是，不可以将常量指针赋值给非常量指针。可以强制类型转换
    // 但是反过来就可以。
    // Error
    const int *p1;
    int *p2;
    p1 = p2; // 允许
    // p2 = p1; // 不允许
    p2 = (int *)p1; // 可以的，因为可以通过强制类型转换


    return 0;
}


// 函数参数为常量指针是，可以避免函数内部不小心改变参数指针所指向的内容
void MyPrintf(const char * p){
    // strcpy(p, "this"); // 编译出错
    printf("%s", p);
}