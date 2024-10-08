#include<stdio.h>
#define MAX(a, b) (a > b ? a: b)
#define MIN(a, b) (a > b ? b: a)

#define maxn 30000

char Fg[51][maxn];
int W[51][maxn];

int N, A[101], Ind[51], Sum;

void Dynamic() {
        int i, j, k, d, l, ind, lim = Sum/2;
        k = N/2;
        if(N%2 == 0) k--;
        for(i = 0; i<N; i++) {
                for(j = k; j>= 1; j--) {
                        for(l = 0; l<Ind[j]; l++) {
                                d = W[j][l] + A[i];
                                if(d > lim) continue;
                                if(Fg[j+1][d]) continue;
                                ind = Ind[j+1];
                                W[j+1][ind] = d;
                                Fg[j+1][d]  = 1;
                                Ind[j+1] ++;
                                if(j == k && d == lim) return;
                        }
                }
                if(Fg[1][A[i]] == 0 && A[i] <= lim) {
                        W[1][Ind[1]++] = A[i];
                        Fg[1][A[i]] = 1;
                }
        }
}

int Find() {
        int i, d, k, max = 0, res;
        k = N/2;
        for(i = 0; i<Ind[k]; i++) {
                d = W[k][i];
                if(d > max) {
                        res = W[k][i];
                        max = W[k][i];
                }
        }
        if(N%2) k++;
        for(i = 0; i<Ind[k]; i++) {
                d = W[k][i];
                if(d > max) {
                        res = W[k][i];
                        max = W[k][i];
                }
        }
        return res;
}

void Cal() {
        int d;
        if(N == 1) {
                printf("0 %d\n", A[0]);
                return;
        }
        else if(N == 2) {
        			printf("%d %d\n", MIN(A[0],A[1]), MAX(A[0],A[1]));
                
                return;
        }
        Dynamic();
        d = Find();
        printf("%d %d\n",d, Sum - d);
        
}


void Free() {
        int i, j, k = N/2, d;
        if(N%2)
                k++;
        for(i = 1; i<=k; i++) {
                for(j = 0; j<Ind[i]; j++) {
                        d = W[i][j];
                        Fg[i][d] = 0;
                }
                Ind[i] = 0;
        }
}


int main() {
        int k, i;
			scanf("%d",&k);
        
        while(k--) {
        	scanf("%d",&N);
                
                Sum = 0;
                for(i = 0; i<N; i++) {
                		scanf("%d",A + i);
                        
                        Sum += A[i];
                }
                Cal();
                if(k) puts("");
                Free();
        }
        return 0;
}