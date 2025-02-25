#include <stdio.h>
void QuickSort(int A[], int n)
{
    QSort(A, 0, n - 1);//首位、末位索引
}
void QSort(int A[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(A, low, high);
        QSort(A, low, pivot - 1);
        QSort(A, pivot + 1, high);
    }
}
int Partition(int A[], int low, int high)
{
    int pivot;
    pivot = A[low];
    // 从线性表的两端交替地向中间扫描
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}
int a[10000];
int main()
{
    int b[100] = {21, 43, 12, 100, 0, 49, 11, 5, 54, 94, 63, 78, 45};
    QuickSort(b, 13);
    for (int i = 0; i < 13; i++)
        printf("%d ", b[i]);
    return 0;
}