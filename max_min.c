#include <stdio.h>
int max, min;
int a[50];
void min_max(int i, int j)
{
    int max1, min1, mid;
    if (i == j)
    {
        max = min = a[i];
    }
    else if (i == j - 1)
    {
        if (a[i] < a[j])
        {
            max = a[j];
            min = a[i];
        }
        else
        {
            max = a[i];
            min = a[j];
        }
    }
    else
    {
        mid = (i + j) / 2;
        min_max(i, mid);
        max1 = max;
        min1 = min;
        min_max(mid + 1, j);
        if (max < max1)
            max = max1;
        if (min > min1)
            min = min1;
    }
}
int main()
{
    int i, n;
    printf("\nEnter the total number of numbers : ");
    scanf("%d", &n);
    printf("Enter the numbers :\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    max = a[0];
    min = a[0];
    min_max(1, n);
    printf("Minimum : %d\n", min);
    printf("Maximum : %d\n", max);
    return 0;
}