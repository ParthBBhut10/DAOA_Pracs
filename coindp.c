#include <stdio.h>
int main()
{
    int n, i, j;
    int m;
    printf("Enter size of subproblem  : ");
    scanf("%d", &m);

    printf("Enter no. of denominator : ");
    scanf("%d", &n);
    int d[n];
    d[0] = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter denominator %d : ", i + 1);
        scanf("%d", &d[i + 1]);
    }

    int c[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // c[i][j]=ans(c[][],d[],i,j);

            if (i == 0)
            {
                c[i][j] = 0;
            }
            else if (j == 0)
            {
                c[i][j] = 0;
            }
            else if (i == 1)
            {
                c[i][j] = 1 + c[1][j - d[i]];
                // printf("anywhere");
            }

            else if (j < d[i])
            {
                c[i][j] = c[i - 1][j];
                // printf("hello");
            }

            else
            {
                if (c[i - 1][j] < (1 + c[i][j - d[i]]))
                {
                    c[i][j] = c[i - 1][j];
                }
                else
                {

                    c[i][j] = 1 + c[i][j - d[i]];
                }
            }
        }
    }
    j = m;
    printf("solution is :");
    i = n;
    while (j != 0)
    {
        if (c[i][j] != c[i - 1][m])
        {
            printf("%d ", d[i]);
            j = j - d[i];
        }
        else
        {
            i--;
        }
    }
    return 0;
}