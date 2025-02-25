#include <stdio.h>
long long catalan[100] = {1, 1, 2};
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 3; i <= n; i++)
    {
        for (j = 0; j < i; j++)
        {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
    printf("n  : P(n)\n");
    for (i = 0; i <= n; i++)
        printf("%-3d: %lld\n", i, catalan[i]);
    return 0;
}