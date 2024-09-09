#include <stdio.h>
#include <math.h>
#define N 1000001

int a[N], f[N];

int main()
{
    int i, j, n, th, temp;
    a[1] = f[1] = 0, a[2] = f[2] = 1;
   
    for(i = 3; i < N; i++)
    {
        th = (int)sqrt(i), temp = 1;
       
        for(j = 2; j <= th; j++)
        {
            if(i % j == 0)
            {
                temp = j;
                break;
            }
        }
       
        if(temp == 1)
            a[i] = 1;
        else
            a[i] = a[temp] + a[i / temp];
       
        f[i] = f[i-1] + a[i];
    }
   
    while(scanf("%d", &n) == 1)
        printf("%d\n", f[n]);
   
    return 0;
}