#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s1[2005], s2[2005];
int a[2005], b[2005], c[4005]; // 分别以数组形式存储a，b和结果c，|c|<=|a|+|b|
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int i, j, k;
        scanf("%s%s", s1, s2);
        for (i = 0; i < 4003; i++)
            c[i] = 0;
        int n = strlen(s1), m = strlen(s2);
        k = n + m; // 相乘后的位数不会大于k
        // 把字符串s1和s2逆序用数字排列
        for (i = 0; i < n; i++)
            a[i] = s1[n - i - 1] - '0';
        for (i = 0; i < m; i++)
            b[i] = s2[m - 1 - i] - '0';
        // 乘运算
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                c[i + j] += a[i] * b[j];
        for (i = 0; i <= k; i++)
        {
            if (c[i] >= 10)
            {
                c[i + 1] += c[i] / 10;
                c[i] %= 10;
            }
        }
        /*去除前导0*/
        i = k;
        while (c[i] == 0)
            i--;
        /*判断两个非负数之积是否为0，以及逆序打印c[]*/
        if (i < 0)
            printf("0");
        else
            for (; i >= 0; i--)
                printf("%d", c[i]);
        printf("\n");
    }
    return 0;
}