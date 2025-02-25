#include <stdio.h>
unsigned long long catalan[100000];
int main()
{
    catalan[0] = 1;
    for (long long i = 1; i < 40; i++)
    {
        catalan[i] = (catalan[i - 1] * (4 * i - 2)) / (i + 1);
    }
    for (int i = 0; i <= 34; i++)
        printf("%lld\n", catalan[i]);
    return 0; // 35的时候会爆！！！
}



// #include <stdio.h>
// unsigned long long catalan[1000];
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     catalan[0] = 1;
//     catalan[1] = 1;
//     for (long long i = 2; i <= 35; i++)
//     {
//         catalan[i] = (catalan[i - 1] * (4 * i - 2)) / (i + 1);
//     }

//     printf("n  : P(n)\n");
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 34)
//             printf("35 : 812944042149730764\n");
//         else
//             printf("%-3d: %lld\n", i + 1, catalan[i]);
//     }
//     return 0;
// }