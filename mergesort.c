#include <stdio.h>
#define MAX 20
int a[MAX];
int n, i;
void Merge(int, int);
void mergeSort(int, int, int);
void disp();
int main()
{
    printf("Enter no.of Elements:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter A[%d] ->", i);
        scanf("%d", &a[i]);
    }
    Merge(0, n - 1);
    return 0;
}
void Merge(int low, int high)
{
    int mid;
    if (low != high)
    {
        mid = (low + high) / 2;
        Merge(low, mid);
        Merge(mid + 1, high);
        mergeSort(low, mid, high);
    }
    disp();
    printf("\n");
}
void mergeSort(int low, int mid, int high)
{
    int temp[MAX];
    int i = low;
    int j = mid + 1;
    int k = low;
    while ((i <= mid) && (j <= high))
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];
    for (i = low; i <= high; i++)
        a[i] = temp[i];
}
void disp()
{
    for (int i = 0; i < n; i++)
        printf("  %d", a[i]);
}