#include <math.h>
#include <stdio.h>

long double myround(long double x, int precision)
{
    return floor(x*pow(10.0,(long double)precision)+0.5)/pow(10.0,(long double)precision);
}

int main(void)
{
    int no, ii;
    long double total, above, below, right, student[1000];

    while (1)
    {
        scanf("%d\n", &no);
        if (!no)
            break;
        for (ii = 0, total = 0; ii < no; ii++)
        {
            scanf("%Lf\n", &student[ii]);
            total += student[ii];
        }
        right = myround((total / no), 2);
        above = below = 0;
        for (ii = 0; ii < no; ii++)
        {
            if (student[ii] < right)
                below += right - student[ii];
            if (student[ii] > right)
                above += student[ii] - right;
        }

        if (above == 0)
            above = below;

        if (below == 0)
            below = above;

        printf("$%.2Lf\n", myround(((below < above) ? below : above), 2));
    }
    return 0;
}