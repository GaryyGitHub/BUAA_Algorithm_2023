#include <stdio.h>
#define INF 2147483647;
int a[100000];
void merge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1; // 左数组的元素个数
    int n2 = r - q;
    int i, j, k;
    int left[100000] = {0}, right[100000] = {0};
    for (i = 0; i < n1; i++)
    {
        left[i] = a[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = a[q + j + 1];
    }
    left[n1] = right[n2] = INF;
    i = j = 0;
    for (k = p; k <= r; k++)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
    }
}
void MergeSort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(a, p, q);
        MergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}