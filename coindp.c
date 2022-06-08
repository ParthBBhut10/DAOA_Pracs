#include <stdio.h>
int d[100];
int j;
int n;
int c[100][100];
int m[50];
int main()
{
    printf("Enter the no of denominations :- ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the denomination :- ");
        scanf("%d", &d[i]);
    }
    printf("Enter the size of subproblem :- ");
    scanf("%d", &j);

    for (int x = 0; x <= j; x++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i == 0 || x == 0)
                c[i][x] = 0;
            else if (x < d[i])
                c[i][x] = c[i - 1][x];
            else if (i == x || i == 1)
                c[i][x] = 1 + c[1][x - d[i]];
            else
            {
                int a = c[i - 1][x];
                int b = 1 + c[i][x - d[i]];
                if (a < b)
                    c[i][x] = a;
                else
                    c[i][x] = b;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        printf("\n");
        for (int x = 0; x <= j; x++)
        {
            printf("%d  ", c[i][x]);
        }
    }
    printf(" ");
    printf("\nThe solution of no of coins to be selected : %d", c[n][j]);
    int e = 0;

    while (j != 0)
    {

        if (c[n][j] != c[n - 1][j])
        {
            m[e] = d[n];
            j = j - d[n];
            e++;
        }
        else
            n--;
    }

    printf("\nTherefore solution set is: ");
    for (int i = 0; i < e; i++)
    {
        printf("%d ", m[i]);
    }
    return 0;
}
