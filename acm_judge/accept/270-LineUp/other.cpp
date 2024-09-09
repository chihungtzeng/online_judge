#include <iostream>
#include <cmath>
using namespace std;

#define MAXN 701
#define MAXLEN 100
#define INF 1e9
#define eps 1e-4

struct POINT
{
    int x, y;
}p[MAXN];

int N;
POINT base;

double s[MAXN];

bool cmp1(POINT a, POINT b)
{
    if(a.y==b.y) return a.x < b.x;
    return a.y < b.y;
}

double _slope(POINT a, POINT b)
{
    if(a.x==b.x) return INF;
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    return dy/dx;
}

int process()
{
    if(N<=2) return N;
    sort(p, p+N, cmp1);

    int i, j, n, maxn=0, k;
    for(i=0; i<N; i++)
    {
        /* set the base to be p[i] */
        base = p[i], n = 0;
        for(j=i+1; j<N; j++) s[n++] = _slope(p[j], p[i]);

        /* sort the slope */
        sort(s, s+n);

        for(j=1, k=1; j<n; j++)
        {
            if(fabs(s[j]-s[j-1])<=eps) k++;
            else k = 1;
            maxn = max(maxn, k);
        }
    }
    return maxn+1;
}

int main()
{
    freopen("c105", "r", stdin);

    int datacase;
    char in[MAXLEN];

    scanf("%d", &datacase);
    gets(in);
    gets(in);
    while(datacase--)
    {
        N = 0;
        while(gets(in))
        {
            if(in[0]==0) break;
            sscanf(in, "%d %d", &p[N].x, &p[N].y);
            N++;
        }

        /* start to process */
        printf("%d\n", process());
    }

    return 0;
}


