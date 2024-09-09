#include <stdio.h>
#include <stdlib.h>
#define LEN 100001
#define M 1000007

long long a[LEN];
int n, K, C;

int compareLL(const void *a, const void *b){
	return *(long long *)a - *(long long *)b;
}
#if 0
long long trivial(){
	int i, j;
	long long result = 0;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			result += llabs(a[i] - a[j]);
		}
	}
	return result;
}
#endif
long long solve(){
	int i, j;
	
	long long result = 0;
	for(i=1; i<n; i++){
		a[i] = (K*a[i-1] + C) % M; 
	}
	#if 0
	for(i=0; i<=n-2; i++){
		printf("%lld ", a[i]);
	}
	printf("\n");
	#endif
	qsort(a, n, sizeof(long long), compareLL);
	for(i=n-2; i >=0; i--){
		j=i+1;
		result += (a[j] - a[i])*j*(n-j);
	}
	return result;
}

int main(){
	int nTest, k=1;
	FILE *fp;
	fp = fopen("in2.txt", "r");
	fscanf(fp, "%d", &nTest);
	while(nTest > 0){
		nTest--;
		fscanf(fp, "%d %d %d %lld", &K, &C, &n, &a[0]);
		printf("Case %d: %lld\n", k++, solve());
		/*printf("trivial solution: %lld\n", trivial());*/
	}
	return 0;
}