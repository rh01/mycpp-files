#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int s[10000], n;

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b; // 实现的是降序排列
}

int main()
{
    // 输入想要输入数据的个数
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    // 定一个比较函数，类型为函数指针类型
    int (*cmp_func)(const void *a, const void *b);
    cmp_func = cmp;

    qsort(s, n, sizeof(s[0]),  cmp);
    for (int i = 0; i < n; i++)
        printf("%d", s[i]);

    // qsort()

    return 0;
}
