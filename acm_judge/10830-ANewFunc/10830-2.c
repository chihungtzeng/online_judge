#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 1
#define LEN 45000
#define PRIME_NUM 4700
#define TYPE int

int *square;

long long solve(int n){
	long long result = 0;
	
	int nMultiple;
	int i;
	for(i=2; (i<LEN) && (square[i] <= n); i++){
		result += (n/i - 1) * i;
	}
	
	
	return result;
}

int main(){
	int n;
	int k=1;
	long long ans;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	square = (TYPE *) malloc(sizeof(TYPE)*LEN);
	for(n=0; n<LEN; n++){
		square[n] = n * n;
	}
	
	while(1 == fscanf(fp, "%d", &n)){
		if(n == 0) break;
		ans = solve(n);
		printf("Case %d: %lld\n", k++, ans);
	}
	free(square);	
	return 0;		
}