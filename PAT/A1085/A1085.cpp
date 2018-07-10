#include <iostream>
#include <algorithm>
int main()
{
    const int nmax = 100010;
    int n, p;
    scanf("%d%d", &n, &p);
    int K[nmax];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &K[i]);
    }

    std::sort(K, K + n); //升序排序

    int *f1 = K; //双指针
    int *f2 = K;
    int maxlength = 1; //最大长度至少为1（一个数）
    while (f1 < K + n) //当f1没有指向末尾时
    {
        static int count = 0; //统计数组长度的变量
        while (*f2 <= (long long)(*f1) * (long long)p && f2 < K + n)
        //f2满足条件，且没有指向末尾时，向数列中添加一个元素
        {
            f2++;
            count++; //长度+1
        }
        if (maxlength < count) //统计最大长度
        {
            maxlength = count;
        }
        f1++;    //f2不满足条件，则f1指向下一个元素
        count--; //f1右移故长度-1
    }

    printf("%d\n", maxlength);
    return 0;
}