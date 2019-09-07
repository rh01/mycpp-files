#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// unsigned int s[10000];
int i;

int cmp(const void *a, const void *b)
{
    unsigned int * ua, * ub;
    ua =(unsigned int *)a;
    ub =(unsigned int *)b;
    return (* ua % 10) - (* ub % 10);
}

#define NUM 5 

int main()
{

    // 输入数组的元素
    // scanf("%d", &n);
    unsigned int s[NUM] = {4, 21, 122, 233, 215};

    qsort(s, NUM, sizeof(unsigned int), cmp);
    for (i = 0; i < NUM; i++)
        printf("%d ", s[i]);
}