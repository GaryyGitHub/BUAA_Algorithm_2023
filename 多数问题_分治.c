#include <stdio.h>
int a[100];
int cnt(int a[], int pivot, int left, int right)
{
    int num = 0;
    for (int i = left; i <= right; i++)
        if (a[i] == pivot)
            num++;
    return num;
}
int majority(int a[], int left, int right)
{
    int lpivot, rpivot, mid = (left + right) / 2;
    if (left == right)
        return a[left] < a[right] ? a[left] : a[right];
    else
    {
        lpivot = majority(a, left, mid);
        rpivot = majority(a, mid + 1, right);
    }
    if (lpivot == rpivot)
        return lpivot; // m1,m2为两分支出现次数较多的解，接下来求解哪个更多
    else
    {
        int ltimes = cnt(a, lpivot, left, right);
        int rtimes = cnt(a, rpivot, left, right);
        return ltimes > rtimes ? lpivot : rpivot;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d", majority(a, 0, n - 1));
    return 0;
}