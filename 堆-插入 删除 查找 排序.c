#include <stdio.h>
#include <stdlib.h>
int size;
int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
void recover(int *heap, int i)
{ // 将完全二叉数恢复为堆（最大堆）
    if (i * 2 + 1 <= size)
    {
        int max = heap[i * 2 + 1] > heap[i * 2] ? heap[i * 2 + 1] : heap[i * 2];
        if (max > heap[i])
        {
            if (max == heap[i * 2])
                swap(&heap[i], &heap[i * 2]);
            else if (max == heap[i * 2 + 1])
                swap(&heap[i], &heap[i * 2 + 1]);
        }
        recover(heap, i * 2);
        recover(heap, i * 2 + 1); // 递归，分别让左右孩子recover
    }
}
void insert(int *heap)
{
    int x;
    scanf("%d", &x);
    heap[++size] = x;
    int flag = size;
    for (int i = size / 2; i > 0; i /= 2)
    {
        if (heap[i] < heap[flag])
        {
            swap(&heap[i], &heap[flag]);
            flag = i;
        }
    }
}
void delete(int *heap)
{
    heap[1] = heap[size];
    heap[size--] = 0;
    /*printf("%d\n",heap[1]);*/
    recover(heap, 1);
}
void heapsort(int *heap)
{
    for (int i = size; i >= 1; i--)
    {
        swap(&heap[1], &heap[i]);
        recover(heap, i);
    }
}
int main()
{
    int t;
    int heap[100005] = {0};
    scanf("%d", &t);
    while (t--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            insert(heap);
        }
        else if (op == 2)
        {
            delete (heap);
        }
        else if (op == 3)
        {
            printf("%d\n", heap[1]);
        }
    }
    for (int i = 1; i <= size; i++)
        heap[i - 1] = heap[i];
    qsort(heap, size, sizeof(int), cmp);
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    // heapsort(heap);
    // for (int i = size; i >= 1; i--)
    //     printf("%d ", heap[i]);
    return 0;
}