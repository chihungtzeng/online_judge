//  Q116: Unidirectional TSP
//  2008.03.02     Celia
//  Method: DP (reverse back-tracking)
#include <stdio.h>           //  Accepted

#define MAX 2147483647

int matrix[10][100],
next_p[10][100];

int main()
{
    int i, j, k, m, n, ptr, min_value, temp[3];

    while (scanf("%d%d", &m, &n) == 2)
    {
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &matrix[i][j]);

        for (j = n-2; j >= 0; j--)
        {
            for (i = 0; i < m; i++)
            {
                min_value = MAX;
                temp[0] = (i+m-1)%m, temp[1] = i, temp[2] = (i+1)%m;

                for (k = 0; k < 3; k++)
                {
                    if (min_value > matrix[temp[k]][j+1])
                        min_value = matrix[temp[k]][j+1], next_p[i][j] = temp[k];
                    else if (min_value == matrix[temp[k]][j+1])
                        next_p[i][j] = ((next_p[i][j] < temp[k])? next_p[i][j] : temp[k]);
                }

                matrix[i][j] += min_value;
            }
        }

        min_value = MAX;

        for (i = 0; i < m; i++)
            if (min_value > matrix[i][0])
                min_value = matrix[i][0], ptr = i;

        printf("%d", ptr+1);

        for (j = 0; j < n-1; j++)
        {
            printf(" %d", next_p[ptr][j]+1);
            ptr = next_p[ptr][j];
        }

        printf("\n%d\n", min_value);
    }

    return 0;
}
