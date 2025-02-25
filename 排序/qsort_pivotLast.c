#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
int Partition(int a[], int p, int r)
{
    int pivot = a[r]; // 将pivot设置为最后一个元素
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[j], &a[i]);
        }
    }
    swap(&a[++i], &a[r]);
    return i;
}
void QuickSort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = Partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}
int a[10000];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}