#include <stdio.h>
#include <algorithm>
#define N 1005
int a[N];
int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        
        std::sort(a, a + n);
        
        bool mk = 1;
        for(int i = n - 1; i && mk; i--)
        for(int j = 0; j < n && mk; j++)
        {
            if(j == i) continue;
            for(int k = 0; k < n && mk; k++)
            {
                if(k == j || k == i) continue;
                for(int l = 0; l < n && mk; l++)
                {
                    if(l == i || l == j || l == k) continue;
                    if(a[i] == a[j] + a[k] + a[l])
                    {
                        mk = 0;
                        printf("%d\n", a[i]);
                    }
                }
            }
        }
        if(mk) puts("no solution");
    }
    return 0; 
}