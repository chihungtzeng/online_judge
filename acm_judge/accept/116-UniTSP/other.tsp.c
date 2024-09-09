#include <stdlib.h>
#include <stdio.h>

#define MAX_M 10
#define MAX_N 100

int main() {
    int i, j, k, min, tmp;
    int m, n, t[MAX_M][MAX_N], p[MAX_M][MAX_N];
    int mod[2] = {-1, 1};

    while ( scanf("%d %d", &m, &n) == 2 ) {
        for (i=0; i<m; i++)
            for (j=0; j<n; j++)
                scanf("%d", &t[i][j]);

        for (j=(n-2); j>=0; j--) {
            for (i=0; i<m; i++) {
                min = i;
                for (k=0; k<2; k++) {
                    tmp = (i+mod[k]+m) % m;
                    if ( t[tmp][j+1] < t[min][j+1] )
                        min = tmp;
                    else if ( t[tmp][j+1] == t[min][j+1] )
                        if ( tmp < min )
                            min = tmp;
                }/*k*/
                p[i][j] = min;
                t[i][j] += t[min][j+1];
            }/*i: row*/
        }/*j: col*/

        k = 0;
        for (i=1; i<m; i++)
            if ( t[i][0] < t[k][0] )
                k = i;

        j = k;
        printf("%d", k+1);
        for (i=0; i<n-1; i++) {
            printf(" %d", p[j][i]+1);
            j = p[j][i];
        }
        printf("\n%d\n", t[k][0]);
    }/*while input data*/

    exit(0);
}
